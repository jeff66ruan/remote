/**
 * Copyright:
 *
 * This demos a 2 button remote control for a TV
 *
 * */

#include <stdio.h>

#define BUTTON_LEFT 108         /* lowcase letter l */
#define BUTTON_RIGHT 114        /* lowcase letter r */
#define BUTTON_UP 117           /* lowcase letter u */
#define BUTTON_DOWN 100         /* lowcase letter d */
#define BUTTON_RETURN 10

int main()
{
  /* at the beginning I use four buttons in order to finish the whole
     application framework. Changing back to two buttons shouldn't
     affect underlining structure except the way of interpreting
     button behaviours */
  char ch;
  while ((ch=getchar())) {
    switch(ch) {
    case BUTTON_LEFT:
      printf("left is pressed\n");
      break;
    case BUTTON_RIGHT:
      printf("right is pressed\n");
      break;
    case BUTTON_UP:
      printf("up is pressed\n");
      break;
    case BUTTON_DOWN:
      printf("down is pressed\n");
      break;
    case BUTTON_RETURN:
      break;
    default:;
      printf("else %d is pressed\n", ch);
    }
  }
  return 0;
}
