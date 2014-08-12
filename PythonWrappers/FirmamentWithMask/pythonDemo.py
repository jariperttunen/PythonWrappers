#!/usr/bin/env python
from shutil import *
# To copy the .so file to the present directory. This is done to run this file from wherever required. So the copy command works like #the first parameter is the source from where the .so file needs to be obtained and then the destination path where it needs to be #copied.
copy("/home/likewise-open/IN/gopalkri/Developer/core-model/PythonWrappers/FirmamentWithMask/build/lib.linux-x86_64-2.7/FirmamentWithMask.so","/home/likewise-open/IN/gopalkri/Developer/core-model/PythonWrappers/FirmamentWithMask")
from FirmamentWithMask import *
d = sky.FirmamentWithMask(10,20,20)   # calling the FirmamentWithMask constructor.
d.resize(20,18,15)                    # resizing the FirmamentWithMask Object.
d.readAllMasks("Firmament.txt")       # reading the txt file using readAllMasks.
d.configure(0,False)                  # reading the configuration file.
varB=d.getBallChange()                # Description & Change to diffuseRadBall caused by SetMask.
print "Result for getBallChange = ",  varB  # Write the result on to the screen.
varP= d.getPlaneChange()              # Description & Change to diffuseRadPlane  caused by SetMask.
print "Result for getPlaneChange =", varP  # Print to the screen the result for getPlanChange.
varNoOfregion = d.numberOfRegions()   # Description & gets the number of sector.
print "Result for numberOfRegions =", varNoOfregion
v=VectorDouble()                      # Generate an obkect of the class of VectorDouble()
v.extend([1,1,1])                     # Insert the empty list v with 3 values "1" So that it initialise for the direction x,y and z
VarDiff=d.diffuseRegionRadiationSum(0,v) #Description & Get intensity of diffuse radiation (on plane perpendicular to direction vector) from sector no n (numbering starts from horizon) and direction of the sector. I have hardcoded the first parameter in this function it can be a for loop. 
print "Result for diffuseRegionRadiationSum =", VarDiff  # This prints the variable VarDiff to the screen.
VarDiffPlane =  d.diffusePlaneSensor()   # Description Intensity of diffuse radiation on a horizontal plane
print "Result for diffusePlaneSensor =", VarDiffPlane   # Prints the diffusePlaneSensor Value.
VarBallSenSor =d.diffuseBallSensor()   # Description &Intensity of diffuse radiation as recorded by a ball sensor.
print "Result for diffuseBallSensor =" , VarBallSenSor # Print on the screen the result of diffuseBallSensor.
VarAzi = d.getNoOfAzimuths()           # Gets the no of Azimuths
print "Result for getNoOfAzimuths = ", VarAzi  # Prints the results of getNoOfAzimuths.
VarInc =d.getNoOfInclinations()        # Gets the no of inclinations.
print "Result for getNoOfInclinations = ", VarInc  # Prints the results of getNoOfInclinations.






