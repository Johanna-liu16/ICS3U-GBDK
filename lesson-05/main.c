// Copyright Johanna Liu 2022
//
// Created by Johanna Liu
// Created in Jan 2023
// This program is for Space Aliens on GameBoy

#include <gb/gb.h>
#include <stdio.h>

#include "MetaSprites.c"
#include "SpaceAliens.c"
#include "Background.c"

void main(){
    // user input
    uint8_t joypadData;

    // load spritesheet referenced as #0
    // load 16 sprites from it
    // from variable SpaceAliens
    set_sprite_data(0, 16, SpaceAliens);

    // load sprites for eta sprite
    set_meta_sprite_tile(0, 1, 2, 3, 4);

    // move sprite indexed #0 to (88, 78)
    move_meta_sprite(0, 76, 120);

    //set background tile sheet 0 to a different tile sheet
    set_bkg_data(0, 43, SpaceAliens);
    // load tiles from (0, 0) to (20, 36) form the tile map called background
    set_bkg_tiles(0, 0, 20, 36, Background);

    SHOW_BKG; // turn background on
    SHOW_SPRITES;
    DISPLAY_ON;

    // game loop
    while (1) {
        // get D-pad input
        joypadData = joypad();

        // If LEFT D-pad is pressed
        if (joypadData & J_LEFT) {
            // move sprite in teh index 0 by (x,y) (-1, 0)
            scroll_meta_sprite(0, -1, 0);
        }

        // If RIGHT D-pad is pressed
        if (joypadData & J_RIGHT) {
            // move sprite in the index 0 by (x, y) (+1, 0)
            scroll_meta_sprite(0, 1, 0);
        }

        // if UP D-pad is pressed
        if (joypadData & J_UP) {
            // move spritein the index 0 by (x,y) (0, -1)
            scroll_meta_sprite(0, 0, -1);
        }

        //if DOWN D-pad is pressed
        if (joypadData & J_DOWN) {
            // move sprite in teh index 0 by (x, y)(0, +1)
            scroll_meta_sprite(0, 0, 1);
        }

        // scroll background 0 in the x and -1 in teh y
        scroll_bkg(0, -1);

        // wait until end of frame (1/60th second)
        wait_vbl_done();
    }
}
