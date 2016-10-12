#include "GameEntity.h"
#include "Movable.h"

class Bullet: public GameEntity, public Movable
{
public:
  Bullet()
    : GameEntity("Bullet")
  {}
  Bullet(uint const & damage,Point2D const & position)
    :GameEntity(position,"Bullet"),
      m_damage(damage)
  {}
  virtual ~Bullet();
  void Update() override;
  void Move() override;
  uint GetDamage() const;
  void SetDamage(uint const & damage);
private:
  uint m_damage = 0;
};

typedef std::shared_ptr<Bullet> pBullet;
