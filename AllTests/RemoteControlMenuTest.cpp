#include "CppUTest/TestHarness.h"

extern "C" {
#include "remoteControlMenu.h"
#include "volume.h"
#include "opmode.h"
#include "bright.h"
#include "channel.h"
}

TEST_GROUP(REMOTECONTROLMENU)
{
  void setup()
  {
  }
  void teardown()
  {

  }
};

TEST(REMOTECONTROLMENU, MovingOnRemoteControlMenuSuccessfully)
{
  menu_t *cur = NULL;

  remoteControlMenuInit();
  remoteControlMenuDisplay();

  // move to next menu node
  cur = remoteControlMenuCurrent();
  remoteControlMenuNext();
  POINTERS_EQUAL(menuNext(cur), remoteControlMenuCurrent());
  remoteControlMenuDisplay();

  // move back to original menu node
  remoteControlMenuPrev();
  POINTERS_EQUAL(cur, remoteControlMenuCurrent());

  // move to the action node of volume
  remoteControlMenuDown();
  remoteControlMenuDisplay();
  POINTERS_EQUAL(cur->child, remoteControlMenuCurrent());
}

TEST(REMOTECONTROLMENU, VolumeActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of volume
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  volumeReset();
  remoteControlMenuNext();
  LONGS_EQUAL(11, volumeRead());
  remoteControlMenuPrev();
  LONGS_EQUAL(10, volumeRead());
}

TEST(REMOTECONTROLMENU, BrightActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of brightness
  remoteControlMenuNext();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  brightReset();
  remoteControlMenuNext();
  LONGS_EQUAL(51, brightRead());
  remoteControlMenuPrev();
  LONGS_EQUAL(50, brightRead());
}

TEST(REMOTECONTROLMENU, ChannelActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of brightness
  remoteControlMenuNext();
  remoteControlMenuNext();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  channelReset();
  remoteControlMenuNext();
  LONGS_EQUAL(4, channelRead());
  remoteControlMenuPrev();
  LONGS_EQUAL(3, channelRead());
}

TEST(REMOTECONTROLMENU, OpModeActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of operating mode
  remoteControlMenuNext();
  remoteControlMenuNext();
  remoteControlMenuNext();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  opmodeReset();
  remoteControlMenuNext();
  CHECK(opmodeRead());
  remoteControlMenuPrev();
  CHECK(!opmodeRead());
}
