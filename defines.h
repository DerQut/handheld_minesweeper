#pragma once
#include <stdint.h>

#define UNCOVERED       0x8000
#define FLAG            0x4000
#define BOMB_VALUE      9
#define FIELD_VALUE(X)  (*(uint8_t*)&(X))

#define RIGHT           0b000100000000
#define LEFT            0b001000000000
#define DOWN            0b010000000000
#define UP              0b100000000000

#define RIGHT_UP        0b100100000000
#define RIGHT_DOWN      0b010100000000
#define LEFT_UP         0b101000000000
#define LEFT_DOWN       0b011000000000

#define SIZE_X          9
#define SIZE_Y          9
#define BOMBS           9