#include "logger.h"

Logger::Logger(TypeLog const & type)
{
  m_msgLevel = type;
}

Logger::~Logger()
{
  if(m_isOpened)
  {
    std::cout << std::endl;
  }
  m_isOpened = false;
}

std::string Logger::GetLabel(TypeLog const & type) const
{
  std::string label;
  switch(type)
  {
    case TypeLog::DEBUG:
      label = "DEBUG";
      break;
    case TypeLog::INFO:
      label = "INFO";
      break;
    case TypeLog::WARN:
      label = "WARNING";
      break;
    case TypeLog::ERROR:
      label = "ERROR";
      break;
  }
  return label;
}
