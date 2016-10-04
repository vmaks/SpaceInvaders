#pragma once

#include "point2d.hpp"

class Box2D
{
public:
  Box2D() = default;

  Box2D(Box2D const & obj)
    : m_boxMin(obj.m_boxMin),
      m_boxMax(obj.m_boxMax)
  {}

  Box2D(Box2D && obj);

  Box2D(Point2D x, Point2D y)
    : m_boxMin(x), m_boxMax(y)
  {}

  Point2D & boxMin() { return m_boxMin; }
  Point2D & boxMax() { return m_boxMax; }

  Point2D const & boxMin() const { return m_boxMin; }
  Point2D const & boxMax() const { return m_boxMax; }

  Box2D & operator = (Box2D const & obj);
  Box2D & operator = (Box2D && obj);

  bool operator == (Box2D const & obj) const;

  void swap(Box2D & obj);
  ///
  /// Check if two boxes are intersected with each other.
  ///
  static bool checkBoxes(Box2D const & box1,
                         Box2D const & box2);

  ///
  /// Check if a point inside a box.
  ///
  static bool checkInside(Box2D const & box,
                          Point2D const & point);

private:
  Point2D m_boxMin = { 0.0f, 0.0f };
  Point2D m_boxMax = { 1.0f, 1.0f };
};


