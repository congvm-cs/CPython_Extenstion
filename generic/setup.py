from distutils.core import setup, Extension

MODULE_NAME = "ModuleName"
VERSION = '1.0'
AUTHOR = "author"
module1 = Extension(MODULE_NAME, 
              #       include_dirs=['./include/'],
                    sources = [f'{MODULE_NAME}_wrapper.c'])

all_modules = [module1]

setup (name = MODULE_NAME,
       version = VERSION,
       author=AUTHOR,
       description = 'This is a demo package',
       ext_modules = all_modules)
