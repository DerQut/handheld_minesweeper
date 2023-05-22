#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <malloc.h>

#include "field_setup.h"

void print_arr(uint16_t arr[], int x, int y){
    printf("\n");
    for(unsigned short int i = 0; i<(x*y); i++){
        if(arr[i]&0b1000000000000000){
            printf("%d ", arr[i]&0b0000000000001111);
        }else{
            if(arr[i]&0b0100000000000000){
                printf("F ");
            }else{
                printf("C ");
            }
        };


        if((i+1) % x == 0){
            printf("\n");
        };
    };
    printf("\n\n");
}

void uncover(uint16_t arr[], int x, int y, int cord){

    if((arr[cord]&0b1100000000000000) == 0){
        arr[cord] = arr[cord]|0b1000000000000000;

        if((arr[cord]&0b1111) == 0){

            if(arr[cord]&0b0000100000000000){
                uncover(arr, x, y, cord-x);
            };

            if(arr[cord]&0b0000010000000000){
                uncover(arr, x, y, cord+x);
            };

            if(arr[cord]&0b0000001000000000){
                uncover(arr, x, y, cord-1);
            };

            if(arr[cord]&0b0000000100000000){
                uncover(arr, x, y, cord+1);
            };


            if( (arr[cord]&0b0000101000000000) == 0b0000101000000000){
                uncover(arr, x, y, cord-1-x);
            };

            if( (arr[cord]&0b0000100100000000) == 0b0000100100000000){
                uncover(arr, x, y, cord+1-x);
            };

            if( (arr[cord]&0b0000011000000000) == 0b0000011000000000){
                uncover(arr, x, y, cord-1+x);
            };

            if( (arr[cord]&0b0000010100000000) == 0b0000010100000000){
                uncover(arr, x, y, cord+1+x);
            };
        };
    };
}

void set_flag(uint16_t arr[], int cord, int *flags_total){
    if((arr[cord]&0b1100000000000000) == 0){
        arr[cord] = (arr[cord]&0b0011111111111111)|0b0100000000000000;
        *flags_total++;
    }else{
        if((arr[cord]&0b1100000000000000) == 0b0100000000000000){
            arr[cord] = (arr[cord])&0b0011111111111111;
            *flags_total--;
        }
    }
}

void first_move(uint16_t arr[], int x, int y, int bombs){

    print_arr(arr, x, y);

    int first_cord;
    printf("First cord: ");
    scanf("%d", &first_cord);
    printf("\n");

    set_neighbour_policy(arr, x, y);
    generate_bombs(arr, bombs, x, y, first_cord);
    uncover(arr, x, y, first_cord);

    print_arr(arr, x, y);
}

void move(uint16_t arr[], int x, int y, bool* alive, int* flags_total){
    bool action;
    int cord;

    printf("Your action [0- uncover, 1- flag]: ");
    scanf("%d", &action);


    printf("Your number (0-%d): ", x*y-1);
    scanf("%d", &cord);

    if(!action){

        uncover(arr, x, y, cord);
        print_arr(arr, x, y);

        if((arr[cord]&0b1001) == 0b1001){
            *alive = false;
        }
    }else{
        set_flag(arr, cord, (int*)&flags_total);
        print_arr(arr, x, y);
    }
}
