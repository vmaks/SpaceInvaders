#include "ray.hpp"

#include <math.h>
#include <array>
#include <algorithm>

#include "constants.hpp"
#include "box2d.hpp"


bool Ray::checkIntersection(
    Ray const & ray,
    Box2D const & box)
{
  if (Box2D::checkInside(box, ray.origin()))
  {
    return true;
  }

  float x_1_n = box.point1().x() - ray.origin().x();
  float x_2_n = box.point2().x() - ray.origin().x();

  float y_1_n = box.point1().y() - ray.origin().y();
  float y_2_n = box.point2().y() - ray.origin().y();

  float x_3_n = x_1_n;
  float y_3_n = y_2_n;

  float x_4_n = x_2_n;
  float y_4_n = y_1_n;

  float y_ray = ray.direction().y();

  if (y_ray < Constants::kEps)
  {
    y_ray = Constants::kEps;
  }

  float angle_ray = convertRadianToDegrees(
        std::atan(y_ray / ray.direction().x()));

  // TODO
  // Check zero denominator!
  // Add comments!
  // Add check for a point inside a box!
  float angle_1_n = convertRadianToDegrees(
        std::atan(y_1_n / x_1_n));
  float angle_2_n = convertRadianToDegrees(
        std::atan(y_2_n / x_2_n));
  float angle_3_n = convertRadianToDegrees(
        std::atan(y_3_n / x_3_n));
  float angle_4_n = convertRadianToDegrees(
        std::atan(y_4_n / x_4_n));

  std::array<float, 4> angles = {
    angle_1_n, angle_2_n, angle_3_n, angle_4_n
  };

  auto result = std::minmax_element(
        std::begin(angles), std::end(angles));

  if (*result.first <= angle_ray
      && angle_ray <= *result.second) {
    return true;
  }

  return false;
}

float Ray::convertRadianToDegrees(float const & angle)
{
  return angle / Constants::PI * 180;
}
