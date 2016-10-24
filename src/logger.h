#pragma once

#include <iostream>

enum typelog
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

  Logger(typelog const & type);

  ~Logger();

  template<class T>
  Logger & operator << (T const & obj)
  {
    std::cout << obj;
    opened = true;
    return *this;
  }

  template<typename T, template<typename,typename...> class C, typename... Args>
  Logger & operator << (C<T, Args...> const & objs)
  {
    for(auto const & obj:objs)
      std::cout << obj << " ";
    opened = true;
    return *this;
  }

private:
  bool opened = false;
  typelog msglevel = DEBUG;
  std::string getLabel(typelog const & type) const;
};
