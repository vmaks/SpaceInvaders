#include "BulletManager.h"

BulletManager::~BulletManager()
{

}

void BulletManager::Fire()
{
  if(not m_bullet_list.empty())
    m_bullet_list.pop_front();
}

std::list<pBullet> BulletManager::GetAmmo() const
{
  return m_bullet_list;
}

void BulletManager::SetAmmo(uint const & count_bullet)
{
  if(count_bullet > 0)
    m_bullet_list = std::list<pBullet>(count_bullet, pBullet(new Bullet()));
}
