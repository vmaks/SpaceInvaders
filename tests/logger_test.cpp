#include "list"
#include "gtest/gtest.h"
#include "logger.h"
#include "alien.h"
#include "space_ship.h"
#include "obstacle.h"
#include "bullet_manager.h"
#include "space.h"

TEST(logger_test, output_std_container)
{
  Logger(WARN) << "warning";
  Logger() << std::list<int>{2,3,4};
  Logger(ERROR) <<  std::vector<Bullet>(3,Bullet());
  Logger() << 5;
  Logger() << Alien() << SpaceShip() << Space(15,14);
  BulletManager bm;
  bm.SetAmmo(2);
  Logger() << Obstacle();
}
