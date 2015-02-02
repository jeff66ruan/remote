#include "CppUTest/TestHarness.h"

extern "C" {
#include "hardware.h"
}

TEST_GROUP(HARDWARE)
{
  void setup()
  {

  }
  void teardown()
  {

  }
};

TEST(HARDWARE, VolumeHasDefaultValue10)
{
  LONGS_EQUAL(10, volumeRead());
  // volumeReset();
  // LONGS_EQUAL(10, volumeRead());
}
