#pragma once

#include <iostream>

enum class TypeLog
{
  DEBUG,
  INFO,
  WARN,
  ERROR
};


class Logger
{
public:
  Logger() = default;

  Logger(TypeLog const & type);

  ~Logger();

  template<class T>
  Logger & operator << (T const & obj)
  {
    std::cout << "[" << GetLabel(m_msgLevel) << "] " << obj;
    m_isOpened = true;
    return *this;
  }

  template<typename T, template<typename, typename...> class C, typename... Args>
  Logger & operator << (C<T, Args...> const & objs)
  {
    std::cout << "[" << GetLabel(m_msgLevel) << "] ";

    for(auto const & obj:objs)
    {
      std::cout << obj << " ";
    }
    m_isOpened = true;
    return *this;
  }

private:
  bool m_isOpened = false;
  TypeLog m_msgLevel = TypeLog::DEBUG;
  std::string GetLabel(TypeLog const & type) const;
};
