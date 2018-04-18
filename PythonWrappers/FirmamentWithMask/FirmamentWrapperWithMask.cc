/* Written: K.V.Gopalkrishnan
  Date :  1st week of july 2014
  Usage in Python: Import FirmamentWithMask
  To make an object
  d = d = FirmamentWithMask.sky.FirmamentWithMask()
  now access the functions and operators.
*/


#include <iostream>
#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/scope.hpp>
#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/iterator.hpp>
#include <boost/python/overloads.hpp>
#include <boost/python/args.hpp>
//#include<boost/python/class_fwd.hpp>
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>


//Firmament is the c++ header file for Firmament class
#include <Firmament.h>
#include <FirmamentWithMask.h>
#include <list>
#include <string>
#include <Lex.h>

using namespace std;
using namespace boost::python;
using namespace cxxadt;
using namespace sky;

class SkyNamespaceDummy{}; //Dummy class to make C++ compiler happy and to define the wrapper for the namespace.


BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(configureWithOne, FirmamentWithMask::configure, 1, 1);
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(configureWithThree, FirmamentWithMask::configure,1, 2);

BOOST_PYTHON_MODULE(FirmamentWithMask)
{ class_<Firmament>("Firmament",init<optional<int,int,int> >())
            //Wrappers for the methods that are defined.
            .def("resize",&Firmament::resize)
            .def("setDiffuseRadiation",&Firmament::setDiffuseRadiation)
            .def("setDirectRadiation",&Firmament::setDirectRadiation)
            .def("outDiff", &Firmament::outDiff)
            .def("outAz",&Firmament::outAz) // this needs to be 3D variable
            .def("getInclinationIndex",&Firmament::getInclinationIndex)
            .def("getNoOfAzimuths", &Firmament::getNoOfAzimuths)
            .def("getNoOfInclinations",&Firmament::getNoOfInclinations)
            .def("outInclinations", &Firmament::outInclinations)
            .def("numberOfRegions", &Firmament::numberOfRegions)
            .def("getInclination",&Firmament::getInclination)
            .def("getAzimuth",&Firmament::getAzimuth)
            .def("directRadiation", &Firmament::directRadiation)
            .def("diffuseRadiationSum", &Firmament::diffuseRadiationSum)
            .def("diffuseRegionRadiationSum",&Firmament::diffuseRegionRadiationSum)
            .def("diffuseHalfRegionRadiationSum",&Firmament::diffuseHalfRegionRadiationSum)
            .def("directHalfRegionRadiationSum", &Firmament::directHalfRegionRadiationSum)
            .def("diffusePlaneSensor", &Firmament::diffusePlaneSensor)
            .def("diffuseBallSensor", &Firmament::diffuseBallSensor)
            .def("diffuseForestRegionRadiationSum",&Firmament::diffuseForestRegionRadiationSum)
            .def("outInclinations",&Firmament::outInclinations)
            .def("getSunPosition",&Firmament:: getSunPosition)
            .def("getIncAz",&Firmament::getIncAz)
            .def("getSectorArea", &Firmament::getSectorArea)
            .def("getAzimDivision", &Firmament::getAzimDivision)
            .def("getInclinationIndex",&Firmament::getInclinationIndex)
            .def("getAzimuthIndex",&Firmament::getAzimuthIndex)
            .def("getDirection",&Firmament::getDirection)
            .def("getDir_x",&Firmament::getDir_x)
            .def("getDir_y",&Firmament::getDir_y)
            .def("getDir_z",&Firmament::getDir_z)
            .def("getThetZ",&Firmament::getThetZ)
            .def("getStandDensity",&Firmament::getStandDensity)
            .def("getHalfDeltaIncl",&Firmament::getHalfDeltaIncl)
            .def("getdeltaIncl",&Firmament::getdeltaIncl)
            .def("getDiffuseRadScale",&Firmament::getDiffuseRadScale)
            .def("getDiffuseRadZenith",&Firmament::getDiffuseRadZenith)
            //****************************************************************************************************************************************************************
            //   The data members in Firmament like num_of_incl are protected but
            //    we can define matching property in python wrapped that can acces
            //     the data member (using getNofInclinations member function).
            //      Definition or wrapopers for the protected properties are given here
            //****************************************************************************************************************************************************************

            .add_property("num_of_incl",&Firmament::getNoOfInclinations)
            .add_property("num_of_azim",&Firmament::getNoOfAzimuths)
            .add_property("numOfSectors",&Firmament::numberOfRegions)
            .add_property("diffuseRadPlane",&Firmament::diffusePlaneSensor)
            .add_property("directRadPlane",&Firmament::setDirectRadiation)
            .add_property("diffuseRadBall",&Firmament::diffuseBallSensor)
            .add_property("diffuseRadBall",&Firmament::diffuseBallSensor)
            .add_property("sunPosition",&Firmament:: getSunPosition)
            .add_property("inclinations",&Firmament:: outInclinations)
            .add_property("areasByInclination",&Firmament:: getSectorArea)
            .add_property("azimDivisions",&Firmament::getAzimDivision)
            .add_property("inclinationIndex",&Firmament::getInclinationIndex)
            .add_property("azimuthIndex",&Firmament::getAzimuthIndex)
            .add_property("dir_x",&Firmament::getDir_x)
            .add_property("dir_y",&Firmament::getDir_y)
            .add_property("dir_z",&Firmament::getDir_z)
            .add_property("zoneAzims",&Firmament::outAz)
            .add_property("diffuseRad",&Firmament::outDiff)
            .add_property("thetZ",&Firmament::getThetZ)
            .add_property("standDensity",&Firmament::getStandDensity)
            .add_property("deltaIncl",&Firmament::getdeltaIncl)
            .add_property("halfDeltaIncl",&Firmament::getHalfDeltaIncl)
            .add_property("diffuseRadScale",&Firmament::getDiffuseRadScale)
            .add_property("diffuseRadZenith",&Firmament:: getDiffuseRadZenith);
    //****************************************************************************************************************************************************************

    //All the class definition that are required for the wrapper to work. Wrappers for vectors,PositionVectors and 3D Matrix are defined here.
    //****************************************************************************************************************************************************************

    class_<std::vector<double> >("VectorDouble")   // Wrapper for a doubel vector
            .def(vector_indexing_suite<std::vector<double> >());

    class_<std::vector<std::pair<double, double> > >("VectorOfPairs") // Wrapper for pairs of vector
            .def(vector_indexing_suite<std::vector<std::pair<double,double> > >());

    class_<std::pair<double, double> >("DoublePair") // Wrapper for a pair only
            .def_readwrite("first", &std::pair<double, double>::first)
            .def_readwrite("second", &std::pair<double, double>::second);

    class_<std::vector<int> >("VectorInt")   // Wrapper for a Integer vector
            .def(vector_indexing_suite<std::vector<int> >());
    class_<PositionVector> ("PositionVector",init<const double,const double,const double >()); //Wrapper for the PositionVector

    class_<TMatrix<double> > ("TMatrix"); //Wrapper for the 3D matrix.

    scope sky = class_<SkyNamespaceDummy>("sky"); //wrapping the namespace sky using the dummy variable
    class_<sky::FindNextMask>("FindNextMask",init<int>()); // Wrapping the real namespace sky
    class_<Lex,boost::noncopyable>("Lex"); // Wrapping the class Lex with copy constructors

    class_<std::vector<std::pair<int, string> > >("VectorOfPairs") // Wrapper for pairs of vector
            .def(vector_indexing_suite<std::vector<std::pair<int,string> > >());

    class_<std::pair<int, string> >("DoublePair") // Wrapper for a pair only
            .def_readwrite("first", &std::pair<int, string>::first)
            .def_readwrite("second", &std::pair<int, string>::second);

   // class_<Firmament>("Firmament"); // Wrapping Frimament
    //class_<FirmamentWithMask,bases<Firmament>,boost::noncopyable >("FirmamentWithMask",init<optional<int,int,double> >()) // Derived data type FirmamentWithMask
     class_<FirmamentWithMask,bases<Firmament> >("FirmamentWithMask",init<optional<int,int,double> >()) // Derived data type FirmamentWithMask
            // Function Definition wrappers
            .def("resize",&FirmamentWithMask::resize)
            .def("configure",static_cast< void(FirmamentWithMask::*)(const std::string&)> (&FirmamentWithMask::configure),configureWithOne())
            .def("configure",static_cast< void(FirmamentWithMask::*)(int,bool) > (&FirmamentWithMask::configure),configureWithThree())
            .def("readAllMasks",&FirmamentWithMask::readAllMasks)
            .def("readMaskFile",&FirmamentWithMask::readMaskFile)
            .def("readAzimuthInclinationMaskFile",&FirmamentWithMask::readAzimuthInclinationMaskFile)
            .def("getBallChange",&FirmamentWithMask::getBallChange)
            .def("getPlaneChange",&FirmamentWithMask::getPlaneChange)
            .def("getDrp_orig",&FirmamentWithMask::getDrp_orig)
            .def("getMask",&FirmamentWithMask::getMask)
            .def("getResultVector",&FirmamentWithMask::getResultVector) // a makeover to convert the list to vector.
            // Properties that are private and protected being wrapped
            .add_property("ballChange",&FirmamentWithMask::getBallChange)
            .add_property("planeChange",&FirmamentWithMask::getPlaneChange)
            .add_property("drp_orig",&FirmamentWithMask::getDrp_orig)
            .add_property("result",&FirmamentWithMask::getResultVector);
}




