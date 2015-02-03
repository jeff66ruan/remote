#include "volume.h"

#define VOLUME_DEFAULT 10
#define VOLUME_MAX 40
#define VOLUME_MIN 0

static volume_t g_volume = VOLUME_DEFAULT;

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
