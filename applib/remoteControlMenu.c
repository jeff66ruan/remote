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

static void volumeActionOnNext(menu_t **menu);
static void volumeActionOnPrev(menu_t **menu);
static void opmodeActionOnNext(menu_t **menu);
static void opmodeActionOnPrev(menu_t **menu);
static void brightActionOnNext(menu_t **menu);
static void brightActionOnPrev(menu_t **menu);
static void channelActionOnNext(menu_t **menu);
static void channelActionOnPrev(menu_t **menu);

static void volumeActionOnNext(menu_t **menu)
{
  assert(menu);
  printf("Volume is %d\n", volumeNext());
}

static void volumeActionOnPrev(menu_t **menu)
{
  assert(menu);
  printf("Volume is %d\n", volumePrev());
}

static void opmodeActionOnNext(menu_t **menu)
{
  assert(menu);
  if (opmodeNext()) {
    printf("TV is on\n");
  } else {
    printf("TV is off\n");
  }
}

static void opmodeActionOnPrev(menu_t **menu)
{
  assert(menu);
  if (opmodePrev()) {
    printf("TV is on\n");
  } else {
    printf("TV is off\n");
  }
}

static void brightActionOnNext(menu_t **menu)
{
  assert(menu);
  printf("Brightness is %d\n", brightNext());
}

static void brightActionOnPrev(menu_t **menu)
{
  assert(menu);
  printf("Brightness is %d\n", brightPrev());
}

static void channelActionOnNext(menu_t **menu)
{
  assert(menu);
  printf("Channel is %d\n", channelNext());
}

static void channelActionOnPrev(menu_t **menu)
{
  assert(menu);
  printf("Channel is %d\n", channelPrev());
}

void remoteControlMenuInit(void)
{
  menuInit(&root, "Select to enter the menu");

  /* volume */
  menuInit(&levelOne[0], "Volume - 0 to 40");
  menuInsertChildTail(&root, &levelOne[0]);
  menuInit(&actions[0], "Press Left and Right to Change Volume");
  actions[0].onNext = volumeActionOnNext;
  actions[0].onPrev = volumeActionOnPrev;
  menuInsertChildTail(&levelOne[0], &actions[0]);

  /* Bright */
  menuInit(&levelOne[1], "Brightness - 0 to 100%");
  menuInsertChildTail(&root, &levelOne[1]);
  menuInit(&actions[1], "Press Left and Right to Change Brightness");
  actions[1].onNext = brightActionOnNext;
  actions[1].onPrev = brightActionOnPrev;
  menuInsertChildTail(&levelOne[1], &actions[1]);

  /* channel */
  menuInit(&levelOne[2], "Channel - 1 to 5");
  menuInsertChildTail(&root, &levelOne[2]);
  menuInit(&actions[2], "Press Left and Right to Change Channel");
  actions[2].onNext = channelActionOnNext;
  actions[2].onPrev = channelActionOnPrev;
  menuInsertChildTail(&levelOne[2], &actions[2]);

  /* operation mode */
  menuInit(&levelOne[3], "Operating mode - On/Standby");
  menuInsertChildTail(&root, &levelOne[3]);
  menuInit(&actions[3], "Press Left and Right to Change Operating mode");
  actions[3].onNext = opmodeActionOnNext;
  actions[3].onPrev = opmodeActionOnPrev;
  menuInsertChildTail(&levelOne[3], &actions[3]);

  pcurMenu = &levelOne[0];
}

static menu_t* remoteControlMenuFirst(menu_t *menu)
{
  while(menu->prev) menu = menu->prev;
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
    iter = iter->next;
  }
  printf("Press the button: ");
}

void remoteControlMenuNext(void)
{
  pcurMenu->onNext(&pcurMenu);
}

void remoteControlMenuPrev(void)
{
  pcurMenu->onPrev(&pcurMenu);
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
