#include "CppUTest/TestHarness.h"

extern "C" {
#include "volume.h"
}

TEST_GROUP(VOLUME)
{
  void setup()
  {
    volumeReset();
  }
  void teardown()
  {

  }
};

TEST(VOLUME, VolumeHasDefaultValue10)
{
  LONGS_EQUAL(10, volumeRead());
}

TEST(VOLUME, VolumeIsIncreasedbyOneSuccessfully)
{
  LONGS_EQUAL(11, volumeRight());
  LONGS_EQUAL(12, volumeRight());
}

TEST(VOLUME, VolumeIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(9, volumeLeft());
  LONGS_EQUAL(8, volumeLeft());
}

TEST(VOLUME, VolumeIsAlwaysInTheRangeOf0to40)
{
  int i;
  for (i = 0; i <100; i++) volumeRight();
  LONGS_EQUAL(40, volumeRead());


  for (i = 0; i <100; i++) volumeLeft();
  LONGS_EQUAL(0, volumeRead());
}
