#include "except.hpp"
#include "bullet.h"


Bullet::~Bullet()
{

}

uint Bullet::GetDamage() const
{
  return m_damage;
}

void Bullet::SetDamage(const uint & damage)
{
  m_damage = damage;
}

void Bullet::Update()
{
  throw NotImplementedException();
}

void Bullet::Move()
{
  throw NotImplementedException();  
}
