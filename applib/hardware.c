#include "hardware.h"

#define VOLUME_DEFAULT 10
#define VOLUME_MAX 40
#define VOLUME_MIN 0

#define OPMODE_DEFAULT false

static volume_t g_volume = VOLUME_DEFAULT;
static opmode_t g_opmode = OPMODE_DEFAULT;

volume_t volumeRead(void)
{
  return g_volume;
}

volume_t volumeNext(void)
{
  return (g_volume == VOLUME_MAX) ? VOLUME_MAX : ++g_volume;
}

volume_t volumePrev(void)
{
return (g_volume == VOLUME_MIN) ? VOLUME_MIN : --g_volume;
}

volume_t volumeReset(void)
{
  g_volume = VOLUME_DEFAULT;
  return g_volume;
}

opmode_t opmodeRead(void)
{
  return g_opmode;
}

opmode_t opmodeNext(void)
{
  g_opmode = !g_opmode;
  return g_opmode;
}

opmode_t opmodePrev(void)
{
  return opmodeNext();
}

opmode_t opmodeReset(void)
{
  g_opmode = OPMODE_DEFAULT;
  return g_opmode;
}
