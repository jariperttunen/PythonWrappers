/* Name: K.V.Goaplkrishnan
  Date: 11th July 2014
  Useage : Import LGMHistogramWrapper
  making an object
  d = LGMHistogramWrapper.cxxadt.LGMHistogram()
  access functions as d.functioname.

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
#include"LGMHistogram.h"


using namespace std;
using namespace boost::python;
using namespace cxxadt;
class cxxdummy{};

BOOST_PYTHON_MODULE(LGMHistogramWrapper)
{

    class_<std::vector<double> >("VectorDouble")   // Wrapper for a doubel vector
            .def(vector_indexing_suite<std::vector<double> >());

    class_<std::vector<int> >("VectorInt")   // Wrapper for a Integer vector
            .def(vector_indexing_suite<std::vector<int> >());

    scope cxxadt = class_<cxxdummy>("cxxadt"); //wrapping the namespace cxxadt using the dummy variable
    //The init matches/wraps constructor with default arguments
    class_<cxxadt::LGMHistogram>("LGMHistogram",init<vector<double> >())
            .def(init<int, double, double>())
            .def(self += self)
            .def("reassign", &LGMHistogram::operator=,return_internal_reference<>())
            .def("getFrequency",&LGMHistogram::getFrequency)
            .def("getN",&LGMHistogram::getN)
            .def("classify",&LGMHistogram::classify)
            .def("getHistogram",&LGMHistogram::getHistogram)
            .def("getLimits",&LGMHistogram::getLimits)
            .add_property("vx",&LGMHistogram::getLimits)
            .add_property("vf",&LGMHistogram::getHistogram)
            .add_property("n",&LGMHistogram::getN);
}


