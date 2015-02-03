#include "remoteControlMenu.h"
#include "menu.h"
#include "volume.h"
#include "opmode.h"
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

  /* operation mode */
  menuInit(&levelOne[1], "Operating mode - On/Standby");
  menuInsertChildTail(&root, &levelOne[1]);
  menuInit(&actions[1], "Press Left and Right to Change Operating mode");
  actions[1].onNext = opmodeActionOnNext;
  actions[1].onPrev = opmodeActionOnPrev;
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
