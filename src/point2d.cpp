#include "point2d.hpp"

void Point2D::swap(Point2D & rhs)
{
  std::swap(m_x, rhs.m_x);
  std::swap(m_y, rhs.m_y);
}

bool Point2D::operator == (Point2D const & obj) const
{
  return EqualWithEps(m_x, obj.m_x) &&
      EqualWithEps(m_y, obj.m_y);
}

Point2D::Point2D(std::initializer_list<float> const & lst)
{
  float * vals[] = { &m_x, &m_y };
  int const count = sizeof(vals) / sizeof(vals[0]);
  auto it = lst.begin();
  for (int i = 0; i < count && it != lst.end(); i++, ++it)
    *vals[i] = *it;
}

Point2D & Point2D::operator = (Point2D const & obj)
{
  if (this == &obj) return *this;
  m_x = obj.m_x;
  m_y = obj.m_y;
  return *this;
}

bool Point2D::operator != (Point2D const & obj) const
{
  return !operator==(obj);
}

bool Point2D::operator < (Point2D const & obj) const
{
  if (m_x != obj.m_x)
  {
    return m_x < obj.m_x;
  }
  return m_y < obj.m_y;
}

Point2D Point2D::operator + (Point2D const & obj) const
{
  return { m_x + obj.m_x, m_y + obj.m_y };
}

Point2D Point2D::operator - (Point2D const & obj) const
{
  return { m_x - obj.m_x, m_y - obj.m_y };
}

Point2D Point2D::operator - () const
{
  return { -m_x, -m_y };
}

Point2D Point2D::operator / (float scale) const
{
  //TODO: обработать деление на 0.
  return { m_x / scale, m_y / scale };
}

Point2D & Point2D::operator += (Point2D const & obj)
{
  m_x += obj.m_x;
  m_y += obj.m_y;
  return *this;
}

Point2D & Point2D::operator -= (Point2D const & obj)
{
  m_x -= obj.m_x;
  m_y -= obj.m_y;
  return *this;
}

Point2D & Point2D::operator *= (float scale)
{
  m_x *= scale;
  m_y *= scale;
  return *this;
}

Point2D & Point2D::operator /= (float scale)
{
  //TODO: обработать деление на 0.
  m_x /= scale;
  m_y /= scale;
  return *this;
}

float Point2D::operator [](unsigned int index) const
{
  if (index >= 2) return 0.0f;
  return index == 0 ? m_x : m_y;
}

bool Point2D::EqualWithEps(float v1, float v2) const
{
  return fabs(v1 - v2) < Constants::kEps;
}

std::ostream & operator << (std::ostream & os,
                            Point2D const & obj)
{
  os << "Point2D {" << obj.x() << ", " << obj.y() << "}";
  return os;
}
