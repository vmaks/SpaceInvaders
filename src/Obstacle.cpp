#include "Obstacle.h"
#include <stdexcept>

uint Obstacle::GetHealth() const
{
  return m_health;
}

void Obstacle::SetHealth(uint const & health)
{
  m_health = health;
}

void Obstacle::Update()
{
  std::runtime_error("Not implemented");
}
