#pragma once

#include <iostream>


/// Log level.
enum class TypeLog
{
  DEBUG,
  INFO,
  WARN,
  ERROR
};


/// It is used to output information to the screen or a file.
class Logger
{
public:
  Logger() = default;

  Logger(TypeLog const & type);

  ~Logger();

  /// Output an object to the screen.
  template<class T>
  Logger & operator << (T const & obj)
  {
    std::cout << "[" << GetLabel(m_msgLevel) << "] " << obj;
    m_isOpened = true;
    return *this;
  }

  /// Output a collection of objects to the screen.
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
  /// It is used to output buffer to the screen
  /// when the Logger is destroyed.
  bool m_isOpened = false;

  /// It is used to store the current log level.
  TypeLog m_msgLevel = TypeLog::DEBUG;

  /// Get the current log level.
  std::string GetLabel(TypeLog const & type) const;
};
