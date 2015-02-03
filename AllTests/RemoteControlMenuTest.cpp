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

  // move to right menu node
  cur = remoteControlMenuCurrent();
  remoteControlMenuRight();
  POINTERS_EQUAL(menuRight(cur), remoteControlMenuCurrent());
  remoteControlMenuDisplay();

  // move back to original menu node
  remoteControlMenuLeft();
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
  remoteControlMenuRight();
  LONGS_EQUAL(11, volumeRead());
  remoteControlMenuLeft();
  LONGS_EQUAL(10, volumeRead());
}

TEST(REMOTECONTROLMENU, BrightActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of brightness
  remoteControlMenuRight();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  brightReset();
  remoteControlMenuRight();
  LONGS_EQUAL(51, brightRead());
  remoteControlMenuLeft();
  LONGS_EQUAL(50, brightRead());
}

TEST(REMOTECONTROLMENU, ChannelActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of brightness
  remoteControlMenuRight();
  remoteControlMenuRight();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  channelReset();
  remoteControlMenuRight();
  LONGS_EQUAL(4, channelRead());
  remoteControlMenuLeft();
  LONGS_EQUAL(3, channelRead());
}

TEST(REMOTECONTROLMENU, OpModeActionsOnRemoteControlMenuIsDoneSuccessfully)
{
  remoteControlMenuInit();

  // move to the action node of operating mode
  remoteControlMenuRight();
  remoteControlMenuRight();
  remoteControlMenuRight();
  remoteControlMenuDown();
  remoteControlMenuDisplay();

  opmodeReset();
  remoteControlMenuRight();
  CHECK(opmodeRead());
  remoteControlMenuLeft();
  CHECK(!opmodeRead());
}
