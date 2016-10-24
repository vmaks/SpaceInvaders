#include "except.hpp"


const char* NotImplementedException::what() const noexcept
{
  return "Not implemented";
}