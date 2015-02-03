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
  POINTERS_EQUAL(&menu_0_1, menuNext(&menu_0_0));
  POINTERS_EQUAL(NULL, menuNext(&menu_0_1));
  POINTERS_EQUAL(&menu_0_0, menuPrev(&menu_0_1));
  POINTERS_EQUAL(NULL, menuPrev(&menu_0_0));
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
  pcur->onNext(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onPrev(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onUp(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
  pcur->onDown(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);

  // operations on the second level menu
  pcur->onPrev(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);
  pcur->onNext(&pcur);
  POINTERS_EQUAL(&menu_0_1, pcur);
  pcur->onNext(&pcur);
  POINTERS_EQUAL(&menu_0_1, pcur);
  pcur->onPrev(&pcur);
  POINTERS_EQUAL(&menu_0_0, pcur);
  pcur->onUp(&pcur);
  POINTERS_EQUAL(&menu_0, pcur);
}
