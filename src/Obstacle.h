#pragma once

#include "GameEntity.h"

class Obstacle: public GameEntity
{
public:
  Obstacle()
    : GameEntity("Obstacle")
  {}

  Obstacle(uint const & health,Point2D const & position)
    :GameEntity(position, "Obstacle"),
      m_health(health)
  {}

  ~Obstacle() override;

  void Update() override;
  uint GetHealth() const;
  void SetHealth(uint const & health);

private:
  uint m_health = 0;
};
