#include "gtest/gtest.h"
#include "alien.h"
#include "space_ship.h"
#include "obstacle.h"
#include "bullet_manager.h"
#include "space.h"
#include "except.hpp"

TEST(bullet_test, test_construction)
{
  Bullet bullet1(15,Point2D(1.0f, 1.0f));
  EXPECT_EQ(bullet1.GetName(),"Bullet");
  EXPECT_EQ(bullet1.GetDamage(),15);
  EXPECT_EQ(bullet1.GetPosition(),Point2D(1.0f, 1.0f));
  bullet1.SetDamage(16);
  EXPECT_EQ(bullet1.GetDamage(),16);
  bullet1.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(bullet1.GetPosition(),Point2D(2.0f, 2.0f));

  Bullet bullet2;
  EXPECT_EQ(bullet2.GetName(),"Bullet");
  EXPECT_EQ(bullet2.GetDamage(),0);
  EXPECT_EQ(bullet2.GetPosition(),Point2D(0.0f, 0.0f));
  bullet2.SetDamage(16);
  EXPECT_EQ(bullet2.GetDamage(),16);
  bullet2.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(bullet2.GetPosition(),Point2D(2.0f, 2.0f));

  try
  {
      bullet2.Update();
  }
  catch(NotImplementedException const & ex)
  {
  }

  try
  {
      bullet2.Move();
  }
  catch(NotImplementedException const & ex)
  {
  }
}

TEST(bulletmanager_test, test_construction)
{
  BulletManager bulletManager1;
  EXPECT_EQ(bulletManager1.GetBullets().empty(),true);
  bulletManager1.SetAmmo(2);
  EXPECT_EQ(bulletManager1.GetBullets().size(),2);

  EXPECT_EQ(bulletManager1.GetBullets().front()->GetName(),"Bullet");
  EXPECT_EQ(bulletManager1.GetBullets().front()->GetDamage(),0);
  EXPECT_EQ(bulletManager1.GetBullets().front()->GetPosition(),Point2D(0.0f, 0.0f));
  bulletManager1.GetBullets().front()->SetDamage(16);
  EXPECT_EQ(bulletManager1.GetBullets().front()->GetDamage(),16);
  bulletManager1.GetBullets().front()->SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(bulletManager1.GetBullets().front()->GetPosition(),Point2D(2.0f, 2.0f));

  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetBullets().size(),1);
  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetBullets().size(),0);
  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetBullets().size(),0);
}

TEST(obstacle_test, test_construction)
{
  Obstacle obstacle1(15,Point2D(1.0f, 1.0f));
  EXPECT_EQ(obstacle1.GetName(),"Obstacle");
  EXPECT_EQ(obstacle1.GetHealth(),15);
  EXPECT_EQ(obstacle1.GetPosition(),Point2D(1.0f, 1.0f));
  obstacle1.SetHealth(16);
  EXPECT_EQ(obstacle1.GetHealth(),16);
  obstacle1.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(obstacle1.GetPosition(),Point2D(2.0f, 2.0f));

  Obstacle obstacle2;
  EXPECT_EQ(obstacle2.GetName(),"Obstacle");
  EXPECT_EQ(obstacle2.GetHealth(),0);
  EXPECT_EQ(obstacle2.GetPosition(),Point2D(0.0f, 0.0f));
  obstacle2.SetHealth(16);
  EXPECT_EQ(obstacle2.GetHealth(),16);
  obstacle2.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(obstacle2.GetPosition(),Point2D(2.0f, 2.0f));

  try
  {
      obstacle2.Update();
  }
  catch(NotImplementedException const & ex)
  {
  }
}

TEST(alien_test, test_construction)
{
  Alien alien1(15,Point2D(1.0f, 1.0f), 1115, 25);
  EXPECT_EQ(alien1.GetName(),"Alien");
  EXPECT_EQ(alien1.GetSpeed(),15);
  EXPECT_EQ(alien1.GetPosition(),Point2D(1.0f, 1.0f));
  EXPECT_EQ(alien1.GetRate(),1115);
  EXPECT_EQ(alien1.GetHealth(),25);
  alien1.SetHealth(16);
  EXPECT_EQ(alien1.GetHealth(),16);
  alien1.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(alien1.GetPosition(),Point2D(2.0f, 2.0f));
  alien1.SetSpeed(16);
  EXPECT_EQ(alien1.GetSpeed(),16);
  alien1.SetRate(16);
  EXPECT_EQ(alien1.GetRate(),16);

  try
  {
      alien1.Update();
  }
  catch(NotImplementedException const & ex)
  {
  }

  try
  {
      alien1.Move();
  }
  catch(NotImplementedException const & ex)
  {
  }

  Alien alien2;
  EXPECT_EQ(alien2.GetName(),"Alien");
  EXPECT_EQ(alien2.GetSpeed(),0);
  EXPECT_EQ(alien2.GetPosition(),Point2D(0.0f, 0.0f));
  EXPECT_EQ(alien2.GetRate(),0);
  EXPECT_EQ(alien2.GetHealth(),0);
  alien2.SetHealth(16);
  EXPECT_EQ(alien2.GetHealth(),16);
  alien2.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(alien2.GetPosition(),Point2D(2.0f, 2.0f));
  alien2.SetSpeed(16);
  EXPECT_EQ(alien2.GetSpeed(),16);
  alien2.SetRate(16);
  EXPECT_EQ(alien2.GetRate(),16);
}

