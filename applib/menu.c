#include "menu.h"
#include <stdio.h>

static bool menuHasChild(menu_t *menu);
static void defaultOnRight(menu_t **menu);
static void defaultOnLeft(menu_t **menu);
static void defaultOnUp(menu_t **menu);
static void defaultOnDown(menu_t **menu);

static void defaultOnRight(menu_t **menu)
{
  if ((*menu)->right)
    *menu = (*menu)->right;
}

static void defaultOnLeft(menu_t **menu)
{
  if ((*menu)->left)
    *menu = (*menu)->left;
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
  menu->right = NULL;
  menu->left = NULL;
  menu->onRight = defaultOnRight;
  menu->onLeft = defaultOnLeft;
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
  while(cur->right) cur = cur->right;
  cur->right = newMenu;
  newMenu->left = cur;
  newMenu->right = NULL;
  newMenu->parent = menu->parent;
  /* no change to child because a series of menu can be insert */
}

void menuInsertChildTail(menu_t *parent, menu_t *child)
{
  if (!menuHasChild(parent)) {
    parent->child = child;
    child->parent = parent;
    child->right = NULL;
    child->left = NULL;
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

menu_t*  menuRight(menu_t *menu)
{
  return menu->right;
}

menu_t*  menuLeft(menu_t *menu)
{
  return menu->left;
}
