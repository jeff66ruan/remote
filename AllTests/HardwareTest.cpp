#include "CppUTest/TestHarness.h"

extern "C" {
#include "hardware.h"
}

TEST_GROUP(HARDWARE)
{
  void setup()
  {
    volumeReset();
    opmodeReset();
  }
  void teardown()
  {

  }
};

TEST(HARDWARE, VolumeHasDefaultValue10)
{
  LONGS_EQUAL(10, volumeRead());
}

TEST(HARDWARE, VolumeIsIncreasedbyOneSuccessfully)
{
  LONGS_EQUAL(11, volumeNext());
  LONGS_EQUAL(12, volumeNext());
}

TEST(HARDWARE, VolumeIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(9, volumePrev());
  LONGS_EQUAL(8, volumePrev());
}

TEST(HARDWARE, VolumeIsAlwaysInTheRangeOf0to40)
{
  int i;
  for (i = 0; i <100; i++) volumeNext();
  LONGS_EQUAL(40, volumeRead());


  for (i = 0; i <100; i++) volumePrev();
  LONGS_EQUAL(0, volumeRead());
}

TEST(HARDWARE, operationModeHasDefaultValueFalse)
{
  LONGS_EQUAL(false, opmodeRead());
}

TEST(HARDWARE, OperationModeIsTurnedOnAndOffSuccessfully)
{
  LONGS_EQUAL(false, opmodeRead());
  LONGS_EQUAL(true, opmodeNext());
  LONGS_EQUAL(false, opmodeNext());
  LONGS_EQUAL(true, opmodePrev());
  LONGS_EQUAL(false, opmodePrev());
}
