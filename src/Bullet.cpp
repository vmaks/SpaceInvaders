#include <stdexcept>
#include "Bullet.h"

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
  std::runtime_error("Not implemented");
}

void Bullet::Move()
{
  std::runtime_error("Not implemented");
}
