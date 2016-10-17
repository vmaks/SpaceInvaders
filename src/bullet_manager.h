#pragma once

#include <list>
#include "bullet.h"

class BulletManager
{
public:
  BulletManager() = default;
  
  ~BulletManager();
  
  void Fire();
  std::list<TBulletPtr> GetBullets() const;
  void SetAmmo(uint const & count_bullet);

private:
  std::list<TBulletPtr> m_bulletList;
};
