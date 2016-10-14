#pragma once

#include <list>
#include "Bullet.h"

class BulletManager
{
public:
  BulletManager() = default;
  
  ~BulletManager();
  
  void Fire();
  std::list<TBulletPtr> GetAmmo() const;
  void SetAmmo(uint const & count_bullet);

private:
  std::list<TBulletPtr> m_bulletList;
};
