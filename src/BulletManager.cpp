#include "BulletManager.h"

BulletManager::~BulletManager()
{

}

void BulletManager::Fire()
{
  if (not m_bulletList.empty())
  {
    m_bulletList.pop_front();
  }
}

std::list<TBulletPtr> BulletManager::GetBullets() const
{
  return m_bulletList;
}

void BulletManager::SetAmmo(uint const & count_bullet)
{
  if (count_bullet > 0) 
  {
    m_bulletList = std::list<TBulletPtr>(count_bullet, TBulletPtr(new Bullet()));
  }
}
