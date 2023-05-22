#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#include "field_setup.h"

void set_neighbour_policy(uint16_t arr[], int x, int y){
    for(unsigned int i=0; i<(x*y); i++){
        if((i+1) % x != 0){
            arr[i] = arr[i]|0b0000000100000000;
        };
        if((i) % x != 0){
            arr[i] = arr[i]|0b0000001000000000;
        };
        if(i > (x-1)){
            arr[i] = arr[i]|0b0000100000000000;
        };
        if(i < (x*(y-1))){
            arr[i] = arr[i]|0b0000010000000000;
        };
    };
}

void increment_around_bombs(uint16_t arr[], int x, int y, int bomb_cord){

    if((arr[bomb_cord]&0b0000100000000000) && ((arr[bomb_cord-x]&0b1111) != 0b1001)){
        arr[bomb_cord-x]++;
    };

    if((arr[bomb_cord]&0b0000010000000000) && ((arr[bomb_cord+x]&0b1111) != 0b1001)){
        arr[bomb_cord+x]++;
    };

    if((arr[bomb_cord]&0b0000001000000000) && ((arr[bomb_cord-1]&0b1111) != 0b1001)){
        arr[bomb_cord-1]++;
    };

    if((arr[bomb_cord]&0b0000000100000000) && ((arr[bomb_cord+1]&0b1111) != 0b1001)){
        arr[bomb_cord+1]++;
    };



    if(((arr[bomb_cord]&0b0000101000000000) == 0b0000101000000000) && ((arr[bomb_cord-x-1]&0b1111) != 0b1001)){
        arr[bomb_cord-x-1]++;
    };

    if(((arr[bomb_cord]&0b0000100100000000) == 0b0000100100000000) && ((arr[bomb_cord-x+1]&0b1111) != 0b1001)){
        arr[bomb_cord-x+1]++;
    };

    if(((arr[bomb_cord]&0b0000011000000000) == 0b0000011000000000) && ((arr[bomb_cord+x-1]&0b1111) != 0b1001)){
        arr[bomb_cord+x-1]++;
    };

    if(((arr[bomb_cord]&0b0000010100000000) == 0b0000010100000000) && ((arr[bomb_cord+x+1]&0b1111) != 0b1001)){
        arr[bomb_cord+x+1]++;
    };

}

void generate_bombs(uint16_t arr[], int bombs, int x, int y, int first_cord){

    unsigned int bomb_candidate;

    srand(time(0));

    for(unsigned int i=0; i<bombs; i=i){
        bomb_candidate = rand()%(x*y-1);
        if(((arr[bomb_candidate]&0b1111) != 0b1001) && bomb_candidate!=first_cord){
            arr[bomb_candidate] = (arr[bomb_candidate]&0b1111111111110000)|0b1001;
            increment_around_bombs(arr, x, y, bomb_candidate);
            i++;
        }
    }
}
