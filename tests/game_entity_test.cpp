#include "gtest/gtest.h"
#include "Alien.h"
#include "SpaceShip.h"
#include "Obstacle.h"
#include "BulletManager.h"

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
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
  }

}

TEST(bulletmanager_test, test_construction)
{
  BulletManager bulletManager1;
  EXPECT_EQ(bulletManager1.GetAmmo().empty(),true);
  bulletManager1.SetAmmo(2);
  EXPECT_EQ(bulletManager1.GetAmmo().size(),2);

  EXPECT_EQ(bulletManager1.GetAmmo().front()->GetName(),"Bullet");
  EXPECT_EQ(bulletManager1.GetAmmo().front()->GetDamage(),0);
  EXPECT_EQ(bulletManager1.GetAmmo().front()->GetPosition(),Point2D(0.0f, 0.0f));
  bulletManager1.GetAmmo().front()->SetDamage(16);
  EXPECT_EQ(bulletManager1.GetAmmo().front()->GetDamage(),16);
  bulletManager1.GetAmmo().front()->SetPosition(Point2D(2.0f, 2.0f));
  EXPECT_EQ(bulletManager1.GetAmmo().front()->GetPosition(),Point2D(2.0f, 2.0f));

  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetAmmo().size(),1);
  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetAmmo().size(),0);
  bulletManager1.Fire();
  EXPECT_EQ(bulletManager1.GetAmmo().size(),0);
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
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
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
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
  }

  try
  {
      alien1.Move();
  }
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
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
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
  }

  try
  {
      spaceship1.Move();
  }
  catch(std::exception const & ex)
  {
    std::cout << ex.what() << std::endl;
      EXPECT_EQ(ex.what(),std::string("Not implemented"));
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
  EXPECT_EQ(spaceship2.GetBulletManager().GetAmmo().empty(),true);
  BulletManager bm1;
  bm1.SetAmmo(2);
  spaceship2.SetBulletManager(bm1);
  EXPECT_EQ(spaceship2.GetBulletManager().GetAmmo().size(),2);
}
