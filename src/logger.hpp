#pragma once

#include <iostream>


/// It is used to add function name, line number and file name if needed.
#define LOG(level) \
Logger::GetLogger(level, __func__, std::to_string(__LINE__), __FILE__)

/// It is used to add function name, line number and file name if needed.
#define LOG_MESSAGE(level, message) \
Logger::Log(level, message, __func__, std::to_string(__LINE__), __FILE__)


/// Log level.
enum class LogLevel
{
  trace,
  debug,
  info,
  warning,
  error,
  fatal
};


/// It is used to output information
/// to the screen or a file.
class Logger
{
public:
  static Logger & GetLogger(LogLevel level,
                            std::string const & functionName = "",
                            std::string lineNumber = "",
                            std::string const & fileName = "");

  /// Set the current log level.
  static void SetLogLevel(LogLevel const &type);

  /// Set output option.
  static void SetPrintFunctionName(bool const &isPrintFunctionName);

  /// Set output option.
  static void SetPrintLineNumber(bool const & isPrintLineNumber);

  /// Set output option.
  static void SetPrintFileName(bool const & isPrintFileName);

  /// Get the current log level.
  static std::string GetLogLevelAsString(LogLevel const &type);

  /// Output a function name, line number and file name if needed.
  static void PrintAdditionalParameters(
          std::string const & functionName,
          std::string lineNumber,
          std::string const & fileName);

  /// It simply output a message with a log level.
  static void Log(LogLevel const & logLevel,
                  std::string const & message,
                  std::string const & functionName = "",
                  std::string lineNumber = "",
                  std::string const & fileName = "");

  static LogLevel GetLogLevel();

  /// Output an object to the screen.
  template<class T>
  Logger & operator << (T const & obj)
  {
    if (m_isPrint)
    {
      std::cout << obj;
    }

    return *this;
  }

  /// Output a collection of objects to the screen.
  template<typename T, template<typename, typename...> class C, typename... Args>
  Logger & operator << (C<T, Args...> const & objs)
  {
    if (m_isPrint)
    {
      for (auto const & obj : objs)
      {
        std::cout << obj << " ";
      }
    }

    return *this;
  }

private:  
  Logger() = default;

  /// It is used to store the current log level.
  static LogLevel m_msgLevel;

  /// It is used to store the current output message flag.
  static bool m_isPrint;

  /// It is used to store the current output function name flag.
  static bool m_isPrintFunctionName;

  /// It is used to store the current output line numer flag.
  static bool m_isPrintLineNumber;

  /// It is used to store the current output file name flag.
  static bool m_isPrintFileName;
};
