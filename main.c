#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <malloc.h>

#include "field_setup.h"
#include "game.h"

#define SIZE_X 9
#define SIZE_Y 9
#define BOMBS 9

// 0b Uncovered-Flag -0-0- Up-Down-Left-Right -0-0-0-0- Value-Value-Value-Vale

int main(){
    bool alive = true;
    uint16_t field[SIZE_X*SIZE_Y] = {0b0000000000000000};
    int flags_total = 0;

    first_move(field, SIZE_X, SIZE_Y, BOMBS);


    while(alive){
        move(field, SIZE_X, SIZE_Y, &alive, &flags_total);
    }
}
