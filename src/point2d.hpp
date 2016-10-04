#pragma once

#include <cmath>
#include <initializer_list>
#include <iostream>
#include <functional>

#include "constants.hpp"

class Point2D
{
public:
  Point2D() = default;

  Point2D(Point2D const & obj)
    : m_x(obj.m_x), m_y(obj.m_y)
  {}

  Point2D(float x, float y)
    : m_x(x), m_y(y)
  {}

  void swap(Point2D & rhs);

  bool operator == (Point2D const & obj) const;

  float & x() { return m_x; }
  float & y() { return m_y; }

  float const & x() const { return m_x; }
  float const & y() const { return m_y; }

  Point2D(std::initializer_list<float> const & lst);

  Point2D & operator = (Point2D const & obj);

  bool operator != (Point2D const & obj) const;

  bool operator < (Point2D const & obj) const;

  Point2D operator + (Point2D const & obj) const;

  Point2D operator - (Point2D const & obj) const;

  Point2D operator - () const;

  Point2D operator * (float scale) const
  {
    return { m_x * scale, m_y * scale };
  }

  Point2D operator / (float scale) const;

  Point2D & operator += (Point2D const & obj);

  Point2D & operator -= (Point2D const & obj);

  Point2D & operator *= (float scale);

  Point2D & operator /= (float scale);

  float operator [] (unsigned int index) const;

  // For hash calculation.
  struct Hash
  {
    size_t operator()(Point2D const & p) const
    {
      auto hasher = std::hash<float>();
      return (hasher(p.x()) ^ (hasher(p.y()) << 1));
    }
  };

private:
  bool EqualWithEps(float v1, float v2) const;

  float m_x = 0.0f, m_y = 0.0f;
};

std::ostream & operator << (std::ostream & os,
                            Point2D const & obj);
