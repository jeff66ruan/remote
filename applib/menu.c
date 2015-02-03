#include "menu.h"
#include <stdio.h>

static bool menuHasChild(menu_t *menu);
static void defaultOnNext(menu_t **menu);
static void defaultOnPrev(menu_t **menu);
static void defaultOnUp(menu_t **menu);
static void defaultOnDown(menu_t **menu);

static void defaultOnNext(menu_t **menu)
{
  if ((*menu)->next)
    *menu = (*menu)->next;
}

static void defaultOnPrev(menu_t **menu)
{
  if ((*menu)->prev)
    *menu = (*menu)->prev;
}

static void defaultOnUp(menu_t **menu)
{
  if ((*menu)->parent)
    *menu = (*menu)->parent;
}

static void defaultOnDown(menu_t **menu)
{
  if (menuHasChild(*menu))
    *menu = menuChild(*menu);
}

static void defaultOnDisplay(menu_t *menu)
{
  printf("%s\n", menu->text);
}

void menuInit(menu_t *menu, const char *text)
{
  menu->text = text;
  menu->child = NULL;
  menu->parent = NULL;
  menu->next = NULL;
  menu->prev = NULL;
  menu->onNext = defaultOnNext;
  menu->onPrev = defaultOnPrev;
  menu->onUp = defaultOnUp;
  menu->onDown = defaultOnDown;
  menu->onDisplay = defaultOnDisplay;
}

/**
 * Checks if the menu node has child menus
 * @param menu the menu node to be checked
 * @return true if the menu node has at least one child menu, otherwise false
 */
static bool menuHasChild(menu_t *menu)
{
  return menu->child != NULL;
}

void menuInsertTail(menu_t *menu, menu_t *newMenu)
{
  menu_t *cur = menu;
  while(cur->next) cur = cur->next;
  cur->next = newMenu;
  newMenu->prev = cur;
  newMenu->next = NULL;
  newMenu->parent = menu->parent;
  /* no change to child because a series of menu can be insert */
}

void menuInsertChildTail(menu_t *parent, menu_t *child)
{
  if (!menuHasChild(parent)) {
    parent->child = child;
    child->parent = parent;
    child->next = NULL;
    child->prev = NULL;
  } else {
    menuInsertTail(parent->child, child);
  }
}

menu_t*  menuChild(menu_t *menu)
{
  return menu->child;
}

menu_t*  menuParent(menu_t *menu)
{
  return menu->parent;
}

menu_t*  menuNext(menu_t *menu)
{
  return menu->next;
}

menu_t*  menuPrev(menu_t *menu)
{
  return menu->prev;
}
