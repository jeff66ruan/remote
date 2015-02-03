#include "channel.h"

#define CHANNEL_DEFAULT 3
#define CHANNEL_MAX 5
#define CHANNEL_MIN 1

static channel_t g_channel = CHANNEL_DEFAULT;

channel_t channelRead(void)
{
  return g_channel;
}

channel_t channelRight(void)
{
  return (g_channel == CHANNEL_MAX) ? CHANNEL_MAX : ++g_channel;
}

channel_t channelLeft(void)
{
return (g_channel == CHANNEL_MIN) ? CHANNEL_MIN : --g_channel;
}

channel_t channelReset(void)
{
  g_channel = CHANNEL_DEFAULT;
  return g_channel;
}
