#ifndef SPACE_INVADERS_FLYING_SAUCER_TEXTURE_H
#define SPACE_INVADERS_FLYING_SAUCER_TEXTURE_H

#include <stdint.h>

static uint32_t flying_saucer_bits[] = {

/* UFO  :
   ht=7, width=16
   +----------------+
   |     ******     |
   |   **********   |
   |  ************  |
   | ** ** ** ** ** |
   |****************|
   |  ***  **  ***  |
   |   *        *   |
   +----------------+ */
        0x7e0,
        0x1ff8,
        0x3ffc,
        0x6db6,
        0xffff,
        0x399c,
        0x1008,

/* UFO_BROKEN :
   ht=8, width=20
   +--------------------+
   |  *  * *      * *  *|
   |   *        **    * |
   |* *   *****  **     |
   |     *******  ***   |
   |    *** * * *  ***  |
   |  *   *****   **    |
   |*      * *   **     |
   |  *   *   *    *    |
   +--------------------+ */
        0x25029,
        0x100c2,
        0xa3e60,
        0x7f38,
        0xea9c,
        0x23e30,
        0x81460,
        0x22210,
/* UFO_EMPTY :
   ht=8, width=20
   +--------------------+
   |                    |
   |                    |
   |                    |
   |                    |
   |                    |
   |                    |
   |                    |
   |                    |
   +--------------------+ */
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,
        0x0,

};

static uint8_t flying_saucer_width = 16;
static uint8_t flying_saucer_height = 7;

#endif //SPACE_INVADERS_FLYING_SAUCER_TEXTURE_H
