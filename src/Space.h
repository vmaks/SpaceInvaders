#pragma once

#include <list>
#include "GameEntity.h"

class Space
{
public:
  Space() = default;

  Space(uint const & width,uint const & height)
    : m_width(width),
      m_height(height)
  {}

  virtual ~Space();

  uint GetWidth() const;
  uint GetHeight() const;
  void SetWidth(uint const & width);
  void SetHeight(uint const & height);
  std::list<TGameEntityConstPtr> GetGameEntity() const;
  void AddGameEntity(TGameEntityConstPtr gameEntity);
  
private:
  uint m_width = 0;
  uint m_height = 0;
  std::list<TGameEntityConstPtr> m_gameEntityList;
};
