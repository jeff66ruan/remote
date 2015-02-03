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
  LONGS_EQUAL(4, channelNext());
  LONGS_EQUAL(5, channelNext());
}

TEST(CHANNEL, ChannelIsDecreasedbyOneSuccessfully)
{
  LONGS_EQUAL(2, channelPrev());
  LONGS_EQUAL(1, channelPrev());
}

TEST(CHANNEL, ChannelIsAlwaysInTheRangeOf1to5)
{
  int i;
  for (i = 0; i <100; i++) channelNext();
  LONGS_EQUAL(5, channelRead());


  for (i = 0; i <100; i++) channelPrev();
  LONGS_EQUAL(1, channelRead());
}
