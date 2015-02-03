/** \file
 * Copyright:
 *
 * Description: This simulates the channel for a TV set
 *
 */

#ifndef D_channel_H
#define D_channel_H

#include <stdint.h>

typedef uint8_t channel_t;

/**
 * It reads current channel value
 * @return the current channel value
 */
extern channel_t channelRead(void);

/**
 * It increases current channel value
 * @return the new channel value
 */
extern channel_t channelRight(void);

/**
 * It decreases current channel value
 * @return the new channel value
 */
extern channel_t channelLeft(void);

/**
 * It resets channel value to the default
 * @return the new channel value
 */
extern channel_t channelReset(void);


#endif
