#include "CppUTest/TestHarness.h"

extern "C" {
#include "bright.h"
}

TEST_GROUP(BRIGHT)
{
  void setup()
  {
    brightReset();
  }
  void teardown()
  {

  }
};

TEST(BRIGHT, BrightHasDefaultValue50)
{
  LONGS_EQUAL(50, brightRead());
}

TEST(BRIGHT, BrightIsIncreasedbyOneSuccessfully)
{
  LONGS_EQUAL(51, brightRight());
  LONGS_EQUAL(52, brightRight());
}

TEST(BRIGHT, BrightIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(49, brightLeft());
  LONGS_EQUAL(48, brightLeft());
}

TEST(BRIGHT, BrightIsAlwaysInTheRangeOf0to100)
{
  int i;
  for (i = 0; i <100; i++) brightRight();
  LONGS_EQUAL(100, brightRead());


  for (i = 0; i <100; i++) brightLeft();
  LONGS_EQUAL(0, brightRead());
}
