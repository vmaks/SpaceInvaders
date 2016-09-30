#pragma once

#include "point2d.hpp"
#include "box2d.hpp"

class Ray
{
public:
  Ray() = default;

  Ray(Point2D const & origin,
      Point2D const & direction)
    : m_origin(origin),
      m_direction(direction)
  {}

  Ray(Ray const & ray)
    : m_origin(ray.m_origin),
      m_direction(ray.m_direction)
  {}

  Ray & operator=(Ray const & obj)
  {
    if (this == &obj) return *this;
    m_origin = obj.m_origin;
    m_direction = obj.m_direction;
    return *this;
  }

  bool operator == (Ray const & obj) const
  {
    if (this == &obj) { return true; }

    if (this->m_direction != obj.direction()) { return false; }
    if (this->m_origin != obj.origin()) { return false; }

    return true;
  }

  bool operator != (Ray const & obj) const
  {
    return !(this->operator ==(obj));
  }

  static bool checkIntersection(Ray const & ray,
                                Box2D const & box);

  Point2D & origin() { return m_origin; }
  Point2D & direction() { return m_direction; }

  Point2D const & origin() const { return m_origin; }
  Point2D const & direction() const { return m_direction; }

  Point2D m_origin;
  Point2D m_direction;
};

inline std::ostream & operator << (std::ostream & os,
                                   Ray const & obj)
{
  os << "origin: " << obj.origin() << "; "
     << "direction: " << obj.direction() << std::endl;
  return os;
}
