#include "CppUTest/TestHarness.h"

extern "C" {
#include "opmode.h"
}

TEST_GROUP(OPMODE)
{
  void setup()
  {
    opmodeReset();
  }
  void teardown()
  {

  }
};

TEST(OPMODE, operationModeHasDefaultValueFalse)
{
  LONGS_EQUAL(false, opmodeRead());
}

TEST(OPMODE, OperationModeIsTurnedOnAndOffSuccessfully)
{
  LONGS_EQUAL(false, opmodeRead());
  LONGS_EQUAL(true, opmodeNext());
  LONGS_EQUAL(false, opmodeNext());
  LONGS_EQUAL(true, opmodePrev());
  LONGS_EQUAL(false, opmodePrev());
}
