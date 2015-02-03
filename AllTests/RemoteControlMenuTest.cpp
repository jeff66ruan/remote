#include "CppUTest/TestHarness.h"

extern "C" {
#include "remoteControlMenu.h"
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

TEST(REMOTECONTROLMENU, AEmptyMenuIsCreated)
{
  remoteControlMenuInit();
  remoteControlMenuDisplay();
  //remoteControlMenuNext();

}
