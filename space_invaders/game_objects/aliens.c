#include <stdlib.h>
#include <stdio.h>

#define ERROR 101

#include "aliens.h"
#include "../textures/aliens_texture.h"
#include "object_structure.h"

bool move_alive_alien(objects_t* aliens, int curr_idx);
int get_last_alive_alien_idx(object_desc_t* aliens, int aliens_num);

objects_t* create_aliens(){
//    object_desc_t aliens_desc[ALIENS_NUM];

    object_desc_t* aliens_desc = malloc(ALIENS_NUM * sizeof(object_desc_t));
    if(aliens_desc == NULL){
        fprintf(stderr, "ERROR: Cant allocate mem for aliens_desc!\n");
        exit(ERROR);
    }
    for(int i = 0; i < ALIENS_NUM; i++){

        switch (FIFTH_LINE-(i/ALIENS_IN_LINE)) {
            case FIRST_LINE:
                aliens_desc[i].bit_height = aliens_height[FIRST];
                aliens_desc[i].bit_width = aliens_width[FIRST];

                // aliens_desc[i].bits_offset = 1*aliens_height[ZERO];
                aliens_desc[i].bits = aliens_bits + 1*aliens_height[FIRST];

                aliens_desc[i].pos_x = FIRST_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = FIRST_GROUP_ALIENS_COST;
                break;
            case SECOND_LINE:
            case THIRD_LINE:
                aliens_desc[i].bit_height = aliens_height[SECOND];
                aliens_desc[i].bit_width = aliens_width[SECOND];

                // aliens_desc[i].bits_offset = 1*aliens_height[ZERO] + 2*aliens_height[FIRST];
                aliens_desc[i].bits = aliens_bits + 3*aliens_height[FIRST] + aliens_height[SECOND];

                aliens_desc[i].pos_x = SECOND_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = SECOND_GROUP_ALIENS_COST;
                break;
            case FOURTH_LINE:
            case FIFTH_LINE:
                aliens_desc[i].bit_height = aliens_height[THIRD];
                aliens_desc[i].bit_width = aliens_width[THIRD];

                // aliens_desc[i].bits_offset = 1*aliens_height[ZERO] + 2*aliens_height[FIRST] + 2*aliens_height[SECOND];
                aliens_desc[i].bits = aliens_bits + 3*aliens_height[FIRST] + 3*aliens_height[SECOND] + aliens_height[THIRD];


                aliens_desc[i].pos_x = THIRD_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = THIRD_GROUP_ALIENS_COST;
                break;
        }
        aliens_desc[i].scale = 2;
        aliens_desc[i].size_x = aliens_desc[i].bit_width * aliens_desc[i].scale;
        aliens_desc[i].size_y = aliens_desc[i].bit_height * aliens_desc[i].scale;
        aliens_desc[i].status = false;
        aliens_desc[i].bits_offset = 0;
        // aliens_desc[i].bits = aliens_bits;


    }

    objects_t* aliens = malloc(sizeof(objects_t));
    if(aliens == NULL){
        fprintf(stderr, "ERROR: Cant allocate mem for aliens!\n");
        exit(ERROR);
    }
    aliens->count = ALIENS_NUM;
    aliens->objects = aliens_desc;
    aliens->speed_x = ALIENS_INITIAL_SPEED_X;
    aliens->speed_y = ALIENS_INITIAL_SPEED_Y;
    aliens->curr_obj_idx = 0;

//    objects_t aliens = {
//            ALIENS_NUM,
//            aliens_desc,
//    };
    printf("Aliens was created successfully!\n");
    return aliens;
}

