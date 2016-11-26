#include "gtest/gtest.h"
#include "box2d.hpp"
#include "except.hpp"

TEST(box2d_test, test_construction)
{
  Box2D box1;
  EXPECT_EQ(box1.boxMin(), Point2D(0.0f, 0.0f));
  EXPECT_EQ(box1.boxMax(), Point2D(1.0f, 1.0f));

  Box2D box2 = Box2D::createBox(Point2D(1.0f, 2.0f), Point2D(5.0f, 8.0f));
  EXPECT_EQ(box2.boxMin(), Point2D(1.0f, 2.0f));
  EXPECT_EQ(box2.boxMax(), Point2D(5.0f, 8.0f));

  try
  {
      Box2D::createBox(Point2D(1.0f, 2.0f), Point2D(1.0f, -8.0f));
  }
  catch(std::invalid_argument const & ex)
  {
  }

  Box2D box3 = box2;
  EXPECT_EQ(box3, box2);
  Box2D box5 = Box2D::createBox(Point2D(1.0f, 2.0f), Point2D(-1.0f, 8.0f));
  EXPECT_EQ(box5.boxMin(), Point2D(-1.0f, 2.0f));
  EXPECT_EQ(box5.boxMax(), Point2D(1.0f, 8.0f));
  Box2D box6 = Box2D::createBox(Point2D(-1.0f, 2.0f), Point2D(1.0f, -8.0f));
  EXPECT_EQ(box6.boxMin(), Point2D(-1.0f, -8.0f));
  EXPECT_EQ(box6.boxMax(), Point2D(1.0f, 2.0f));
  Box2D box7 = Box2D::createBox(Point2D(1.0f, 2.0f), Point2D(-1.0f, -8.0f));
  EXPECT_EQ(box7.boxMin(), Point2D(-1.0f, -8.0f));
  EXPECT_EQ(box7.boxMax(), Point2D(1.0f, 2.0f));
}

TEST(box2d_test, test_check)
{
  Box2D box1 = Box2D::createBox(Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f));
  Box2D box2 = Box2D::createBox(Point2D(0.0f, 2.0f), Point2D(1.0f, 3.0f));
  Box2D box3 = Box2D::createBox(Point2D(2.0f, 0.0f), Point2D(3.0f, 1.0f));
  Box2D box4 = Box2D::createBox(Point2D(2.0f, 2.0f), Point2D(3.0f, 3.0f));
  Box2D box5 = Box2D::createBox(Point2D(0.5f, 0.5f), Point2D(2.5f, 2.5f));
  Box2D box6 = Box2D::createBox(Point2D(1.0f, 1.0f), Point2D(2.0f, 2.0f));
  Box2D box7 = Box2D::createBox(Point2D(2.0f, 1.0f), Point2D(3.0f, 2.0f));
  Box2D box8 = Box2D::createBox(Point2D(1.0f, 2.0f), Point2D(2.0f, 3.0f));
  Box2D box9 = Box2D::createBox(Point2D(0.0f, 1.0f), Point2D(1.0f, 2.0f));
  Box2D box10 = Box2D::createBox(Point2D(1.0f, 0.0f), Point2D(2.0f, 1.0f));
  Box2D box11 = Box2D::createBox(Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f));
  EXPECT_EQ(Box2D::checkBoxes(box1,box2),false);
  EXPECT_EQ(Box2D::checkBoxes(box2,box1),false);
  EXPECT_EQ(Box2D::checkBoxes(box2,box3),false);
  EXPECT_EQ(Box2D::checkBoxes(box3,box2),false);
  EXPECT_EQ(Box2D::checkBoxes(box5,box3),true);
  EXPECT_EQ(Box2D::checkBoxes(box3,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box4),true);
  EXPECT_EQ(Box2D::checkBoxes(box4,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box6,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box6),true);
  EXPECT_EQ(Box2D::checkBoxes(box7,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box7),true);
  EXPECT_EQ(Box2D::checkBoxes(box8,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box8),true);
  EXPECT_EQ(Box2D::checkBoxes(box9,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box9),true);
  EXPECT_EQ(Box2D::checkBoxes(box10,box5),true);
  EXPECT_EQ(Box2D::checkBoxes(box5,box10),true);
  EXPECT_EQ(Box2D::checkBoxes(box6,box3),false);
  EXPECT_EQ(Box2D::checkBoxes(box3,box6),false);
  EXPECT_EQ(Box2D::checkBoxes(box7,box6),false);
  EXPECT_EQ(Box2D::checkBoxes(box6,box7),false);
  EXPECT_EQ(Box2D::checkBoxes(box8,box6),false);
  EXPECT_EQ(Box2D::checkBoxes(box6,box8),false);
  EXPECT_EQ(Box2D::checkBoxes(box2,box6),false);
  EXPECT_EQ(Box2D::checkBoxes(box6,box2),false);
  EXPECT_EQ(Box2D::checkBoxes(box1,box11),true);
  EXPECT_EQ(Box2D::checkBoxes(box11,box1),true);
}

TEST(box2d_test, test_point_check_inside)
{
  Point2D p1 = { 0.0f, 0.0f };

  Box2D box1 = Box2D::createBox(Point2D(-1.0f, -1.0f),Point2D(1.0f, 1.0f));

  EXPECT_EQ(Box2D::checkInside(box1, p1), true);
}

TEST(box2d_test, test_point_check_outside)
{
  Point2D p1 = { 2.0f, 1.0f };

  Point2D p2 = { -10.0f, -3.0f };

  Box2D box1 = Box2D::createBox(Point2D(-1.0f, -1.0f),Point2D(1.0f, 1.0f));

  EXPECT_EQ(Box2D::checkInside(box1, p1), false);
  EXPECT_EQ(Box2D::checkInside(box1, p2), false);
}

TEST(box2d_test, move)
{
  Box2D r1 = Box2D::createBox(Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f));
  Box2D r2 = std::move(r1);
  Box2D r3;
  r3 = std::move(r1);
}

TEST(box2d_test, test_output)
{
  std::stringstream s;
  s << Box2D::createBox(Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f));
  EXPECT_EQ(s.str(), "Box2D [BoxMin: Point2D {0, 0}; BoxMax: Point2D {1, 1}]");
}
