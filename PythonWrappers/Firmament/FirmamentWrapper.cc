/* This is a wrapper for Firmament.h to be used in python and needs to be checked again for accuracy.
  This is written using boost python
  Written: K.V.Gopalkrishnan
  Date : 1st July 2014.
  */
//**********************************************************************************************************************************************************
#include <iostream>
#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/class.hpp>
#include <boost/python/overloads.hpp>
#include <boost/python/args.hpp>
#include <boost/python/return_internal_reference.hpp>

//Firmament is the c++ header file for Firmament
#include <Firmament.h>
using namespace std;
using namespace boost::python;
using namespace cxxadt;
using namespace sky;


//Sample class wrapper for Firmament, see also matching setup.py
BOOST_PYTHON_MODULE(Firmament)
{
    //The init matches/wraps constructor with default arguments
    class_<Firmament>("Firmament",init<optional<int,int,int> >())
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
            .add_property("num_of_azim",&Firmament::getNoOfInclinations)
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

}






