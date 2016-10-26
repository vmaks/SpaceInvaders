#include "logger.hpp"
#include "except.hpp"


// Set default values.
LogLevel Logger::m_msgLevel = LogLevel::info;

bool Logger::m_isPrint = false;
bool Logger::m_isPrintFunctionName = false;
bool Logger::m_isPrintLineNumber = false;
bool Logger::m_isPrintFileName = false;

Logger & Logger::GetLogger(LogLevel level,
                          std::string const & functionName,
                          std::string lineNumber,
                          std::string const & fileName)
{
  static Logger logger;

  if (level >= m_msgLevel)
  {
    m_isPrint = true;

    PrintAdditionalParameters(functionName, lineNumber, fileName);
  }
  else {
    m_isPrint = false;
  }

  return logger;
}

void Logger::SetLogLevel(LogLevel const &type)
{
  m_msgLevel = type;
}

void Logger::SetPrintFunctionName(bool const &isPrintFunctionName)
{
  m_isPrintFunctionName = isPrintFunctionName;
}

void Logger::SetPrintLineNumber(bool const & isPrintLineNumber)
{
  m_isPrintLineNumber = isPrintLineNumber;
}

void Logger::SetPrintFileName(bool const & isPrintFileName)
{
  m_isPrintFileName = isPrintFileName;
}

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

void Logger::PrintAdditionalParameters(
    std::string const & functionName,
    std::string lineNumber,
    std::string const & fileName)
{
  std::cout << "[" << GetLogLevelAsString(m_msgLevel) << "] ";

  if (m_isPrintFunctionName)
  {
    std::cout << functionName;
    std::cout << " | ";
  }
  if (m_isPrintLineNumber)
  {
    std::cout << lineNumber;
    std::cout << " | ";
  }
  if (m_isPrintFileName)
  {
    std::cout << fileName;
    std::cout << " | ";
  }
}

void Logger::Log(LogLevel const & logLevel,
                std::string const & message,
                std::string const & functionName,
                std::string lineNumber,
                std::string const & fileName)
{
  if (logLevel >= m_msgLevel)
  {
    PrintAdditionalParameters(
        functionName, lineNumber, fileName);

    std::cout << message << std::endl;
  }
}

LogLevel Logger::GetLogLevel()
{
  return m_msgLevel;
}