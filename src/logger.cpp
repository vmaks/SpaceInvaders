#include "logger.hpp"
#include "except.hpp"


// Set default values.
LogLevel Logger::m_msgLevel = LogLevel::info;

bool Logger::m_isPrint = false;
bool Logger::m_isPrintFunctionName = false;
bool Logger::m_isPrintLineNumber = false;
bool Logger::m_isPrintFileName = false;

std::string Logger::GetLogLevelAsString(LogLevel const &type)
{
  std::string label;
  switch(type)
  {
    case LogLevel::trace:
      label = "trace";
      break;
    case LogLevel::debug:
      label = "debug";
      break;
    case LogLevel::info:
      label = "info";
      break;
    case LogLevel::warning:
      label = "warning";
      break;
    case LogLevel::error:
      label = "error";
      break;
    case LogLevel::fatal:
      label = "fatal";
      break;
    default:
      throw WrongLogLevelException();
  }
  return label;
}
