#pragma once

#include <iostream>
#include <exception>


class NotImplementedException : public std::exception
{
public:
  virtual const char* what() const throw();
};