#include "ray.hpp"

#include <math.h>
#include <array>
#include <algorithm>

#include "constants.hpp"
#include "box2d.hpp"


Ray::Ray(const Point2D & origin,
         const Point2D & direction)
  : m_origin(origin)
{
  m_direction = normalize(direction);
}

void Ray::swap(Ray & rhs)
{
  std::swap(m_origin, rhs.m_origin);
  std::swap(m_direction, rhs.m_direction);
}

Ray::Ray(Ray && rhs)
{
  swap(rhs);
}

Ray & Ray::operator=(Ray && rhs)
{
  swap(rhs);
  return *this;
}

bool Ray::operator ==(Ray const & rhs) const
{
  if (this == &rhs) { return true; }

  if (this->m_direction != rhs.direction()) { return false; }
  if (this->m_origin != rhs.origin()) { return false; }

  return true;
}

bool Ray::operator !=(Ray const & rhs) const
{
  return !(this->operator ==(rhs));
}

Point2D Ray::normalize(Point2D direction)
{
  float x = checkZeroDenominator(direction.x());
  float y = checkZeroDenominator(direction.y());

  float length = sqrt(pow(x, 2.0) + pow(y, 2.0));

  direction /= length;

  return direction;
}

Ray & Ray::operator=(const Ray & rhs)
{
  Ray tmp(rhs);
  swap(tmp);
  return *this;
}

bool Ray::checkIntersection(
    Ray const & ray,
    Box2D const & box)
{
  // Check if a point inside a box.
  if (Box2D::checkInside(box, ray.origin()))
  {
    return true;
  }

  bool isSpecial = false;

  // Recalculate box points.
  // Use the point as an origin of a coordinate system for the box.
  float xBoxMinLower = box.boxMin().x() - ray.origin().x();
  float xBoxMaxUpper = box.boxMax().x() - ray.origin().x();

  float yBoxMinLower = box.boxMin().y() - ray.origin().y();
  float yBoxMaxUpper = box.boxMax().y() - ray.origin().y();

  float xBoxMinUpper = xBoxMinLower;
  float yBoxMinUpper = yBoxMaxUpper;

  float xBoxMaxLower = xBoxMaxUpper;
  float yBoxMaxLower = yBoxMinLower;

  float xRay = ray.direction().x();
  float yRay = ray.direction().y();

  // It handels special case when rectangle intersepts x-axis
  // to the right from an origin point of a ray.
  if (xRay < xBoxMinLower)
  {
    isSpecial = true;
  }

  // Check if the x coordinate is zero.
  xRay = checkZeroDenominator(xRay);
  xBoxMinLower = checkZeroDenominator(xBoxMinLower);
  xBoxMaxUpper = checkZeroDenominator(xBoxMaxUpper);
  xBoxMinUpper = checkZeroDenominator(xBoxMinUpper);
  xBoxMaxLower = checkZeroDenominator(xBoxMaxLower);

  // Calculate an anlge for the current point
  // and convert the angle to degrees.
  float angleRay = convertRadianToDegrees(
        std::atan(yRay / xRay));

  float angleBoxMinLower = convertRadianToDegrees(
        std::atan(yBoxMinLower / xBoxMinLower));

  float angleBoxMaxUpper = convertRadianToDegrees(
        std::atan(yBoxMaxUpper / xBoxMaxUpper));

  float angleBoxMinUpper = convertRadianToDegrees(
        std::atan(yBoxMinUpper / xBoxMinUpper));

  float angleBoxMaxLower = convertRadianToDegrees(
        std::atan(yBoxMaxLower / xBoxMaxLower));

  // Correct a value of the angle if needed.
  angleRay = recalculateAngle(
        xRay, yRay, angleRay);

  angleBoxMinLower = recalculateAngle(
        xBoxMinLower, yBoxMinLower, angleBoxMinLower);

  angleBoxMaxUpper = recalculateAngle(
        xBoxMaxUpper, yBoxMaxUpper, angleBoxMaxUpper);

  angleBoxMinUpper = recalculateAngle(
        xBoxMinUpper, yBoxMinUpper, angleBoxMinUpper);

  angleBoxMaxLower = recalculateAngle(
        xBoxMaxLower, yBoxMaxLower, angleBoxMaxLower);

  // Combine all angles for the box points.
  std::array<float, 4> angles = {
    angleBoxMinLower, angleBoxMaxUpper,
    angleBoxMinUpper, angleBoxMaxLower
  };

  if (isSpecial)
  {
    // It finds to angles.
    // Maximum angle in the first quater
    // and the minimun angle in the fouth quater.
    float angleMaxFirstQuater = 0.0f;
    float angleMinFourthQuater = 360.0f;

    for (auto const & item : angles)
    {
      if (item < 90.0f)
      {
        if (angleMaxFirstQuater < item)
        {
          angleMaxFirstQuater = item;
        }
      }
      else if (item > 270.0f)
      {
        if (angleMinFourthQuater > item)
        {
          angleMinFourthQuater = item;
        }
      }
    }

    // Compare the ray angle with
    // the max angle in the first quater
    // and the min angle in the fouth quater.
    if (angleRay <= angleMaxFirstQuater &&
        angleRay >= angleMinFourthQuater) {
      return true;
    }
  }
  else
  {
    // Find a min and max angles for the box points.
    auto result = std::minmax_element(
          std::begin(angles), std::end(angles));

    // Compare the ray angle with the min
    // and max angles for the box points.
    if (*result.first <= angleRay &&
        angleRay <= *result.second) {
      return true;
    }
  }

  return false;
}

float Ray::convertRadianToDegrees(float const & angle)
{
  return angle / Constants::PI * 180;
}

float Ray::recalculateAngle(float const & x,
                            float const & y,
                            float const & angle)
{
  float correctedAngle = 0.0f;

  // The second quarter.
  if (y > (0.0f - Constants::kEps) &&
      x < (0.0f + Constants::kEps))
  {
    correctedAngle = 180.0f - abs(angle);
  }

  // The third quarter.
  if (y < 0.0f &&
      x < (0.0f + Constants::kEps))
  {
    correctedAngle = 180.0f + abs(angle);
  }

  // The fouth quarter.
  if (y < 0.0f &&
      x > 0.0f)
  {
    correctedAngle = 360.0f - abs(angle);
  }

  return correctedAngle;
}

float Ray::checkZeroDenominator(float const & value)
{
  float tmp = value;

  if (abs(tmp) < Constants::kEps)
  {
    tmp = Constants::kEps;
  }

  return tmp;
}

void Ray::setOrigin(const Point2D & origin)
{
  m_origin = origin;
}

void Ray::setDirection(const Point2D & direction)
{
  m_direction = normalize(direction);
}

std::ostream & operator <<(std::ostream & os,
                           Ray const & rhs)
{
  os << "origin: " << rhs.origin() << "; "
     << "direction: " << rhs.direction() << std::endl;
  return os;
}
