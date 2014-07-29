#!/usr/bin/env python
 
from distutils.core import setup
from distutils.extension import Extension

#This  is the  setup.py for   Firmament.  The  setup  assumes that  in
#the   core-model   directory,   there  exists    e.g.   PythonWrapper
#directory where this  setup.py  and FirmamentWrapper.cc are  located.
#Then   the   command    "python    setup.py     build"   can     find
#Firmament.cc, necessary  header  files  and  the cxxadt  library  and
#then   create Firmament.so  shared library  that can  be imported  to
#python.  The  library  boost_python-mt  is   for Mac,  it   may  need
#renaming      on     other       systems.    However, the     command
#"locate boost_python" should reveal the right name.
setup(name="LGMHistogramWrapper",version="1.0",
    ext_modules=[
        Extension("LGMHistogramWrapper", ["LGMHistogramWrapper.cc","../../c++adt/src/LGMHistogram.cc"],
        libraries = ["boost_python-mt-py27",'cxxadt'],
        library_dirs = ['/opt/local/lib','../../c++adt/lib'],
        include_dirs = ['/opt/local/include','../../c++adt/include','../../c++adt/include',
                        '../../stl-lignum/include'])
    ])
