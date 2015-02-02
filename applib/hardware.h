/** \file
 * Copyright:
 *
 * Description: This simulates the hardware - TV sets
 *
 */

#ifndef D_hardware_H
#define D_hardware_H

#include <stdint.h>

typedef uint8_t volume_t;

/**
 * It reads current volume value
 * @return the current volume value
 */
extern volume_t volumeRead(void);

#endif
