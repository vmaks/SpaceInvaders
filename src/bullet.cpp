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

std::ostream & operator << (std::ostream & os,
                           const Bullet &obj)
{
  os << "Bullet {Position: " << obj.GetPosition() << " Damage: " << obj.GetDamage() << "} ";
  return os;
}
