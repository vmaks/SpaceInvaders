#include "list"
#include "gtest/gtest.h"

#include "logger.hpp"
#include "alien.hpp"
#include "space_ship.hpp"
#include "obstacle.hpp"
#include "bullet_manager.hpp"
#include "space.hpp"


TEST(logger_test, logger_1)
{
  Logger::SetLevel(LogLevel::trace);

  Logger::GetLogger(LogLevel::trace) << "trace\n";

  Logger::GetLogger(LogLevel::debug) << "debug\n";

  Logger::GetLogger(LogLevel::info) << "info\n";

  Logger::GetLogger(LogLevel::warning) << "warning\n";

  Logger::GetLogger(LogLevel::fatal) << "fatal\n";
}

TEST(logger_test, logger_2)
{
  Logger::SetLevel(LogLevel::info);

  Logger::GetLogger(LogLevel::trace) << "trace\n";

  Logger::GetLogger(LogLevel::debug) << "debug\n";

  Logger::GetLogger(LogLevel::info) << "info\n";

  Logger::GetLogger(LogLevel::warning) << "warning\n";

  Logger::GetLogger(LogLevel::fatal) << "fatal\n";
}

TEST(logger_test, logger_3)
{
  Logger::SetLevel(LogLevel::fatal);

  Logger::GetLogger(LogLevel::trace) << "trace\n";

  Logger::GetLogger(LogLevel::debug) << "debug\n";

  Logger::GetLogger(LogLevel::info) << "info\n";

  Logger::GetLogger(LogLevel::warning) << "warning\n";

  Logger::GetLogger(LogLevel::fatal) << "fatal\n";
}

TEST(logger_test, logger_4)
{
  Logger::SetLevel(LogLevel::info);

  Logger::GetLogger(LogLevel::fatal) << "info" << " warning" << " fatal\n";
}

TEST(logger_test, logger_5)
{
  Logger::SetLevel(LogLevel::info);

  Logger::GetLogger(LogLevel::info) << 5 << "\n";
  Logger::GetLogger(LogLevel::info) << std::list<int>{2, 3, 4} << "\n";;
  Logger::GetLogger(LogLevel::info) << std::vector<Bullet>(3, Bullet()) << "\n";;
  Logger::GetLogger(LogLevel::info) << Alien() << SpaceShip() << Space(15, 14) << "\n";;
  Logger::GetLogger(LogLevel::info) << Alien() << SpaceShip() << Space(15, 14) << "\n";;
}

TEST(logger_test, logger_6)
{
  Logger::SetLevel(LogLevel::info);

  Logger::Log(LogLevel::trace, "Hello");
  Logger::Log(LogLevel::fatal, "World");
}
