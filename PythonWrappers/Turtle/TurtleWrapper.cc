/* Name: K.V.Goaplkrishnan
  Date:16th July 2014
  Notes : Friend Functions are not wrapped. In the real Turtle.h file i wrote 4 functions to get the
  h,l,u,p as a property and then wrapped them.I wrapped Position vector and Point functions as required.
  Python usage as normal

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
#include"Turtle.h"
#include <mathsym.h>
#include <Point.h>
#include <PositionVector.h>

using namespace std;
using namespace boost::python;
using namespace cxxadt;

BOOST_PYTHON_MODULE(TurtleWrapper)
{

    class_<Turtle>("Turtle")  //Defining all the constructors for Turtle
            .def(init<Point>())
            .def(init<Turtle>())
            .def(init<Point,const PositionVector,const PositionVector>())
            .def(init<Turtle>())
            .def("reassign", &Turtle::operator=,return_internal_reference<>())
            .def("turn",&Turtle::turn,return_internal_reference<>())
            .def("pitch",&Turtle::pitch,return_internal_reference<>())
            .def("roll", &Turtle::roll,return_internal_reference<>())
            .def("hroll",&Turtle::hroll,return_internal_reference<>())
            .def("hrz",&Turtle::hrz,return_internal_reference<>())
            .def("forward",&Turtle::forward,return_internal_reference<>())
            .def("up",&Turtle::up,return_internal_reference<>())
            .def("hdir",&Turtle::hdir,return_internal_reference<>())
            .def("hup",&Turtle::hup,return_internal_reference<>())
            .def("geth",&Turtle::geth)
            .def("getl",&Turtle::getl)
            .def("getu",&Turtle::getu)
            .def("getp",&Turtle::getp)
            .add_property("h",&Turtle::geth)
            .add_property("l",&Turtle::getl)
            .add_property("u",&Turtle::getu)
            .add_property("p",&Turtle::getp);

    class_<PositionVector>("PositionVector",init<const PositionVector>()); //Wrapper for the PositionVector
    class_<Point>("Point",init<const Point>());

}


