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

#include<Box.h>
#include<PositionVector.h>
#include<Point.h>
using namespace std;
using namespace boost::python;
using namespace cxxadt;

BOOST_PYTHON_MODULE(Box){
  class_<PositionVector>("PositionVector",init<const double,const double,const double >());
  class_<Point>("Point",init<const double,const double,const double >());
  class_<Box>("Box",init<const Point,const Point>())
    .def("intersect",&Box::intersect);
    //Wrapper for the PositionVector

}
