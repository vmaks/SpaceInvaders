#include "except.hpp"


const char* NotImplementedException::what() const noexcept
{
  return "Not implemented!";
}

const char* WrongLogLevelException::what() const noexcept
{
  return "Wrong log level!";
}
