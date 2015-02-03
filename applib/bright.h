/** \file
 * Copyright:
 *
 * Description: This simulates the volume for a TV set
 *
 */

#ifndef D_bright_H
#define D_bright_H

#include <stdint.h>

typedef uint8_t bright_t;

/**
 * It reads current brightness value
 * @return the current brightness value
 */
extern bright_t brightRead(void);

/**
 * It increases current bright value
 * @return the new bright value
 */
extern bright_t brightNext(void);

/**
 * It decreases current bright value
 * @return the new bright value
 */
extern bright_t brightPrev(void);

/**
 * It resets bright value to the default
 * @return the new bright value
 */
extern bright_t brightReset(void);

#endif
