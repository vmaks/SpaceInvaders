#pragma once

#include "Bullet.h"
#include <list>

class BulletManager
{
public:
  BulletManager() = default;
  virtual ~BulletManager();
  void Fire();
  std::list<pBullet> GetAmmo() const;
  void SetAmmo(uint const & count_bullet);
private:
  std::list<pBullet> m_bullet_list;
};
