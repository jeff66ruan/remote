/** \file
 * Copyright:
 *
 * Description: This simulates operating mode for a TV set
 *
 */

#ifndef D_opmode_H
#define D_opmode_H

#include <stdint.h>
#include <stdbool.h>

typedef bool opmode_t;

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
