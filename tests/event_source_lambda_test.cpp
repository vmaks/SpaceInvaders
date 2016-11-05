#include <logger.hpp>
#include "gtest/gtest.h"
#include "event_source_lambda.h"

TEST(event_source_lambda_test, test_lambda_register_listener)
{
  EventSourceLambda eventSource;

  eventSource.RegisterListener([]{});

  EXPECT_EQ(eventSource.Count(), 1);
}

TEST(event_source_lambda_test, test_notify_1)
{
  EventSourceLambda eventSource;

  eventSource.RegisterListener([]{
    std::cout << "Notify from lambda!" << "\n";
  });

  EXPECT_EQ(eventSource.Count(), 1);
}

TEST(event_source_lambda_test, test_notify_2)
{
  EventSourceLambda eventSource;

  eventSource.RegisterListener([]{
    Logger::Instance(LogLevel::info) << "Notify from lambda 1!" << "\n"; });

  eventSource.RegisterListener([]{
    Logger::Instance(LogLevel::info) << "Notify from lambda 2!" << "\n"; });

  EXPECT_EQ(eventSource.Count(), 2);
}