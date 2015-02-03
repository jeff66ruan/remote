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
  LONGS_EQUAL(11, volumeNext());
  LONGS_EQUAL(12, volumeNext());
}

TEST(VOLUME, VolumeIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(9, volumePrev());
  LONGS_EQUAL(8, volumePrev());
}

TEST(VOLUME, VolumeIsAlwaysInTheRangeOf0to40)
{
  int i;
  for (i = 0; i <100; i++) volumeNext();
  LONGS_EQUAL(40, volumeRead());


  for (i = 0; i <100; i++) volumePrev();
  LONGS_EQUAL(0, volumeRead());
}
