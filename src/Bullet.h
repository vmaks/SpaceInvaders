#include "GameEntity.h"

class Bullet: public GameEntity
{
public:
  Bullet()
    : GameEntity("Bullet")
  {}
  Bullet(uint const & damage,Point2D const & position)
    :GameEntity(position,"Bullet"),
      m_damage(damage)
  {}
  void Update() override;
  uint GetDamage() const;
  void SetDamage(uint const & damage);
private:
  uint m_damage = 0;
};

typedef std::shared_ptr<Bullet> pBullet;