void reset_aliens(objects_t* aliens){
    object_desc_t* aliens_desc = aliens->objects;
    for(int i = 0; i < aliens->count; i++){
        switch (FIFTH_LINE-(i/ALIENS_IN_LINE)) {
            case FIRST_LINE:
                aliens_desc[i].bit_height = aliens_height[FIRST];
                aliens_desc[i].bit_width = aliens_width[FIRST];

                aliens_desc[i].bits = aliens_bits + 1*aliens_height[FIRST];

                aliens_desc[i].pos_x = FIRST_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = FIRST_GROUP_ALIENS_COST;
                break;
            case SECOND_LINE:
            case THIRD_LINE:
                aliens_desc[i].bit_height = aliens_height[SECOND];
                aliens_desc[i].bit_width = aliens_width[SECOND];

                aliens_desc[i].bits = aliens_bits + 3*aliens_height[FIRST] + aliens_height[SECOND];

                aliens_desc[i].pos_x = SECOND_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = SECOND_GROUP_ALIENS_COST;
                break;
            case FOURTH_LINE:
            case FIFTH_LINE:
                aliens_desc[i].bit_height = aliens_height[THIRD];
                aliens_desc[i].bit_width = aliens_width[THIRD];

                aliens_desc[i].bits = aliens_bits + 3*aliens_height[FIRST] + 3*aliens_height[SECOND] + aliens_height[THIRD];

                aliens_desc[i].pos_x = THIRD_GROUP_OFFSET_X + DISTANCE_X * (i % ALIENS_IN_LINE);
                aliens_desc[i].pos_y = OFFSET_Y + DISTANCE_Y * ((ALIENS_NUM-1-i) / ALIENS_IN_LINE);

                aliens_desc[i].cost = THIRD_GROUP_ALIENS_COST;
                break;
        }
        aliens_desc[i].scale = 2;
        aliens_desc[i].size_x = aliens_desc[i].bit_width * aliens_desc[i].scale;
        aliens_desc[i].size_y = aliens_desc[i].bit_height * aliens_desc[i].scale;
        aliens_desc[i].status = true;
        aliens_desc[i].bits_offset = 0;
    }

    aliens->speed_x = ALIENS_INITIAL_SPEED_X;
    aliens->speed_y = ALIENS_INITIAL_SPEED_Y;
    aliens->curr_obj_idx = 0;
}

bool move_aliens(objects_t* aliens){
    bool ret = false;
    int *i = &(aliens->curr_obj_idx);
    int died_count = 0;
    while((*i) < aliens->count){
        object_desc_t* alien = aliens->objects+*i;
        if(alien->status){

            ret = move_alive_alien(aliens, *i);

            (*i)++;
            (*i) %= aliens->count;
            break;
        }

        died_count++;
        if(died_count == aliens->count){
            return ret;
        }

        (*i)++;
        (*i) %= aliens->count;
    }
    return ret;
}

bool move_alive_alien(objects_t* aliens, int curr_idx){
    bool ret = false;
    object_desc_t* all_aliens = aliens->objects;
    object_desc_t* curr_alien = aliens->objects+curr_idx;
    int* speed_x = &aliens->speed_x;
    int* speed_y = &aliens->speed_y;

    if((*speed_y) == 0){
        curr_alien->pos_x+=(*speed_x);
        switch (curr_alien->status) {
            case 1:
                // curr_alien->bits++;
                curr_alien->status = 2;
                break;
            case 2:
                // curr_alien->bits++;
                curr_alien->status = 1;
        }
    }

    if(curr_alien->pos_y+curr_alien->size_y+(*speed_y) > 320){
        printf("You lost!\n");
        ret = true;
        return ret;
    }
    curr_alien->pos_y+=(*speed_y);
    if(curr_idx == get_last_alive_alien_idx(aliens->objects, aliens->count)){
//        printf("LAST\n");
        for(int i = 0; i < aliens->count; i++){
            if(!all_aliens[i].status){
                continue;
            }
            if(all_aliens[i].pos_x+all_aliens[i].size_x+(*speed_x) > 480 || all_aliens[i].pos_x+(*speed_x) < 0){
                (*speed_y) = 16;
                (*speed_x)*=-1;

                break;
            }
            (*speed_y) = 0;
        }
    }
    return ret;

}

int get_last_alive_alien_idx(object_desc_t* aliens, int aliens_num){
    int last_alive = aliens_num-1;

    while(last_alive > 0 && !(aliens+last_alive)->status){
        last_alive--;
    }
    if(!(aliens+last_alive)->status){
        printf("ERROR: is not alien alive here!\n");
        exit(1);
    }
    return last_alive;
}
