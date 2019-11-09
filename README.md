# CPython Extenstion

Author: CongVM

## Introduction

Some methods are required high performance in speed which haven't improved by any available algorithms, they need to be coded by lower languages such as C/C++, etc.... To leverage those languages, We need to use a Python wrapper. 

Higher performance but require C-C++ knowledge. Maybe it is worth a try for your cases.

## Installation
```
Python>=3.0
gcc or g++
```

## Compilation

The explainations are noted down in `*.c` or `*.cpp`

`python setup build_ext --inplace`

We will have a file *.so.

## Testing

`python test.py`


## References

1. https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2019

2. https://realpython.com/build-python-c-extension-module/