#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#include "field_setup.h"
#include "defines.h"

void set_neighbour_policy(uint16_t arr[]){
    for(uint8_t i = 0; i < (SIZE_X * SIZE_Y); i++){
        if(i % SIZE_X != 8)
            arr[i] |= RIGHT;

        if(i % SIZE_X != 0)
            arr[i] |= LEFT;

        if(i > SIZE_X - 1)
            arr[i] |= UP;

        if(i < SIZE_X * (SIZE_Y - 1))
            arr[i] |= DOWN;

    };
}

void increment_around_bombs(uint16_t arr[], int bomb_cord){

    if(arr[bomb_cord] & UP && FIELD_VALUE(arr[bomb_cord - SIZE_X]) != BOMB_VALUE)
        arr[bomb_cord - SIZE_X]++;

    if(arr[bomb_cord] & DOWN && FIELD_VALUE(arr[bomb_cord + SIZE_X]) != BOMB_VALUE)
        arr[bomb_cord + SIZE_X]++;

    if(arr[bomb_cord] & LEFT && FIELD_VALUE(arr[bomb_cord - 1]) != BOMB_VALUE)
        arr[bomb_cord - 1]++;

    if(arr[bomb_cord] & RIGHT && FIELD_VALUE(arr[bomb_cord + 1]) != BOMB_VALUE)
        arr[bomb_cord + 1]++;



    if((arr[bomb_cord] & LEFT_UP) == LEFT_UP && FIELD_VALUE(arr[bomb_cord - SIZE_X - 1]) != BOMB_VALUE)
        arr[bomb_cord - SIZE_X - 1]++;

    if((arr[bomb_cord] & RIGHT_UP) == RIGHT_UP && FIELD_VALUE(arr[bomb_cord - SIZE_X + 1]) != BOMB_VALUE)
        arr[bomb_cord - SIZE_X + 1]++;

    if((arr[bomb_cord] & LEFT_DOWN) == LEFT_DOWN && FIELD_VALUE(arr[bomb_cord + SIZE_X - 1]) != BOMB_VALUE)
        arr[bomb_cord + SIZE_X - 1]++;

    if((arr[bomb_cord] & RIGHT_DOWN) == RIGHT_DOWN && FIELD_VALUE(arr[bomb_cord + SIZE_X + 1]) != BOMB_VALUE)
        arr[bomb_cord + SIZE_X + 1]++;

}

void generate_bombs(uint16_t arr[], int first_cord){

    unsigned int bomb_candidate;

    srand(time(0));

    for(uint8_t i = 0; i < BOMBS; ){
        bomb_candidate = rand() % (SIZE_X * SIZE_Y - 1);
        if((FIELD_VALUE(arr[bomb_candidate]) != BOMB_VALUE) && bomb_candidate != first_cord){
            FIELD_VALUE(arr[bomb_candidate]) = BOMB_VALUE;
            increment_around_bombs(arr, bomb_candidate);
            i++;
        }
    }
}
