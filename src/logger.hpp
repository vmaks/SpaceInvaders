#pragma once

#include <iostream>


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
  static Logger & GetLogger(LogLevel level)
  {
    static Logger logger;

    if (level >= m_msgLevel)
    {
      m_isPrint = true;

      std::cout << "[" << GetLogLevelAsString(m_msgLevel) << "] ";
    }
    else {
      m_isPrint = false;
    }

    return logger;
  }

  /// Set the current log level.
  static void SetLevel(LogLevel const & type)
  {
    m_msgLevel = type;
  }

  /// Get the current log level.
  static std::string GetLogLevelAsString(LogLevel const &type);

  /// It simply output a message with a log level.
  static void Log(LogLevel const & logLevel,
                  std::string const & message)
  {
    if (logLevel >= m_msgLevel)
    {
      std::cout << message << std::endl;
    }
  }

  static LogLevel GetLogLevel()
  {
    return m_msgLevel;
  }

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

  static bool m_isPrint;
};
