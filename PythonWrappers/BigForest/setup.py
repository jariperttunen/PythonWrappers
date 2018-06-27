from distutils.core import setup
from distutils.extension import Extension
setup(name="Box",version="1.0",
          ext_modules=[
              Extension("Box",["BigForestWrapper.cc"],
                        libraries=['boost_python3-mt','cxxadt','bigbox'],
                        library_dirs=['/opt/local/lib/','../../c++adt/lib/','../../BigForest/'],
                        include_dirs=['/opt/local/include/','../../c++adt/include/','../../BigForest/include/'])
          ])
