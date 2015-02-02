#include "hardware.h"

static volume_t g_volume = 10;

volume_t volumeRead(void)
{
  return g_volume;
}
