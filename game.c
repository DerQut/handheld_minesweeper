#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <malloc.h>

#include "field_setup.h"
#include "defines.h"

void print_arr(uint16_t arr[]){
    printf("\n");
    for(unsigned short int i = 0; i < (SIZE_X * SIZE_Y); i++){
        if(arr[i] & UNCOVERED){
            printf("%d ", FIELD_VALUE(arr[i]));
        }else{
            if(arr[i] & FLAG){
                printf("F ");
            }else{
                printf("C ");
            }
        };


        if((i+1) % SIZE_X == 0){
            printf("\n");
        };
    };
    printf("\n\n");
}

void uncover(uint16_t arr[], int coord){

    if((arr[coord] & (FLAG + UNCOVERED)) == 0){
        arr[coord] |= UNCOVERED;

        if(FIELD_VALUE(arr[coord]) == 0){

            if(arr[coord] & UP){
                uncover(arr, coord - SIZE_X);
            };

            if(arr[coord] & DOWN){
                uncover(arr, coord + SIZE_X);
            };

            if(arr[coord] & LEFT){
                uncover(arr, coord - 1);
            };

            if(arr[coord] & RIGHT){
                uncover(arr, coord + 1);
            };


            if((arr[coord] & LEFT_UP) == LEFT_UP){
                uncover(arr, coord - 1 - SIZE_X);
            };

            if( (arr[coord] & RIGHT_UP) == RIGHT_UP){
                uncover(arr, coord + 1 - SIZE_X);
            };

            if( (arr[coord] & LEFT_DOWN) == LEFT_DOWN){
                uncover(arr, coord - 1 + SIZE_X);
            };

            if( (arr[coord] & RIGHT_DOWN) == RIGHT_DOWN){
                uncover(arr, coord + 1 + SIZE_X);
            };
        };
    };
}

void set_flag(uint16_t arr[], int coord, uint8_t *flags_total_ptr){
    if((arr[coord] ^= FLAG) & FLAG)
        *flags_total_ptr++;
    else
        *flags_total_ptr--;
}

void first_move(uint16_t arr[]){

    print_arr(arr);

    int first_coord;
    printf("First coord: ");
    scanf("%d", &first_coord);
    printf("\n");

    set_neighbour_policy(arr);
    generate_bombs(arr, first_coord);
    uncover(arr, first_coord);

    print_arr(arr);
}

void move(uint16_t arr[], bool* alive_ptr, uint8_t* flags_total_ptr){
    int action;
    int coord;

    printf("Your action [0- uncover, 1- flag]: ");

    fflush(stdin);
    scanf("%d", &action);

    printf("Your number (0-%d): ", SIZE_X * SIZE_Y - 1);

    fflush(stdin);
    scanf("%d", &coord);

    if(!action){

        uncover(arr, coord);
        print_arr(arr);

        if(FIELD_VALUE(arr[coord]) == BOMB_VALUE){
            *alive_ptr = false;
        }
    }else{
        set_flag(arr, coord, flags_total_ptr);
        print_arr(arr);
    }
}
