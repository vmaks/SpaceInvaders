#pragma once

class Movable
{
public:
  virtual ~Movable() = default;
  virtual void Move() = 0;
};
