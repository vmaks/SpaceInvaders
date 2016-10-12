#pragma once

#include <memory>
#include "point2d.hpp"

class GameEntity {

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
  std::string GetName() const;
  virtual void Update() = 0;
  Point2D GetPosition() const;
  void SetName(std::string const & name);
  void SetPosition(Point2D const & point);
protected:
  Point2D m_position;
  std::string m_name;
};

typedef std::shared_ptr<GameEntity> pGameEntity;
