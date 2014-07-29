/* Written: K.V.Gopalkrishnan
  Date :  1st week of july 2014
  Usage in Python: Import FirmamentWithMask
  To make an object
  d = FirmamentWithMask.sky.Firmament()
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
{

    scope sky = class_<SkyNamespaceDummy>("sky"); //wrapping the namespace sky using the dummy variable
    class_<sky::FindNextMask>("FindNextMask",init<int>()); // Wrapping the real namespace sky
    class_<Lex,boost::noncopyable>("Lex"); // Wrapping the class Lex with copy constructors

    class_<std::vector<std::pair<int, string> > >("VectorOfPairs") // Wrapper for pairs of vector
            .def(vector_indexing_suite<std::vector<std::pair<int,string> > >());

    class_<std::pair<int, string> >("DoublePair") // Wrapper for a pair only
            .def_readwrite("first", &std::pair<int, string>::first)
            .def_readwrite("second", &std::pair<int, string>::second);

    class_<Firmament>("Firmament"); // Wrapping Frimament
    class_<FirmamentWithMask,bases<Firmament>,boost::noncopyable >("FirmamentWithMask",init<optional<int,int,double> >()) // Derived data type FirmamentWithMask
            // Function Definition wrappers
            .def("resize",&FirmamentWithMask::resize)
            .def("configure",static_cast< void(FirmamentWithMask::*)(const std::string&)> (&FirmamentWithMask::configure),configureWithOne())
            .def("configure",static_cast< void(FirmamentWithMask::*)(int,bool) > (&FirmamentWithMask::configure),configureWithThree())
            .def("readAllMasks",&FirmamentWithMask::readAllMasks)
            .def("readMaskFile",&FirmamentWithMask::readMaskFile)
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




