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

extern void remoteControlMenuInit(void);

extern void remoteControlMenuDisplay(void);

extern void remoteControlMenuNext(void);

extern void remoteControlMenuPrev(void);

extern void remoteControlMenuDown(void);

extern void remoteControlMenuUp(void);

extern menu_t* remoteControlMenuCurrent(void);

#endif
