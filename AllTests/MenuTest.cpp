#include "CppUTest/TestHarness.h"

extern "C" {
#include "menu.h"
}

TEST_GROUP(MENU)
{
  void setup()
  {
  }
  void teardown()
  {

  }
};

TEST(MENU, AMenuHavingOneSubMenuIsCreated)
{
  menu_t menu_0;
  menu_t menu_0_0;

  menuInit(&menu_0, "");
  menuInit(&menu_0_0, "");
  menuInsertChildTail(&menu_0, &menu_0_0);
  POINTERS_EQUAL(&menu_0_0, menuChild(&menu_0));
  POINTERS_EQUAL(&menu_0, menuParent(&menu_0_0));
}

TEST(MENU, AMenuHavingTwoSubMenusIsCreated)
{
  menu_t menu_0;
  menu_t menu_0_0;
  menu_t menu_0_1;

  menuInit(&menu_0, "");
  menuInit(&menu_0_0, "");
  menuInit(&menu_0_1, "");
  menuInsertChildTail(&menu_0, &menu_0_0);
  menuInsertChildTail(&menu_0, &menu_0_1);
  POINTERS_EQUAL(&menu_0_0, menuChild(&menu_0));
  POINTERS_EQUAL(&menu_0, menuParent(&menu_0_0));
  POINTERS_EQUAL(&menu_0, menuParent(&menu_0_1));
  POINTERS_EQUAL(&menu_0_1, menuRight(&menu_0_0));
  POINTERS_EQUAL(NULL, menuRight(&menu_0_1));
  POINTERS_EQUAL(&menu_0_0, menuLeft(&menu_0_1));
  POINTERS_EQUAL(NULL, menuLeft(&menu_0_0));
}

TEST(MENU, MenuOnActionsSuccessfully)
{
  menu_t menu_0;
  menu_t menu_0_0;
  menu_t menu_0_1;
  menu_t action_0_0;
  menu_t action_0_1;
  menu_t *pcur;
  // form a menu structure
  menuInit(&menu_0, "");
  menuInit(&menu_0_0,"");
  menuInit(&menu_0_1, "");
  menuInsertChildTail(&menu_0, &menu_0_0);
  menuInsertChildTail(&menu_0, &menu_0_1);
  menuInsertChildTail(&menu_0_0, &action_0_0);
  menuInsertChildTail(&menu_0_1, &action_0_1);

  // simulate the operation
  // operations on the root
  pcur = &menu_0;
  pcur->onRight(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onLeft(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onUp(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onDown(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);

  // operations on the second level menu
  pcur->onLeft(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);
  pcur->onRight(&pcur);
  POINTERS_EQUAL(&menu_0_1, pcur);
  pcur->onRight(&pcur);
  POINTERS_EQUAL(&menu_0_1, pcur);
  pcur->onLeft(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);
  pcur->onUp(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
}
