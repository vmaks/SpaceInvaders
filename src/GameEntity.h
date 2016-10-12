#pragma once

#include <memory>
#include "point2d.hpp"

class GameEntity 
{
public:
  GameEntity() = default;
  GameEntity(std::string const & name)
    :m_name(name)
  {}
  GameEntity(Point2D const & position,std::string const & name)
    : m_position(position),
      m_name(name)
  {}
  GameEntity(GameEntity const & obj)
    :m_position(obj.m_position),
      m_name(obj.m_name)
  {}
  virtual ~GameEntity();
  std::string const & GetName() const;
  virtual void Update() = 0;
  Point2D const & GetPosition() const;
  void SetPosition(Point2D const & point);
protected:
  Point2D m_position;
  std::string m_name;
};

using TGameEntityPtr = std::shared_ptr<GameEntity>;
using TGameEntityConstPtr = std::shared_ptr<const GameEntity>;
