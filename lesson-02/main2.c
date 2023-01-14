// Copyright Johanna Liu 2022
//
// Created by Johanna Liu
// Created in Jan 2023
// This program is for Space Aliens on GameBoy

#include <gb/gb.h>
#include <stdio.h>

#include "MetaSprites.c"
#include "SpaceAliens.c"

void main(){
    // load spritesheet referenced as #0
    // load 16 sprites from it
    // from variable SpaceAliens
    set_sprite_data(0, 16, SpaceAliens);

    // load sprites for eta sprite
    set_meta_sprite_tile(0, 1, 2, 3, 4);

    // move sprite indexed #0 to (88, 78)
    move_meta_sprite(0, 76, 120);

    SHOW_SPRITES;
    DISPLAY_ON;
}
