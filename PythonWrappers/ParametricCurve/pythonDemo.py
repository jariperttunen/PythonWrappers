#!/usr/bin/env python
from shutil import *
# To copy the .so file to the present directory. This is done to run this file from wherever required.
# So the copy command works like #the first parameter is the source from where the .so file needs to be obtained and then the destination
#path where it needs to be copied.
copy("build/lib.macosx-10.9-x86_64-2.7/ParametricCurveWrapper.so",".")

from  ParametricCurveWrapper import *

d = cxxadt.ParametricCurve("function.txt")       # Call the ParametricCurve with the text file
print " Number at 0 = ",d(0)                     # demos the extrapolation and interpolation of the x and y coordinates.      
print " Number at 1 = ",d(1)
print " Number at 2 = ",d(2)
print " Number at 3 = ",d(3)
print " Number at 4 = ",d(4)
print " Number at 4.5 = ",d(4.5)
print " Number at 5.3 = ",d(5.3)
print " Number at 6.1 = ",d(6.1)
print " Number at 8.1 = ",d(8.1)
print " Number at 9.1 = ",d(9.1)
print " Number at 10.1 = ",d(10.1)
print " Number at 11.1 = ",d(11.1)
print " Number at 11.99 = ",d(11.99)
