#include "box2d.hpp"

Box2D::Box2D(Box2D && obj)
{
  swap(obj);
  std::cout << "Move copy constructor" <<std::endl;
}

Box2D & Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  Box2D tmp(obj);
  swap(tmp);
  return *this;
}

Box2D & Box2D::operator = (Box2D && obj)
{
  swap(obj);
  std::cout << "Move operator=" <<std::endl;
  return *this;
}

bool Box2D::operator == (Box2D const & obj) const
{
  return m_boxMin == obj.m_boxMin
      && m_boxMax == obj.m_boxMax;
}

void Box2D::swap(Box2D & obj)
{
  std::swap(m_boxMin, obj.m_boxMin);
  std::swap(m_boxMax, obj.m_boxMax);
}

bool Box2D::checkInside(const Box2D &box, const Point2D &point)
{
  if ((point.x() >= box.m_boxMin.x() &&
       point.x() <= box.m_boxMax.x() &&
       point.y() >= box.m_boxMin.y() &&
       point.y() <= box.m_boxMax.y()) ||
      (point.x() >= box.m_boxMax.x() &&
       point.x() <= box.m_boxMin.x() &&
       point.y() >= box.m_boxMax.y() &&
       point.y() <= box.m_boxMin.y())
      )
  {
    return true;
  }

  return false;
}



bool Box2D::checkBoxes(const Box2D &box1, const Box2D &box2)
{
  // If two boxes are not intersected with each other
  // then return false.
  if( box1.boxMax().x() <= box2.boxMin().x() ||
      box2.boxMax().x() <= box1.boxMin().x() ||
      box1.boxMin().y() >= box2.boxMax().y() ||
      box2.boxMin().y() >= box1.boxMax().y() )
  {
    return false;
  }

  return true;
}
