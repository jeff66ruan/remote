/** \file
 * Copyright:
 *
 * Description: The menu is a tree
 *
 *
 */

#ifndef D_menu_H
#define D_menu_H

#include <stdbool.h>

typedef struct menu_type {
  const char *text;
  struct menu_type *parent, *child, *right, *left;
  void (*onRight)(struct menu_type** menu);
  void (*onLeft)(struct menu_type** menu);
  void (*onUp)(struct menu_type** menu);
  void (*onDown)(struct menu_type** menu);
  void (*onDisplay)(struct menu_type* menu);
} menu_t;

/**
 * initiliaze a menu node to the default
 * @param menu an unintialized menu node, will be initialized to the default
 * @param text a text describing the menu
 * after the return
 */
extern void menuInit(menu_t *menu, const char *text);

/**
 * Insert the new menu node as the tail sibling of the existing menu node
 * @param menu the existing menu node
 * @param newMenu the new menu node to be inserted
 */
extern void menuInsertTail(menu_t *menu, menu_t *newMenu);

/**
 * Insert the child menu node as the tail child of the parent menu node
 * @param parent the parent menu node
 * @param child the child menu node
 */
extern void menuInsertChildTail(menu_t *parent, menu_t *child);

/**
 * It returns the pointer of the input menu node's child menu node
 * @param menu the input menu node
 * @return the pointer of the input menu node's child menu node,
 * NULL if the input menu node hasn't any child
 */
extern menu_t*  menuChild(menu_t *menu);

/**
 * It returns the pointer of the input menu node's parent menu node
 * @param menu the input menu node
 * @return the pointer of the input menu node's parent menu node,
 * NULL if the input menu node hasn't a parent
 */
extern menu_t*  menuParent(menu_t *menu);

/**
 * It returns the pointer of the input menu node's right sibling menu node
 * @param menu the input menu node
 * @return the pointer of the input menu node's right sibling menu node,
 * NULL if the input menu node hasn't a right sibling
 */
extern menu_t*  menuRight(menu_t *menu);

/**
 * It returns the pointer of the input menu node's left sibling menu node
 * @param menu the input menu node
 * @return the pointer of the input menu node's left sibling menu node,
 * NULL if the input menu node hasn't a left sibling
 */
extern menu_t*  menuLeft(menu_t *menu);

#endif
