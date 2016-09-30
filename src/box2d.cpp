#include "box2d.hpp"


bool Box2D::checkInside(const Box2D &box, const Point2D &point)
{
    if (point.x() >= box.m_point1.x() &&
            point.x() <= box.m_point2.x() &&
            point.y() >= box.m_point1.y() &&
            point.y() <= box.m_point2.y())
    {
        return true;
    }

    return false;
}
