#include <stdlib.h>

#include "space_ship.h"
#include "../textures/space_ship_texture.h"

#define START_POS 250
#define POS_Y 280

object_desc_t *space_ship_desc;

objects_t* create_space_ship(){
    space_ship_desc = malloc(1 * sizeof(object_desc_t));

    space_ship_desc->width = space_ship_width;
    space_ship_desc->height = space_ship_height;
    space_ship_desc->scale = 2;
    space_ship_desc->bits = space_ship_bits;
    space_ship_desc->pos_x = START_POS;
    space_ship_desc->pos_y = POS_Y;


    objects_t *space_ship = malloc(sizeof(objects_t));
    space_ship->count = 1;

    space_ship->objects = space_ship_desc;
//    objects_t space_ship = {
//            1,
//            space_ship_desc
//    };

    return space_ship;
}