#ifndef SPACE_INVADERS_ALIENS_TEXTURE_H
#define SPACE_INVADERS_ALIENS_TEXTURE_H

#include "stdint.h"

static uint16_t aliens_bits[] = {

/* Monster 1 ():
   ht=8, width=8
   +--------+
   |   **   |
   |  ****  |
   | ****** |
   |** ** **|
   |********|
   | * ** * |
   |*      *|
   | *    * |
   +--------+ */
        0x18,
        0x3c,
        0x7e,
        0xdb,
        0xff,
        0x5a,
        0x81,
        0x42,

/* Monster 2 ():
   ht=8, width=11
   +-----------+
   |  *     *  |
   |   *   *   |
   |  *******  |
   | ** *** ** |
   |***********|
   |***********|
   |* *     * *|
   |   ** **   |
   +-----------+ */
        0x104,
        0x88,
        0x1fc,
        0x376,
        0x7ff,
        0x7ff,
        0x505,
        0xd8,

/* Monster 3 ():
   ht=8, width=12
   +------------+
   |    ****    |
   | ********** |
   |************|
   |***  **  ***|
   |************|
   |  ***  ***  |
   | **  **  ** |
   |  **    **  |
   +------------+ */
        0xf0,
        0x7fe,
        0xfff,
        0xe67,
        0xfff,
        0x39c,
        0x666,
        0x30c,
};

static uint8_t aliens_height[] = {
        8,
        8,
        8,
};

static uint8_t aliens_width[] = {
        8,
        11,
        12,
};

#endif //SPACE_INVADERS_ALIENS_TEXTURE_H
