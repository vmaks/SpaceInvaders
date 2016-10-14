#include "GameEntityWithWeapon.h"

class Alien : public GameEntityWithWeapon
{
public:
  Alien()
    : GameEntityWithWeapon("Alien")
  {}

  Alien(uint const & speed,
        Point2D const & position,
        uint const & rate,
        uint const & health)
    : GameEntityWithWeapon(position, "Alien", rate, health),
      m_speed(speed)
  {}

  ~Alien() override;

  void Move() override;
  void Update() override;
  uint GetSpeed() const;
  void SetSpeed(uint const & rate);
  
private:
  uint m_speed = 0;
};
