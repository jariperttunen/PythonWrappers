#!/usr/bin/env python
from shutil import *
# To copy the .so file to the present directory. This is done to run this file from wherever required. So the copy command works like #the first parameter is the source from where the .so file needs to be obtained and then the destination path where it needs to be #copied.
#copy("FirmamentWithMask/build/*/FirmamentWithMask.so",".")
from FirmamentWithMask import *
print("Configuring firmament with 20 azimuths, 10 inclinations, 1 zenith and 1200 MJ total radiant intensity")
d = sky.FirmamentWithMask(10,20,1200)   # calling the FirmamentWithMask constructor.
VarAzi = d.getNoOfAzimuths()           # Gets the no of Azimuths
print("Result for getNoOfAzimuths = ", VarAzi)  # Prints the results of getNoOfAzimuths.
VarInc =d.getNoOfInclinations()        # Gets the no of inclinations.
print("Result for getNoOfInclinations = ", VarInc)  # Prints the results of getNoOfInclinations.
varNoOfregion = d.numberOfRegions()   # Description & gets the number of sector.
print("Result for numberOfRegions()", varNoOfregion)

VarDiffPlane =  d.diffusePlaneSensor()   # Description Intensity of diffuse radiation on a horizontal plane
print("Result for diffusePlaneSensor =", VarDiffPlane)   # Prints the diffusePlaneSensor Value.
VarBallSenSor =d.diffuseBallSensor()   # Description &Intensity of diffuse radiation as recorded by a ball sensor.
print("Result for diffuseBallSensor =" , VarBallSenSor) # Print on the screen the result of diffuseBallSensor.

print("Resizing the firmament to 20 azimuths, 18 inclinations, 1 zenith and with 1200 MJ total radiant intensity")
d.resize(20,18,1200)                    # resizing the FirmamentWithMask Object.
VarAzi = d.getNoOfAzimuths()           # Gets the no of Azimuths
print("Result for getNoOfAzimuths = ", VarAzi)  # Prints the results of getNoOfAzimuths.
VarInc =d.getNoOfInclinations()        # Gets the no of inclinations.
print("Result for getNoOfInclinations = ", VarInc)  # Prints the results of getNoOfInclinations.
varNoOfregion = d.numberOfRegions()   # Description & gets the number of sector.
print("Result for numberOfRegions()", varNoOfregion)
VarDiffPlane =  d.diffusePlaneSensor()   # Description Intensity of diffuse radiation on a horizontal plane
print("Result for diffusePlaneSensor =", VarDiffPlane)   # Prints the diffusePlaneSensor Value.
VarBallSenSor =d.diffuseBallSensor()   # Description &Intensity of diffuse radiation as recorded by a ball sensor.
print("Result for diffuseBallSensor =" , VarBallSenSor) # Print on the screen the result of diffuseBallSensor.

print("Configuring the firmament from the file Firmament.txt with a gap model")
d.readAllMasks("Firmament.txt")       # reading the txt file using readAllMasks.
VarAzi = d.getNoOfAzimuths()           # Gets the no of Azimuths
print("Result for getNoOfAzimuths = ", VarAzi)  # Prints the results of getNoOfAzimuths.
VarInc =d.getNoOfInclinations()        # Gets the no of inclinations.
print("Result for getNoOfInclinations = ", VarInc)  # Prints the results of getNoOfInclinations.
varNoOfregion = d.numberOfRegions()   # Description & gets the number of sector.
print("Result for numberOfRegions()", varNoOfregion)
print("Radiant intensity without gap model")
VarDiffPlane =  d.diffusePlaneSensor()   # Description Intensity of diffuse radiation on a horizontal plane
print("Result for diffusePlaneSensor =", VarDiffPlane)  # Prints the diffusePlaneSensor Value.
VarBallSenSor =d.diffuseBallSensor()   # Description &Intensity of diffuse radiation as recorded by a ball sensor.
print("Result for diffuseBallSensor =" , VarBallSenSor) # Print on the screen the result of diffuseBallSensor.

print("Installing the gap model")
d.configure(0,False)                  # reading the configuration file.
print("Radiant intensity (MJ) with gap model")
VarDiffPlane =  d.diffusePlaneSensor()   # Description Intensity of diffuse radiation on a horizontal plane
print("Result for diffusePlaneSensor =", VarDiffPlane)  # Prints the diffusePlaneSensor Value.
VarBallSenSor =d.diffuseBallSensor()   # Description &Intensity of diffuse radiation as recorded by a ball sensor.
print("Result for diffuseBallSensor =" , VarBallSenSor) # Print on the screen the result of diffuseBallSensor.
print("The difference with the Firmament without gap model is")
varB=d.getBallChange()                # Description & Change to diffuseRadBall caused by SetMask.
print("Result for getBallChange = ",  varB*100.0,'%')  # Write the result on to the screen.
varP= d.getPlaneChange()              # Description & Change to diffuseRadPlane  caused by SetMask.
print("Result for getPlaneChange =", varP*100.0,'%')  # Print to the screen the result for getPlanChange.
v=VectorDouble()                      # Generate an object of the class of VectorDouble()
v.extend([1,1,1])                     # Insert the empty list v with 3 values "1" So that
                                      # it initialise for the direction x,y and z
VarDiff=d.diffuseRegionRadiationSum(0,v) #Description & Get intensity of diffuse radiation
                                         #(on plane perpendicular to direction vector) from sector no n
                                         #(numbering starts from horizon) and direction of the sector.
                                         #I have hardcoded the first parameter in this function it can be a for loop. 
print("The radiant intensity from direction", "x=",v[0],"y=",v[1],"z=",v[2],"is",VarDiff, 'MJ')
print("Reading azimuth inclination mask")
d.readAzimuthInclinationMaskFile("gap.txt")
print("Regions",d.numberOfRegions())
for i in range(0,d.numberOfRegions()):
   v=VectorDouble()
   v.extend([1,1,1])
   rad = d.diffuseRegionRadiationSum(i,v)
   print(i,v[0],v[1],v[2],rad)



