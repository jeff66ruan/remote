#include "bright.h"

#define BRIGHT_DEFAULT 50
#define BRIGHT_MAX 100
#define BRIGHT_MIN 0

static bright_t g_bright = BRIGHT_DEFAULT;

bright_t brightRead(void)
{
  return g_bright;
}

bright_t brightRight(void)
{
  return (g_bright == BRIGHT_MAX) ? BRIGHT_MAX : ++g_bright;
}

bright_t brightLeft(void)
{
return (g_bright == BRIGHT_MIN) ? BRIGHT_MIN : --g_bright;
}

bright_t brightReset(void)
{
  g_bright = BRIGHT_DEFAULT;
  return g_bright;
}
