#include "opmode.h"

#define OPMODE_DEFAULT false

static opmode_t g_opmode = OPMODE_DEFAULT;


opmode_t opmodeRead(void)
{
  return g_opmode;
}

opmode_t opmodeRight(void)
{
  g_opmode = !g_opmode;
  return g_opmode;
}

opmode_t opmodeLeft(void)
{
  return opmodeRight();
}

opmode_t opmodeReset(void)
{
  g_opmode = OPMODE_DEFAULT;
  return g_opmode;
}
