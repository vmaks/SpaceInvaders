#include <ostream>
#include "point2d.hpp"

std::ostream & operator << (std::ostream & os, Point2D const & obj)
{
  os << "Point2D {" << obj.x() << ", " << obj.y() << "}";
  return os;
}


