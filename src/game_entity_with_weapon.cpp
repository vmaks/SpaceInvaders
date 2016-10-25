#include "game_entity_with_weapon.hpp"

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
  m_bulletManager = bulletmanager;
}

BulletManager const & GameEntityWithWeapon::GetBulletManager() const
{
  return m_bulletManager;
}
