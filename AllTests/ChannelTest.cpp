#include "CppUTest/TestHarness.h"

extern "C" {
#include "channel.h"
}

TEST_GROUP(CHANNEL)
{
  void setup()
  {
    channelReset();
  }
  void teardown()
  {

  }
};

TEST(CHANNEL, ChannelHasDefaultValue1)
{
  LONGS_EQUAL(3, channelRead());
}

TEST(CHANNEL, ChannelIsIncreasedbyOneSuccessfully)
{
  LONGS_EQUAL(4, channelRight());
  LONGS_EQUAL(5, channelRight());
}

TEST(CHANNEL, ChannelIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(2, channelLeft());
  LONGS_EQUAL(1, channelLeft());
}

TEST(CHANNEL, ChannelIsAlwaysInTheRangeOf1to5)
{
  int i;
  for (i = 0; i <100; i++) channelRight();
  LONGS_EQUAL(5, channelRead());


  for (i = 0; i <100; i++) channelLeft();
  LONGS_EQUAL(1, channelRead());
}
