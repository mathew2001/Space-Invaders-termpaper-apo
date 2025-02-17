#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "flying_saucer.h"
#include "../textures/flying_saucer_texture.h"

#define ERROR 101

#define FLYING_SAUCER_POS_X 0
#define FLYING_SAUCER_POS_Y 30

objects_t* create_flying_saucer(){
    srandom(time(NULL));

    object_desc_t* flying_saucer_desc = (object_desc_t*)malloc(1 * sizeof(object_desc_t));
    if(flying_saucer_desc == NULL){
        fprintf(stderr, "ERROR: Cant allocate mem for flying_saucer_desc!\n");
        exit(ERROR);
    }

    flying_saucer_desc->bit_width = flying_saucer_width;
    flying_saucer_desc->bit_height = flying_saucer_height;
    flying_saucer_desc->scale = 2;
    flying_saucer_desc->bits = flying_saucer_bits;
    flying_saucer_desc->pos_x = FLYING_SAUCER_POS_X;
    flying_saucer_desc->pos_y = FLYING_SAUCER_POS_Y;
    flying_saucer_desc->size_x = flying_saucer_desc->bit_width * flying_saucer_desc->scale;
    flying_saucer_desc->size_y = flying_saucer_desc->bit_height * flying_saucer_desc->scale;
    flying_saucer_desc->status = false;
    flying_saucer_desc->bits_offset = 0;

    objects_t *flying_saucer = (objects_t*)malloc(sizeof(objects_t));
    if(flying_saucer == NULL){
        fprintf(stderr, "ERROR: Cant allocate mem for flying_saucer!\n");
        exit(ERROR);
    }
    flying_saucer->count = 1;

    flying_saucer->objects = flying_saucer_desc;
    flying_saucer->speed_x = 1;

    printf("Flying saucer was created successfully!\n");
    return flying_saucer;
}

void move_flying_saucer(objects_t * flying_saucer_obj){
    object_desc_t* flying_saucer = flying_saucer_obj->objects;
    if(flying_saucer->status == false && random()%1000+1 == 1){
        printf("Flying saucer was activated!\n");
        if(random()%2 == 0){
            flying_saucer_obj->speed_x = -1;
            flying_saucer->pos_x = 480-flying_saucer->size_x;
        } else {
            flying_saucer_obj->speed_x = 1;
            flying_saucer->pos_x = 0;
        }
        flying_saucer->status = true;
    }
    if(flying_saucer->status == true){
        if(flying_saucer->pos_x+flying_saucer->size_x+flying_saucer_obj->speed_x*5 > 480){
            flying_saucer->status = false;
//            flying_saucer->pos_x = 0;
            return;
        }
        if(flying_saucer->pos_x+flying_saucer_obj->speed_x*5 < 0){
            flying_saucer->status = false;
//            flying_saucer->pos_x = 480-flying_saucer->size_x;
            return;
        }
        flying_saucer->pos_x+=flying_saucer_obj->speed_x*5;

    }


}
