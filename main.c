#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#include "field_setup.h"
#include "game.h"
#include "defines.h"

// 0b Uncovered-Flag -0-0- Up-Down-Left-Right -0-0-0-0- Value-Value-Value-Vale

int main(){
    bool alive = true;
    uint16_t field[SIZE_X * SIZE_Y] = {0};
    uint8_t flags_total = 0;

    first_move(field);

    while(alive){
        move(field, &alive, &flags_total);
    }
}
