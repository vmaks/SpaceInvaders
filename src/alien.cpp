#include "except.hpp"
#include "alien.h"


Alien::~ Alien()
{

}

void Alien::Move()
{
  throw NotImplementedException();
}

void Alien::Update()
{
  throw NotImplementedException();
}

uint Alien::GetSpeed() const
{
  return m_speed;
}

void Alien::SetSpeed(uint const & rate)
{
  m_speed = rate;
}
