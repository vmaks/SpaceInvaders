#pragma once

#include "GameEntityWithWeapon.h"

class SpaceShip: public GameEntityWithWeapon
{
public:
  SpaceShip()
    : GameEntityWithWeapon("SpaceShip")
  {}

  SpaceShip(Point2D const & position,
            uint const & rate,
            uint const & health)
    : GameEntityWithWeapon(position,"SpaceShip",rate,health)
  {}

  ~SpaceShip() override;

  void Update() override;
  void Move() override;
};
