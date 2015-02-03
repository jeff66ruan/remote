/** \file
 * Copyright:
 *
 * Description: This simulates the volume for a TV set
 *
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
extern volume_t volumeRight(void);

/**
 * It decreases current volume value
 * @return the new volume value
 */
extern volume_t volumeLeft(void);

/**
 * It resets volume value to the default
 * @return the new volume value
 */
extern volume_t volumeReset(void);

#endif
