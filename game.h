#pragma once
#include <stdint.h>

void print_arr(uint16_t arr[]);

void uncover(uint16_t arr[], int coord);

void set_flag(uint16_t arr[], int coord, uint8_t* flags_total);

void first_move(uint16_t arr[]);

void move(uint16_t arr[], bool* alive, uint8_t* flags_total);
