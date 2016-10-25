#include "space.hpp"

uint Space::GetWidth() const
{
  return m_width;
}

uint Space::GetHeight() const
{
  return m_height;
}

void Space::SetWidth(uint const & width)
{
  m_width = width;
}

void Space::SetHeight(uint const & height)
{
  m_height = height;
}

void Space::AddGameEntity(TGameEntityConstPtr gameEntity)
{
  m_gameEntityList.push_back(gameEntity);
}

Space::~Space()
{

}

std::list<TGameEntityConstPtr> const & Space::GetGameEntity() const
{
  return m_gameEntityList;
}

std::ostream & operator << (std::ostream & os,
                            const Space & obj)
{
  os << "Space [Height: " << obj.GetHeight()
     << "; Width: " << obj.GetWidth() << "]";
  return os;
}
