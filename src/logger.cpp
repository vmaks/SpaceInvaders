#include "logger.h"

Logger::Logger(typelog const & type)
{
  msglevel = type;
  std::cout << "[" << getLabel(type) << "] ";
}

Logger::~Logger()
{
  if(opened)
  {
    std::cout << std::endl;
  }
  opened = false;
}

std::string Logger::getLabel(typelog const & type) const
{
  std::string label;
  switch(type)
  {
    case DEBUG:
      label = "DEBUG";
      break;
    case INFO:
      label = "INFO";
      break;
    case WARN:
      label = "WARNING";
      break;
    case ERROR:
      label = "ERROR";
      break;
  }
  return label;
}
