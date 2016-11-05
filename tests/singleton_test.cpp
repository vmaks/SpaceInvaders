#include "gtest/gtest.h"
#include "singleton.h"

TEST(singleton_test, test_instance)
{
  class A
  {
   public:
    int a = 10;
  };

  A const & instance_1 = Singleton<A>::Instance();
  A const & instance_2 = Singleton<A>::Instance();

  EXPECT_EQ(instance_1.a, instance_2.a);
}