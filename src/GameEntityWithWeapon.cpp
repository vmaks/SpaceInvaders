#include "GameEntityWithWeapon.h"

uint GameEntityWithWeapon::GetRate() const
{
  return m_rate;
}

uint GameEntityWithWeapon::GetHealth() const
{
  return m_health;
}

void GameEntityWithWeapon::SetRate(uint const & rate)
{
  m_rate = rate;
}

void GameEntityWithWeapon::SetHealth(uint const & health)
{
  m_health = health;
}

GameEntityWithWeapon::~GameEntityWithWeapon()
{

}

void GameEntityWithWeapon::SetBulletManager(BulletManager const & bulletmanager)
{
  m_bullet_manager = bulletmanager;
}

BulletManager GameEntityWithWeapon::GetBulletManager() const
{
  return m_bullet_manager;
}
