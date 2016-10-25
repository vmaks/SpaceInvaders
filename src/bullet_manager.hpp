#pragma once

#include <list>
#include "bullet.hpp"

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

std::ostream & operator << (std::ostream & os,
                            BulletManager const & obj);
