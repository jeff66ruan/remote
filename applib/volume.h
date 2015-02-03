/** \file
 * Copyright:
 *
 * Description: This simulates the hardware - TV sets
 *
 * preferable each hardware component can be in its own module
 */

#ifndef D_volume_H
#define D_volume_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t volume_t;

/**
 * It reads current volume value
 * @return the current volume value
 */
extern volume_t volumeRead(void);

/**
 * It increases current volume value
 * @return the new volume value
 */
extern volume_t volumeNext(void);

/**
 * It decreases current volume value
 * @return the new volume value
 */
extern volume_t volumePrev(void);

/**
 * It resets volume value to the default
 * @return the new volume value
 */
extern volume_t volumeReset(void);

#endif
