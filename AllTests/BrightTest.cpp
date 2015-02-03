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
  LONGS_EQUAL(51, brightNext());
  LONGS_EQUAL(52, brightNext());
}

TEST(BRIGHT, BrightIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(49, brightPrev());
  LONGS_EQUAL(48, brightPrev());
}

TEST(BRIGHT, BrightIsAlwaysInTheRangeOf0to100)
{
  int i;
  for (i = 0; i <100; i++) brightNext();
  LONGS_EQUAL(100, brightRead());


  for (i = 0; i <100; i++) brightPrev();
  LONGS_EQUAL(0, brightRead());
}
