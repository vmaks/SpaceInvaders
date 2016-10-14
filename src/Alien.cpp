#include <stdexcept>
#include "Alien.h"

Alien::~ Alien()
{

}

void Alien::Move()
{
  std::runtime_error("Not implemented");
}

void Alien::Update()
{
  std::runtime_error("Not implemented");
}

uint Alien::GetSpeed() const
{
  return m_speed;
}

void Alien::SetSpeed(uint const & rate)
{
  m_speed = rate;
}
