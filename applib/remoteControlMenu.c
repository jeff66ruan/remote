#include "remoteControlMenu.h"
#include "menu.h"

#define LEVEL_ONE_AMOUNT 4

static menu_t root;
static menu_t levelOne[LEVEL_ONE_AMOUNT];
static menu_t actions[LEVEL_ONE_AMOUNT];

static menu_t *pcurMenu = NULL;



void remoteControlMenuInit(void)
{
  menuInit(&root, "Select to enter the menu");

  /* volume */
  menuInit(&levelOne[0], "Volume - 0 to 40");
  menuInsertChildTail(&root, &levelOne[0]);
  menuInit(&actions[0], "Press Up and Down to Change Volume");
  menuInsertChildTail(&levelOne[0], &actions[0]);

  /* operation mode */
  menuInit(&levelOne[1], "Operating mode - On/Standby");
  menuInsertChildTail(&root, &levelOne[1]);
  menuInit(&actions[1], "Press Up and Down to Change Operating mode");
  menuInsertChildTail(&levelOne[1], &actions[1]);

  pcurMenu = &levelOne[0];
}

static menu_t* remoteControlMenuFirst(menu_t *menu)
{
  while(menu->prev) menu = menu->prev;
  return menu;
}

void remoteControlMenuDisplay(void)
{
  menu_t *iter = remoteControlMenuFirst(pcurMenu);
  while(iter) {
    iter->onDisplay(iter);
    iter = iter->next;
  }
}
