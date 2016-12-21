/*  Written : K.V.Gopalkrishnan
    Date    : 14 July 2014
   I have implemented the operator() wrapper but the code crashes in PrametricCurve.cc line 149.
   The 'i' in the loop goes out of bounds. Now I have not fixed this else this wrapper is completed.
   Once that is fixed just uncomment the line .def("__call__", &ParametricCurve::operator() )
   and ideally it should work well. I also implemented an empty class for the function
   withXYvectors since there was no definition for this function in ParametricCurve.cc.
   So now this works.

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
#include <boost/python/return_internal_reference.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/to_python_converter.hpp>
#include<boost/python/operators.hpp>
#include<boost/python/operators.hpp>
#include<boost/python/detail/caller.hpp>
#include<boost/python/default_call_policies.hpp>
#include"ParametricCurve.h"
#include <vector>
#include <stdio.h>
#include <fstream>
#include <float.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;
using namespace boost::python;
using namespace cxxadt;
class cxxdummy{};

BOOST_PYTHON_MODULE(ParametricCurveWrapper)
{

    class_<std::vector<double> >("VectorDouble")   // Wrapper for a doubel vector
            .def(vector_indexing_suite<std::vector<double> >());
    scope cxxadt = class_<cxxdummy>("cxxadt"); //wrapping the namespace cxxadt using the dummy variable
                                               //The init matches/wraps constructor with default arguments
    class_<cxxadt::ParametricCurve>("ParametricCurve")
      .def(init<const string>())
      .def(init<const string,int>())
      .def(init<const vector<double> > ())
      .def(init<ParametricCurve> ())
      .def(init<double> ())
      .def(init<int,vector<double>,vector<double> > ())
      .def("reassign", &ParametricCurve::operator=,return_internal_reference<>())
      .def("__call__", &ParametricCurve::operator() )
      .def("install",&ParametricCurve::install)
      .def("ok",&ParametricCurve::ok)
      .def("eval",&ParametricCurve::eval)
      .def("getFile",&ParametricCurve::getFile)
      .def("getVector",&ParametricCurve::getVector)
      .add_property("v",&ParametricCurve::getVector)
      .add_property("file",&ParametricCurve::getFile);
}


