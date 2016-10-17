#include "except.hpp"


const char* NotImplementedException::what() const throw()
{
  return "Not implemented";
}