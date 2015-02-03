#include "remoteControlMenu.h"
#include "menu.h"
#include "volume.h"
#include "opmode.h"
#include "bright.h"
#include "channel.h"
#include <stdio.h>
#include <assert.h>

#define LEVEL_ONE_AMOUNT 4

static menu_t root;
static menu_t levelOne[LEVEL_ONE_AMOUNT];
static menu_t actions[LEVEL_ONE_AMOUNT];

static menu_t *pcurMenu = NULL;

static void volumeActionOnRight(menu_t **menu);
static void volumeActionOnLeft(menu_t **menu);
static void opmodeActionOnRight(menu_t **menu);
static void opmodeActionOnLeft(menu_t **menu);
static void brightActionOnRight(menu_t **menu);
static void brightActionOnLeft(menu_t **menu);
static void channelActionOnRight(menu_t **menu);
static void channelActionOnLeft(menu_t **menu);

static void volumeActionOnRight(menu_t **menu)
{
  assert(menu);
  printf("Volume is %d\n", volumeRight());
}

static void volumeActionOnLeft(menu_t **menu)
{
  assert(menu);
  printf("Volume is %d\n", volumeLeft());
}

static void opmodeActionOnRight(menu_t **menu)
{
  assert(menu);
  if (opmodeRight()) {
    printf("TV is on\n");
  } else {
    printf("TV is off\n");
  }
}

static void opmodeActionOnLeft(menu_t **menu)
{
  assert(menu);
  if (opmodeLeft()) {
    printf("TV is on\n");
  } else {
    printf("TV is off\n");
  }
}

static void brightActionOnRight(menu_t **menu)
{
  assert(menu);
  printf("Brightness is %d\n", brightRight());
}

static void brightActionOnLeft(menu_t **menu)
{
  assert(menu);
  printf("Brightness is %d\n", brightLeft());
}

static void channelActionOnRight(menu_t **menu)
{
  assert(menu);
  printf("Channel is %d\n", channelRight());
}

static void channelActionOnLeft(menu_t **menu)
{
  assert(menu);
  printf("Channel is %d\n", channelLeft());
}

void remoteControlMenuInit(void)
{
  menuInit(&root, "Select to enter the menu");

  /* volume */
  menuInit(&levelOne[0], "Volume - 0 to 40");
  menuInsertChildTail(&root, &levelOne[0]);
  menuInit(&actions[0], "Press Left and Right to Change Volume");
  actions[0].onRight = volumeActionOnRight;
  actions[0].onLeft = volumeActionOnLeft;
  menuInsertChildTail(&levelOne[0], &actions[0]);

  /* Bright */
  menuInit(&levelOne[1], "Brightness - 0 to 100%");
  menuInsertChildTail(&root, &levelOne[1]);
  menuInit(&actions[1], "Press Left and Right to Change Brightness");
  actions[1].onRight = brightActionOnRight;
  actions[1].onLeft = brightActionOnLeft;
  menuInsertChildTail(&levelOne[1], &actions[1]);

  /* channel */
  menuInit(&levelOne[2], "Channel - 1 to 5");
  menuInsertChildTail(&root, &levelOne[2]);
  menuInit(&actions[2], "Press Left and Right to Change Channel");
  actions[2].onRight = channelActionOnRight;
  actions[2].onLeft = channelActionOnLeft;
  menuInsertChildTail(&levelOne[2], &actions[2]);

  /* operation mode */
  menuInit(&levelOne[3], "Operating mode - On/Standby");
  menuInsertChildTail(&root, &levelOne[3]);
  menuInit(&actions[3], "Press Left and Right to Change Operating mode");
  actions[3].onRight = opmodeActionOnRight;
  actions[3].onLeft = opmodeActionOnLeft;
  menuInsertChildTail(&levelOne[3], &actions[3]);

  pcurMenu = &levelOne[0];
}

static menu_t* remoteControlMenuFirst(menu_t *menu)
{
  while(menu->left) menu = menu->left;
  return menu;
}

void remoteControlMenuDisplay(void)
{
  printf("\n\n");
  menu_t *iter = remoteControlMenuFirst(pcurMenu);
  while(iter) {
    if (iter != pcurMenu) {
      printf("   ");
    } else {
      printf("-> ");
    }
    iter->onDisplay(iter);
    iter = iter->right;
  }
  printf("Press the button (l/r/u/d): ");
}

void remoteControlMenuRight(void)
{
  pcurMenu->onRight(&pcurMenu);
}

void remoteControlMenuLeft(void)
{
  pcurMenu->onLeft(&pcurMenu);
}

void remoteControlMenuDown(void)
{
  pcurMenu->onDown(&pcurMenu);
}

void remoteControlMenuUp(void)
{
  pcurMenu->onUp(&pcurMenu);
}

menu_t* remoteControlMenuCurrent(void)
{
  return pcurMenu;
}
