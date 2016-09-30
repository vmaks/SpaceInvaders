#pragma once

#include "point2d.hpp"

class Box2D
{
public:
  // Разрешаем конструирование по умолчанию.
  Box2D() = default;

  // Конструктор копирования.
  Box2D(Box2D const & obj)
    : m_point1(obj.m_point1), m_point2(obj.m_point2)
  {}

  // Конструктор с параметрами.
  Box2D(Point2D x, Point2D y)
    : m_point1(x), m_point2(y)
  {}

  Point2D & point1() { return m_point1; }
  Point2D & point2() { return m_point2; }

  Point2D const & point1() const { return m_point1; }
  Point2D const & point2() const { return m_point2; }

  // Оператор присваивания.
  Box2D & operator = (Box2D const & obj)
  {
    if (this == &obj) return *this;
    m_point1 = obj.m_point1;
    m_point2 = obj.m_point2;
    return *this;
  }

  // Оператор логического равенства.
  bool operator == (Box2D const & obj) const
  {
    return m_point1 == obj.m_point1 && m_point2 == obj.m_point2;
  }

private:
    Point2D m_point1={ 0.0f, 0.0f };
    Point2D m_point2={ 1.0f, 1.0f };
};

inline bool checkBoxes(Box2D const & box1,Box2D const & box2)
{
    bool result;
    if( box1.point2().x() <= box2.point1().x() || box2.point2().x() <= box1.point1().x() ||
            box1.point1().y() >= box2.point2().y() || box2.point1().y() >= box1.point2().y() )
        result = false;
    else
        result = true;
    return result;
}
