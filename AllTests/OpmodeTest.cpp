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
  LONGS_EQUAL(true, opmodeRight());
  LONGS_EQUAL(false, opmodeRight());
  LONGS_EQUAL(true, opmodeLeft());
  LONGS_EQUAL(false, opmodeLeft());
}
