#!/usr/bin/env python
from shutil import *
# To copy the .so file to the present directory. This is done to run this file from wherever required. So the copy command works like #the first parameter is the source from where the .so file needs to be obtained and then the destination path where it needs to be #copied.
copy("/home/likewise-open/IN/gopalkri/Developer/core-model/PythonWrappers/LGMHistogram/build/lib.linux-x86_64-2.7/LGMHistogramWrapper.so","/home/likewise-open/IN/gopalkri/Developer/core-model/PythonWrappers/LGMHistogram")


from LGMHistogramWrapper import *
d = cxxadt.LGMHistogram(100,0,1) #Make a histogram with 100as the limit, 0 as the frequencies and 1 as the delta value
v = d.getHistogram()      # This gets the histogram data
print "The first histogram value= ",  v[0]
print "The second histogram value= ", v[1]
print "The third histogram value= ",  v[2]
print "The fourth histogram value= ", v[3]
print "The fifth histogram value= ",  v[4]

e=d.classify(0.9)# inserts the value to the histogram
print "Using Classify for 0.9 = ", e
e=d.classify(1.0)
print "Using Classify for 1.0 = ", e
e=d.classify(0.3)
print "Using Classify for 0.3 = ", e
