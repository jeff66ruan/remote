/** \file
 * Copyright:
 *
 * Description: This simulates the hardware - TV sets
 *
 * preferable each hardware component can be in its own module
 */

#ifndef D_hardware_H
#define D_hardware_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t volume_t;
typedef bool opmode_t;

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

/**
 * It reads current operation mode value
 * @return the current operation mode value
 */
extern opmode_t opmodeRead(void);

/**
 * It turns on or off operation mode to next mode
 * @return the new operation mode value
 */
extern opmode_t opmodeNext(void);

/**
 * It turns on or off operation mode to next mode
 * @return the new operation mode value
 */
extern opmode_t opmodePrev(void);

/**
 * It resets operation mode value to the default
 * @return the new operation mode value
 */
extern opmode_t opmodeReset(void);

#endif
