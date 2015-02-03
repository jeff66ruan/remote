/** \file
 * Copyright:
 *
 * Description: A concrete implementation of remote control
 *
 *
 */

#ifndef D_remoteControlMenu_H
#define D_remoteControlMenu_H

#include <menu.h>

/**
 * It initializes a global concrete menu of remote control for the TV set
 */
extern void remoteControlMenuInit(void);

/**
 * It displays the current level of menu and hints users to give input
 */
extern void remoteControlMenuDisplay(void);

/**
 * It executes the current selected menu node's onNext action
 */
extern void remoteControlMenuNext(void);

/**
 * It executes the current selected menu node's onPrev action
 */
extern void remoteControlMenuPrev(void);

/**
 * It executes the current selected menu node's onDown action
 */
extern void remoteControlMenuDown(void);

/**
 * It executes the current selected menu node's onUp action
 */
extern void remoteControlMenuUp(void);


/**
 * It returns the current selected menu node
 * @return the pointer to the current selected menu node
 */
extern menu_t* remoteControlMenuCurrent(void);

#endif
