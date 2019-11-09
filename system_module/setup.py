from distutils.core import setup, Extension

module1 = Extension('system_module', 
                    include_dirs=['./include/'],
                    sources = ['system_module_wrapper.c'])

all_modules = [module1]
setup (name = 'SystemModule',
       version = '1.0',
       author="CongVM",
       author_email="congvm.it@gmail.com",
       description = 'This is a demo package',
       ext_modules = all_modules)
