/* Notes 

- PyObject: 
    Object Structure used to define object types for Python
    A pointer is treated to be an object.

- PyArgs_ParseTuple:
    Parses the arguments received from Python programs into local variables

- References:
    - https://docs.python.org/3/c-api/arg.html
    - https://realpython.com/build-python-c-extension-module/
*/

#include <Python.h>
#include "system_call.cpp"

static PyObject *invoke_command(PyObject *self, PyObject *args){
    char *command;
    int sts;
    if (!PyArg_ParseTuple(args, // PyObjects
                          "s",  // format specifies the type of data
                          &command // pointers to local variables assigned
                          ))

        // If args is invalid, return NULL
        // Maybe catch the exception here to debug
        return NULL;

    // Our C/C++ implementation
    sts = _invoke_command(command);
    return Py_BuildValue("i",  // Convert C into Python Int
                         sts); // C/C++ results
}

// A Tree View of Module:
// spamify_module
// - spamify
// ...
// - ...
static PyMethodDef SystemMethods[] = {
    {
        "invoke_command", // method name
        invoke_command,  // PyObject method
        METH_VARARGS, // PyArg_ParseTuple for arguments
        "Execute the given command" // Description
    },
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef system_module_def = 
{
    PyModuleDef_HEAD_INIT,
    "system_module", // name of Python C extension modules
    "Module that is still in development",
    -1, // amount of mem needed to store program. negative means no need mem
    SystemMethods // the reference to the method table. this is an array of PyMethodDef structs
};

// Caution: PyInit_spamify_module :  PyInit_<implemented module name>
PyMODINIT_FUNC PyInit_system_module(void){
    return PyModule_Create(&system_module_def);
}