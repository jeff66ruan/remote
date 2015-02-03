/**
 * Copyright:
 *
 * This demos a 2 button remote control for a TV
 *
 * */

#include <stdio.h>
#include "remoteControlMenu.h"

#define BUTTON_LEFT 108         /* lowcase letter l */
#define BUTTON_RIGHT 114        /* lowcase letter r */
#define BUTTON_UP 117           /* lowcase letter u */
#define BUTTON_DOWN 100         /* lowcase letter d */
#define BUTTON_RETURN 10

/* at the beginning I use four buttons in order to finish the whole
   application framework. Changing back to two buttons shouldn't
   affect underlining structure except the way of interpreting
   button behaviours */
static int buttonAction(void)
{
  return getchar();
}

int main()
{
  char ch;

  remoteControlMenuInit();
  remoteControlMenuDisplay();

  while ((ch=buttonAction())) {
    switch(ch) {
    case BUTTON_LEFT:
      remoteControlMenuPrev();
      break;
    case BUTTON_RIGHT:
      remoteControlMenuNext();
      break;
    case BUTTON_UP:
      remoteControlMenuUp();
      break;
    case BUTTON_DOWN:
      remoteControlMenuDown();
      break;
    case BUTTON_RETURN:
      continue;   /* special here because don't want to display menu */
    default:
      printf("Invalid button\n");
      break;
    }
    remoteControlMenuDisplay();
  }
  return 0;
}
