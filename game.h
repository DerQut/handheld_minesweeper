#pragma once

void print_arr(uint16_t arr[], int x, int y);

void uncover(uint16_t arr[], int x, int y, int cord);

void set_flag(uint16_t arr[], int cord, int* flags_total);

void first_move(uint16_t arr[], int x, int y, int bombs);

void move(uint16_t arr[], int x, int y, bool* alive, int* flags_total);