TEST(spaceship_test, test_construction)
{
  SpaceShip spaceship1(Point2D(1.0f, 1.0f), 1115, 25);
  EXPECT_EQ(spaceship1.GetName(),"SpaceShip");
  EXPECT_EQ(spaceship1.GetPosition(),Point2D(1.0f, 1.0f));
  EXPECT_EQ(spaceship1.GetRate(),1115);
  EXPECT_EQ(spaceship1.GetHealth(),25);
  spaceship1.SetHealth(16);
  EXPECT_EQ(spaceship1.GetHealth(),16);
  spaceship1.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(spaceship1.GetPosition(),Point2D(2.0f, 2.0f));
  spaceship1.SetRate(16);
  EXPECT_EQ(spaceship1.GetRate(),16);

  try
  {
      spaceship1.Update();
  }
  catch(NotImplementedException const & ex)
  {
  }

  try
  {
      spaceship1.Move();
  }
  catch(NotImplementedException const & ex)
  {
  }

  SpaceShip spaceship2;
  EXPECT_EQ(spaceship2.GetName(),"SpaceShip");
  EXPECT_EQ(spaceship2.GetPosition(),Point2D(0.0f, 0.0f));
  EXPECT_EQ(spaceship2.GetRate(),0);
  EXPECT_EQ(spaceship2.GetHealth(),0);
  spaceship2.SetHealth(16);
  EXPECT_EQ(spaceship2.GetHealth(),16);
  spaceship2.SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(spaceship2.GetPosition(),Point2D(2.0f, 2.0f));
  spaceship2.SetRate(16);
  EXPECT_EQ(spaceship2.GetRate(),16);
  EXPECT_EQ(spaceship2.GetBulletManager().GetBullets().empty(),true);
  BulletManager bm1;
  bm1.SetAmmo(2);
  spaceship2.SetBulletManager(bm1);
  EXPECT_EQ(spaceship2.GetBulletManager().GetBullets().size(),2);
}

TEST(space_test, test_construction)
{
  Space space1;
  EXPECT_EQ(space1.GetHeight(),0);
  EXPECT_EQ(space1.GetWidth(),0);
  space1.SetHeight(15);
  EXPECT_EQ(space1.GetHeight(),15);
  space1.SetWidth(15);
  EXPECT_EQ(space1.GetWidth(),15);

  Space space2(15,15);
  EXPECT_EQ(space2.GetHeight(),15);
  EXPECT_EQ(space2.GetWidth(),15);
  space2.SetHeight(5);
  EXPECT_EQ(space2.GetHeight(),5);
  space2.SetWidth(5);
  EXPECT_EQ(space2.GetWidth(),5);
  EXPECT_EQ(space2.GetGameEntity().size(),0);
  space2.AddGameEntity(TGameEntityConstPtr(new Bullet()));
  EXPECT_EQ(space2.GetGameEntity().size(),1);
}


TEST(space_test, test_output)
{
  std::stringstream s;
  s << Space();
  EXPECT_EQ(s.str(), "Space [Height: 0; Width: 0]");
}

TEST(alien_test, test_output)
{
  std::stringstream s;
  s << Alien();
  EXPECT_EQ(s.str(), "Alien [Position: Point2D {0, 0}; Rate: 0; Health: 0; Speed: 0]");
}

TEST(bullet_test, test_output)
{
  std::stringstream s;
  s << Bullet();
  EXPECT_EQ(s.str(), "Bullet [Position: Point2D {0, 0}; Damage: 0]");
}

TEST(bulletmanager_test, test_output)
{
  BulletManager bm;
  bm.SetAmmo(2);
  std::stringstream s;
  s << bm;
  EXPECT_EQ(s.str(), "BulletManager [Bullet [Position: Point2D {0, 0}; Damage: 0]Bullet [Position: Point2D {0, 0}; Damage: 0]]");
}

TEST(spaceship_test, test_output)
{
  std::stringstream s;
  s << SpaceShip();
  EXPECT_EQ(s.str(), "SpaceShip [Position: Point2D {0, 0}; Rate: 0; Health: 0]");
}

TEST(obstacle_test, test_output)
{
  std::stringstream s;
  s << Obstacle();
  EXPECT_EQ(s.str(), "Obstacle [Position: Point2D {0, 0}; Health: 0]");
}
