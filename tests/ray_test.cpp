#include "gtest/gtest.h"
#include "ray.hpp"

TEST(ray_test, test_construction)
{
  // Default constructor.
  Ray r1;
  EXPECT_EQ(r1.origin().x(), 0.0f);
  EXPECT_EQ(r1.origin().y(), 0.0f);
  EXPECT_EQ(r1.direction().x(), 0.0f);
  EXPECT_EQ(r1.direction().y(), 0.0f);

  // Constructor with parameters.
  Ray r2(Point2D(1.0f, 1.0f),
         Point2D(0.0f, 1.0f));

  EXPECT_EQ(r2.origin().x(), 1.0f);
  EXPECT_EQ(r2.origin().y(), 1.0f);
  EXPECT_EQ(r2.direction().x(), 0.0f);
  EXPECT_EQ(r2.direction().y(), 1.0f);

  // Copy constructor.
  Ray r3 = r2;

  EXPECT_EQ(r3 == r2, true);
}

TEST(ray_test, test_assignment)
{
  Ray r1;

  r1 = Ray(Point2D(1.0f, 1.0f),
           Point2D(0.0f, 1.0f));

  EXPECT_EQ(r1.origin().x(), 1.0f);
  EXPECT_EQ(r1.origin().y(), 1.0f);
  EXPECT_EQ(r1.direction().x(), 0.0f);
  EXPECT_EQ(r1.direction().y(), 1.0f);
}

TEST(ray_test, test_equality)
{
  Ray r1(Point2D(1.0f, 1.0f),
         Point2D(0.0f, 1.0f));

  Ray r2(Point2D(1.0f, 1.0f),
         Point2D(0.0f, 1.0f));

  Ray r3(Point2D(1.0f, 1.0f),
         Point2D(1.0f, 1.0f));

  EXPECT_EQ(r1, r2);
  EXPECT_NE(r1, r3);
}
