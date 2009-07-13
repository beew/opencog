#include "Node_wrap.h"
#include <boost/python.hpp>

using namespace opencog;
using namespace boost::python;

void init_Node_py()
{
    class_<NodeWrap, bases<Atom>, boost::noncopyable>("Node", no_init)
        .def(self == self)
        .def(self != self)
        .def("hashCode", pure_virtual(&Atom::hashCode))
    ;
}

// For the pure virtual functions.

// For the non-pure virtual functions.

bool NodeWrap::operator==(const Atom& a) const
{
    if (override o = this->get_override("operator=="))
        return operator==(a);

    return Node::operator==(a);
}
bool NodeWrap::default_operator_equal_equal(const Atom& a) const
{
    return this->Node::operator==(a);
}

bool NodeWrap::operator!=(const Atom& a) const
{
    if (override o = this->get_override("operator!="))
        return operator!=(a);

    return Node::operator!=(a);
}
bool NodeWrap::default_operator_not_equal(const Atom& a) const
{
    return this->Node::operator!=(a);
}

size_t NodeWrap::hashCode(void) const
{
    if (override o = this->get_override("hashCode"))
        return hashCode();

    return Node::hashCode();
}
size_t NodeWrap::default_hashCode(void) const
{
    return this->Node::hashCode();
}
