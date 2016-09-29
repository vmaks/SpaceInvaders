#include "gtest/gtest.h"
#include "box2d.hpp"

TEST(box2d_test, test_construction)
{
  // Тест на создание объекта по умолчанию.
  Box2D box1;
  EXPECT_EQ(box1.point1(), Point2D(0.0f, 0.0f));
  EXPECT_EQ(box1.point2(), Point2D(1.0f, 1.0f));

  // Тест на создание объекта с параметрами.
  Box2D box2 = { Point2D(1.0f, 2.0f), Point2D(5.0f, 8.0f) };
  EXPECT_EQ(box2.point1(), Point2D(1.0f, 2.0f));
  EXPECT_EQ(box2.point2(), Point2D(5.0f, 8.0f));

  // Тест на создание копии объекта.
  Box2D box3 = box2;
  EXPECT_EQ(box3, box2);
}

TEST(box2d_test, test_check)
{
  // Тест на проверку пересечения прямоугольников
  Box2D box1 = { Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f) };
  Box2D box2 = { Point2D(0.0f, 2.0f), Point2D(1.0f, 3.0f) };
  Box2D box3 = { Point2D(2.0f, 0.0f), Point2D(3.0f, 1.0f) };
  Box2D box4 = { Point2D(2.0f, 2.0f), Point2D(3.0f, 3.0f) };
  Box2D box5 = { Point2D(0.5f, 0.5f), Point2D(2.5f, 2.5f) };
  Box2D box6 = { Point2D(1.0f, 1.0f), Point2D(2.0f, 2.0f) };
  Box2D box7 = { Point2D(2.0f, 1.0f), Point2D(3.0f, 2.0f) };
  Box2D box8 = { Point2D(1.0f, 2.0f), Point2D(2.0f, 3.0f) };
  Box2D box9 = { Point2D(0.0f, 1.0f), Point2D(1.0f, 2.0f) };
  Box2D box10 = { Point2D(1.0f, 0.0f), Point2D(2.0f, 1.0f) };
  Box2D box11 = { Point2D(0.0f, 0.0f), Point2D(1.0f, 1.0f) };
  EXPECT_EQ(checkBoxes(box1,box2),false);
  EXPECT_EQ(checkBoxes(box2,box1),false);
  EXPECT_EQ(checkBoxes(box2,box3),false);
  EXPECT_EQ(checkBoxes(box3,box2),false);
  EXPECT_EQ(checkBoxes(box5,box3),true);
  EXPECT_EQ(checkBoxes(box3,box5),true);
  EXPECT_EQ(checkBoxes(box5,box4),true);
  EXPECT_EQ(checkBoxes(box4,box5),true);
  EXPECT_EQ(checkBoxes(box6,box5),true);
  EXPECT_EQ(checkBoxes(box5,box6),true);
  EXPECT_EQ(checkBoxes(box7,box5),true);
  EXPECT_EQ(checkBoxes(box5,box7),true);
  EXPECT_EQ(checkBoxes(box8,box5),true);
  EXPECT_EQ(checkBoxes(box5,box8),true);
  EXPECT_EQ(checkBoxes(box9,box5),true);
  EXPECT_EQ(checkBoxes(box5,box9),true);
  EXPECT_EQ(checkBoxes(box10,box5),true);
  EXPECT_EQ(checkBoxes(box5,box10),true);
  EXPECT_EQ(checkBoxes(box6,box3),false);
  EXPECT_EQ(checkBoxes(box3,box6),false);
  EXPECT_EQ(checkBoxes(box7,box6),false);
  EXPECT_EQ(checkBoxes(box6,box7),false);
  EXPECT_EQ(checkBoxes(box8,box6),false);
  EXPECT_EQ(checkBoxes(box6,box8),false);
  EXPECT_EQ(checkBoxes(box2,box6),false);
  EXPECT_EQ(checkBoxes(box6,box2),false);
  EXPECT_EQ(checkBoxes(box1,box11),true);
  EXPECT_EQ(checkBoxes(box11,box1),true);
}
