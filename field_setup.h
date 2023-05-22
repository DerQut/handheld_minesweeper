#pragma once

void set_neighbour_policy(uint16_t arr[], int x, int y);

void generate_bombs(uint16_t arr[], int bombs, int x, int y, int first_cord);

void increment_around_bombs(uint16_t arr[], int x, int y, int bomb_cord);
