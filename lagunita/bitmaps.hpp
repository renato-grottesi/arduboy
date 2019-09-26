#pragma once

#include <avr/io.h>
#include <avr/pgmspace.h>

/*
 * Game bitmaps stored in PROGMEM
 */

const unsigned char PROGMEM bmp_selection[] = {
    0b00010000, /**/
    0b00110000, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b00110000, /**/
    0b00010000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_empty[] = {
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_cactus[] = {
    0b00001100, /**/
    0b00011000, /**/
    0b00110000, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b00001100, /**/
    0b00000110, /**/
    0b00000011, /**/
};

const unsigned char PROGMEM bmp_weed[] = {
    0b00001000, /**/
    0b00101001, /**/
    0b01010010, /**/
    0b11111110, /**/
    0b01001001, /**/
    0b00100101, /**/
    0b00010000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_ground[] = {
    0b00100000, /**/
    0b01000000, /**/
    0b00100000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b01000000, /**/
    0b00010000, /**/
    0b10000000, /**/
};

const unsigned char PROGMEM bmp_bridge[] = {
    0b11110000, /**/
    0b01001000, /**/
    0b01111100, /**/
    0b00100100, /**/
    0b01111100, /**/
    0b01001000, /**/
    0b11110000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_decor[] = {
    /* Top */
    0b00000110, /**/
    0b00000110, /**/
    0b00001100, /**/
    0b00001100, /**/
    0b00001100, /**/
    0b00001100, /**/
    0b00001100, /**/
    0b00011000, /**/
    0b00011000, /**/
    0b00011000, /**/
    0b00111000, /**/
    0b11110000, /**/
    0b11100000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00011100, /**/
    0b00111100, /**/
    0b01110000, /**/
    0b01100000, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b11000000, /**/
    0b11100000, /**/
    0b01111000, /**/
    0b00111111, /**/
    0b00001111, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_tumbleweed[] = {
    /* Frame 1 */
    0b00010000, /**/
    0b00101100, /**/
    0b01001010, /**/
    0b10100000, /**/
    0b10001001, /**/
    0b01010010, /**/
    0b00100100, /**/
    0b00011000, /**/
    /* Frame 3 */
    0b00001100, /**/
    0b00011000, /**/
    0b10100000, /**/
    0b01001010, /**/
    0b01001001, /**/
    0b11001001, /**/
    0b01111010, /**/
    0b00000100, /**/
    /* Frame 2 */
    0b00110000, /**/
    0b01000100, /**/
    0b10010010, /**/
    0b01100001, /**/
    0b10001001, /**/
    0b01000110, /**/
    0b00100100, /**/
    0b00011000, /**/
    /* Frame 4 */
    0b00001100, /**/
    0b01110011, /**/
    0b10001001, /**/
    0b01000110, /**/
    0b10100010, /**/
    0b10010110, /**/
    0b01011100, /**/
    0b00100000, /**/
    /* Frame 5 */
    0b00001000, /**/
    0b01110100, /**/
    0b10000110, /**/
    0b00101001, /**/
    0b01010001, /**/
    0b10001010, /**/
    0b01100100, /**/
    0b00011000, /**/
    /* Frame 6 */
    0b00100000, /**/
    0b01011100, /**/
    0b10010010, /**/
    0b10100010, /**/
    0b01001010, /**/
    0b00100111, /**/
    0b01010001, /**/
    0b00000110, /**/
    /* Frame 7 */
    0b00011000, /**/
    0b00100100, /**/
    0b01000110, /**/
    0b11101001, /**/
    0b10010010, /**/
    0b01001010, /**/
    0b00100100, /**/
    0b00100000, /**/
    /* Frame 8 */
    0b00000110, /**/
    0b00111001, /**/
    0b01001001, /**/
    0b01001010, /**/
    0b01100010, /**/
    0b10010000, /**/
    0b11001000, /**/
    0b00110000, /**/
};

const unsigned char PROGMEM bmp_river[] = {
    /* Frame 1 */
    0b11111111, /**/
    0b11111100, /**/
    0b00110000, /**/
    0b10000100, /**/
    0b01001000, /**/
    0b10000000, /**/
    0b00001110, /**/
    0b11111111, /**/
    /* Frame 3 */
    0b11111111, /**/
    0b11111100, /**/
    0b00110000, /**/
    0b00001000, /**/
    0b10010000, /**/
    0b01000000, /**/
    0b00001110, /**/
    0b11111111, /**/
    /* Frame 2 */
    0b11111111, /**/
    0b11111100, /**/
    0b00110000, /**/
    0b00000001, /**/
    0b00100010, /**/
    0b01000000, /**/
    0b00001110, /**/
    0b11111111, /**/
};

const unsigned char PROGMEM bmp_horse[] = {
    /* Frame 1 */
    0b01100000, /**/
    0b00110000, /**/
    0b00010000, /**/
    0b00111000, /**/
    0b01111100, /**/
    0b10111100, /**/
    0b01011100, /**/
    0b10011100, /**/
    0b00011100, /**/
    0b01011100, /**/
    0b01111111, /**/
    0b00111111, /**/
    0b00100110, /**/
    0b00100000, /**/
    0b01000000, /**/
    0b00000000, /**/
    /* Frame 2 */
    0b00110000, /**/
    0b00011000, /**/
    0b10001000, /**/
    0b01111000, /**/
    0b00111100, /**/
    0b11111100, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b00111100, /**/
    0b01011110, /**/
    0b10011111, /**/
    0b00100111, /**/
    0b01000110, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Frame 3 */
    0b00110000, /**/
    0b00011000, /**/
    0b10001000, /**/
    0b01111000, /**/
    0b00111100, /**/
    0b00111100, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b11011100, /**/
    0b00111110, /**/
    0b00011111, /**/
    0b00100111, /**/
    0b01000110, /**/
    0b10000000, /**/
    0b00000000, /**/
    /* Frame 4 */
    0b01100000, /**/
    0b00110000, /**/
    0b00010000, /**/
    0b00111000, /**/
    0b01111100, /**/
    0b10111100, /**/
    0b01011100, /**/
    0b00011100, /**/
    0b10011100, /**/
    0b01011100, /**/
    0b10111111, /**/
    0b01111111, /**/
    0b00000110, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_man[] = {
    /* Frame 1 */
    0b00000000, /**/
    0b00000000, /**/
    0b11010010, /**/
    0b00111111, /**/
    0b01010111, /**/
    0b10010010, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Frame 2 */
    0b00000000, /**/
    0b00000000, /**/
    0b11010010, /**/
    0b01111111, /**/
    0b10100111, /**/
    0b00000010, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Frame 3 */
    0b00000000, /**/
    0b00000000, /**/
    0b00100010, /**/
    0b11111111, /**/
    0b10100111, /**/
    0b00000010, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Frame 4 */
    0b00000000, /**/
    0b00000000, /**/
    0b11010010, /**/
    0b01111111, /**/
    0b10100111, /**/
    0b00000010, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_bird[] = {
    /* Frame 1 */
    0b00000000, /**/
    0b00000000, /**/
    0b00001011, /**/
    0b00001110, /**/
    0b00011100, /**/
    0b01111000, /**/
    0b00001110, /**/
    0b00000100, /**/
    /* Frame 2 */
    0b00000000, /**/
    0b00000000, /**/
    0b00010000, /**/
    0b00011100, /**/
    0b01111000, /**/
    0b00010000, /**/
    0b00011100, /**/
    0b00001000, /**/
    /* Frame 3 */
    0b00000000, /**/
    0b00000000, /**/
    0b00100000, /**/
    0b00110000, /**/
    0b00110000, /**/
    0b00100000, /**/
    0b00111000, /**/
    0b00010000, /**/
    /* Frame 4 */
    0b00000000, /**/
    0b00000000, /**/
    0b00010000, /**/
    0b00011100, /**/
    0b01111000, /**/
    0b00010000, /**/
    0b00011100, /**/
    0b00001000, /**/
};

const unsigned char PROGMEM bmp_bullet[] = {
    0b01111000, /**/
    0b01001000, /**/
    0b01111000, /**/
    0b01111000, /**/
    0b01111000, /**/
    0b00110000, /**/
    0b00110000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_mine[] = {
    /* Top */
    0b00000000, /* b0 */
    0b00000000, /**/
    0b00000000, /**/
    0b10000000, /**/
    0b01100000, /**/
    0b00011100, /**/
    0b00000011, /**/
    0b00001100, /**/
    0b10010000, /* b1 */
    0b01100000, /**/
    0b00010000, /**/
    0b00001100, /**/
    0b00000011, /**/
    0b00000100, /**/
    0b00000100, /**/
    0b00001000, /**/
    0b00111000, /* b2 */
    0b01000100, /**/
    0b10000010, /**/
    0b00011100, /**/
    0b11100000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Middle */
    0b11000000, /* b0 */
    0b00110000, /**/
    0b00001100, /**/
    0b00000011, /**/
    0b11000000, /**/
    0b00100000, /**/
    0b00011100, /**/
    0b00000010, /**/
    0b00000101, /* b1 */
    0b00001000, /**/
    0b10010000, /**/
    0b11100000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b11110000, /**/
    0b00001000, /**/
    0b11110000, /* b2 */
    0b00000000, /**/
    0b00001111, /**/
    0b00110000, /**/
    0b01000111, /**/
    0b10011000, /**/
    0b00100000, /**/
    0b11000000, /**/
    /* Bottom */
    0b00000000, /* b0 */
    0b00000001, /**/
    0b00000010, /**/
    0b00000010, /**/
    0b00000011, /**/
    0b00000010, /**/
    0b00000010, /**/
    0b00000010, /**/
    0b00000010, /* b1 */
    0b00000001, /**/
    0b00000000, /**/
    0b10000000, /**/
    0b11000001, /**/
    0b10100001, /**/
    0b10111001, /**/
    0b10101111, /**/
    0b10111001, /* b2 */
    0b10100001, /**/
    0b11000001, /**/
    0b10000010, /**/
    0b00000010, /**/
    0b00000001, /**/
    0b00000001, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_house[] = {
    /* Top */
    0b00000000, /* b0 */
    0b10000000, /**/
    0b01000000, /**/
    0b10100000, /**/
    0b01010000, /**/
    0b00101000, /**/
    0b00010100, /**/
    0b00001010, /**/
    0b00001010, /* b1 */
    0b00010100, /**/
    0b00101111, /**/
    0b01011111, /**/
    0b10100000, /**/
    0b01000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b00000000, /* b0 */
    0b11111111, /**/
    0b10000001, /**/
    0b10001100, /**/
    0b10001100, /**/
    0b10000000, /**/
    0b11111110, /**/
    0b10101001, /**/
    0b10101001, /* b1 */
    0b11111110, /**/
    0b10000000, /**/
    0b10001100, /**/
    0b10001100, /**/
    0b10000001, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_house2[] = {
    /* Top */
    0b11111110, /* b0 */
    0b10010001, /**/
    0b01011110, /**/
    0b00111110, /**/
    0b00010001, /**/
    0b00011110, /**/
    0b00011110, /**/
    0b00010001, /**/
    0b00011110, /* b1 */
    0b00011110, /**/
    0b00010001, /**/
    0b00111110, /**/
    0b01011110, /**/
    0b10010001, /**/
    0b11111110, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b10001111, /**/
    0b10001111, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10101001, /**/
    0b10101001, /**/
    0b10101001, /* b1 */
    0b11111111, /**/
    0b10000000, /**/
    0b10001111, /**/
    0b10001111, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_water[] = {
    /* Top */
    0b11111111, /**/
    0b11000001, /**/
    0b11111111, /**/
    0b01000001, /**/
    0b01111111, /**/
    0b11000001, /**/
    0b11111111, /**/
    0b00000000, /**/
    /* Middle */
    0b00000000, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b01010101, /**/
    0b00100010, /**/
    0b11111111, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b00000000, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b01010101, /**/
    0b00100010, /**/
    0b11111111, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_totem[] = {
    /* Top */
    0b00000100, /**/
    0b10011000, /**/
    0b11110011, /**/
    0b00111111, /**/
    0b11110011, /**/
    0b10011000, /**/
    0b00000100, /**/
    0b00000000, /**/
    /* Middle */
    0b00000100, /**/
    0b11101110, /**/
    0b11111011, /**/
    0b11001111, /**/
    0b11111011, /**/
    0b11101110, /**/
    0b00000100, /**/
    0b00000000, /**/
    /* Bottom */
    0b00000000, /**/
    0b10001100, /**/
    0b11111011, /**/
    0b11101111, /**/
    0b11111011, /**/
    0b10001100, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_mill[] = {
    /* Top */
    0b00100100, /**/
    0b10101000, /**/
    0b01110000, /**/
    0b11111100, /**/
    0b01110000, /**/
    0b10101000, /**/
    0b00100100, /**/
    0b00000000, /**/
    /* Middle */
    0b00000001, /**/
    0b00000000, /**/
    0b11110000, /**/
    0b10101111, /**/
    0b11110000, /**/
    0b00000000, /**/
    0b00000001, /**/
    0b00000000, /**/
    /* Bottom */
    0b11110000, /**/
    0b01001111, /**/
    0b00100100, /**/
    0b00011011, /**/
    0b00100100, /**/
    0b01001111, /**/
    0b11110000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_tree[] = {
    /* Top */
    0b00000000, /* b0 */
    0b00001100, /**/
    0b00011001, /**/
    0b00110011, /**/
    0b01100110, /**/
    0b01111100, /**/
    0b11111001, /**/
    0b11111111, /**/
    0b11111110, /* b1 */
    0b01110000, /**/
    0b00111100, /**/
    0b00111110, /**/
    0b00110011, /**/
    0b00011001, /**/
    0b00011000, /**/
    0b00001100, /**/
    /* Bottom */
    0b00000000, /* b0 */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b10000000, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111111, /* b1 */
    0b10111100, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
};

/* The upgraded bank is just 2 extra coins on top of the normal bank */
#define bmp_bank (&bmp_bank2[16])

const unsigned char PROGMEM bmp_bank2[] = {
    /* beginning of bmp_bank2 */
    0b00000000, /* b0 */
    0b00000000, /**/
    0b00100000, /**/
    0b01010000, /**/
    0b10001000, /**/
    0b01010000, /**/
    0b00100000, /**/
    0b00000000, /**/
    0b00100000, /* b1 */
    0b01010000, /**/
    0b10001000, /**/
    0b01010000, /**/
    0b00100000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* beginning of bmp_bank */
    /* Top */
    0b00110000, /* b0 */
    0b11111111, /**/
    0b00010110, /**/
    0b00001110, /**/
    0b00000101, /**/
    0b01000110, /**/
    0b10100110, /**/
    0b00010101, /**/
    0b10100110, /* b1 */
    0b01000110, /**/
    0b00000101, /**/
    0b00001110, /**/
    0b00010110, /**/
    0b11111111, /**/
    0b00110000, /**/
    0b00000000, /**/
    /* Bottom */
    0b00000000, /* b0 */
    0b11111111, /**/
    0b10000000, /**/
    0b10001100, /**/
    0b10001100, /**/
    0b10000000, /**/
    0b11111100, /**/
    0b10000101, /**/
    0b11111100, /* b1 */
    0b10000000, /**/
    0b10001100, /**/
    0b10001100, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_sheriff[] = {
    /* Top */
    0b11111110, /* b0 */
    0b00100101, /**/
    0b00010110, /**/
    0b00001110, /**/
    0b00000101, /**/
    0b00000110, /**/
    0b10100110, /**/
    0b01110101, /**/
    0b10100110, /* b1 */
    0b00000110, /**/
    0b00000101, /**/
    0b00001110, /**/
    0b00010110, /**/
    0b00100101, /**/
    0b11111110, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111110, /**/
    0b10000010, /**/
    0b11111110, /**/
    0b10000010, /**/
    0b11111110, /**/
    0b10000000, /**/
    0b10111110, /* b1 */
    0b10100010, /**/
    0b10111110, /**/
    0b10100010, /**/
    0b10111110, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_sheriff2[] = {
    /* Top */
    0b11111110, /* b0 */
    0b00100101, /**/
    0b00010110, /**/
    0b00001110, /**/
    0b10100101, /**/
    0b01110110, /**/
    0b10100110, /**/
    0b00000101, /**/
    0b10100110, /* b1 */
    0b01110110, /**/
    0b10100101, /**/
    0b00001110, /**/
    0b00010110, /**/
    0b00100101, /**/
    0b11111110, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111110, /**/
    0b10000010, /**/
    0b11111110, /**/
    0b10000010, /**/
    0b11111110, /**/
    0b10000000, /**/
    0b10111110, /* b1 */
    0b10100010, /**/
    0b10111110, /**/
    0b10100010, /**/
    0b10111110, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_church2[] = {
    /* Top */
    0b11000000, /* b0 */
    0b10110000, /**/
    0b10101100, /**/
    0b10101011, /**/
    0b10101100, /**/
    0b10110000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00000000, /* b1 */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /* b2 */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Middle */
    0b11111111, /* b0 */
    0b00000000, /**/
    0b00000100, /**/
    0b00111110, /**/
    0b00000100, /**/
    0b00000000, /**/
    0b11111111, /**/
    0b10000000, /**/
    0b10000000, /* b1 */
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111100, /**/
    0b10000010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10000010, /**/
    0b10011011, /* b1 */
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /* b2 */
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_church[] = {
    /* Top */
    0b11000000, /* b0 */
    0b10110000, /**/
    0b10101100, /**/
    0b10101011, /**/
    0b10101100, /**/
    0b10110000, /**/
    0b11000000, /**/
    0b10000000, /**/
    0b10000000, /* b1 */
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111100, /**/
    0b10000010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10000010, /**/
    0b10011011, /* b1 */
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /* b2 */
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b10011011, /**/
    0b10000010, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_saloon[] = {
    /* Top */
    0b11111100, /* b0 */
    0b00010100, /**/
    0b00011100, /**/
    0b00010111, /**/
    0b00011101, /**/
    0b00010111, /**/
    0b00011101, /**/
    0b00010111, /**/
    0b01111101, /* b1 */
    0b01000111, /**/
    0b01010101, /**/
    0b01010111, /**/
    0b01010101, /**/
    0b01000111, /**/
    0b01111101, /**/
    0b00010111, /**/
    0b00011101, /* b2 */
    0b00010111, /**/
    0b00011101, /**/
    0b00010111, /**/
    0b00011100, /**/
    0b00010100, /**/
    0b11111100, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b10011111, /**/
    0b10010001, /**/
    0b10010001, /**/
    0b10010001, /**/
    0b10011111, /**/
    0b10000000, /**/
    0b11111100, /* b1 */
    0b10101010, /**/
    0b10101001, /**/
    0b11111111, /**/
    0b10101001, /**/
    0b10101010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b10001111, /**/
    0b10001001, /**/
    0b10001111, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_saloon2[] = {
    /* Top */
    0b00000000, /* b0 */
    0b00000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b01000000, /**/
    0b11000000, /**/
    0b01000000, /**/
    0b11000000, /**/
    0b01111000, /* b1 */
    0b11000100, /**/
    0b01000010, /**/
    0b11000010, /**/
    0b01000010, /**/
    0b11000100, /**/
    0b01111000, /**/
    0b11000000, /**/
    0b01000000, /* b2 */
    0b11000000, /**/
    0b01000000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Middle */
    0b11111100, /* b0 */
    0b00010100, /**/
    0b00011100, /**/
    0b00010111, /**/
    0b00011100, /**/
    0b00010111, /**/
    0b00011100, /**/
    0b00010111, /**/
    0b01111100, /* b1 */
    0b01000111, /**/
    0b01010100, /**/
    0b01010111, /**/
    0b01010100, /**/
    0b01000111, /**/
    0b01111100, /**/
    0b00010111, /**/
    0b00011100, /* b2 */
    0b00010111, /**/
    0b00011100, /**/
    0b00010111, /**/
    0b00011100, /**/
    0b00010100, /**/
    0b11111100, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b10011111, /**/
    0b10010001, /**/
    0b10010001, /**/
    0b10010001, /**/
    0b10011111, /**/
    0b10000000, /**/
    0b11111100, /* b1 */
    0b10101010, /**/
    0b10101001, /**/
    0b11111111, /**/
    0b10101001, /**/
    0b10101010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b10001111, /**/
    0b10001001, /**/
    0b10001111, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_stable2[] = {
    /* Top */
    0b00000000, /* b0 */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b10000000, /* b1 */
    0b11000000, /**/
    0b10100000, /**/
    0b01010000, /**/
    0b00101000, /**/
    0b00010100, /**/
    0b00001010, /**/
    0b11111111, /**/
    0b00001010, /* b2*/
    0b00010100, /**/
    0b00101000, /**/
    0b01010000, /**/
    0b10100000, /**/
    0b11000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /* b3 */
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Middle */
    0b10000000, /* b0 */
    0b11000000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11110000, /**/
    0b10010000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111111, /* b1 */
    0b10000000, /**/
    0b11111111, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10011100, /**/
    0b10011100, /**/
    0b10011111, /**/
    0b10011100, /* b2 */
    0b10011100, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b11111000, /* b3 */
    0b10010000, /**/
    0b11110000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111000, /**/
    0b11111000, /**/
    0b10000000, /**/
    0b11100000, /**/
    0b11100000, /**/
    0b10000000, /**/
    0b11111111, /* b1 */
    0b10011001, /**/
    0b11100111, /**/
    0b10011001, /**/
    0b11111111, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b11111111, /**/
    0b10011001, /**/
    0b11100111, /**/
    0b10011001, /**/
    0b11111111, /**/
    0b10100000, /**/
    0b10100000, /* b3 */
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_stable[] = {
    /* Top */
    0b10000000, /* b0 */
    0b11000000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11110000, /**/
    0b10010000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111100, /* b1 */
    0b10000100, /**/
    0b11111110, /**/
    0b10000010, /**/
    0b11111111, /**/
    0b11000111, /**/
    0b10101011, /**/
    0b10010011, /**/
    0b10101011, /* b2 */
    0b11000111, /**/
    0b11111111, /**/
    0b10000010, /**/
    0b11111110, /**/
    0b10000100, /**/
    0b11111100, /**/
    0b10001000, /**/
    0b11111000, /* b3 */
    0b10010000, /**/
    0b11110000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b11111000, /**/
    0b11111000, /**/
    0b10000000, /**/
    0b11100000, /**/
    0b11100000, /**/
    0b10000000, /**/
    0b11111111, /* b1 */
    0b10011001, /**/
    0b11100111, /**/
    0b10011001, /**/
    0b11111111, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /**/
    0b10000000, /* b2 */
    0b10000000, /**/
    0b11111111, /**/
    0b10011001, /**/
    0b11100111, /**/
    0b10011001, /**/
    0b11111111, /**/
    0b10100000, /**/
    0b10100000, /* b3 */
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b10100000, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_farm2[] = {
    /* Top */
    0b11000000, /* b0 */
    0b10100000, /**/
    0b01010000, /**/
    0b00101000, /**/
    0b00010100, /**/
    0b10001010, /**/
    0b11111101, /**/
    0b10001010, /**/
    0b00010100, /* b1 */
    0b00101000, /**/
    0b01010000, /**/
    0b10100000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00010000, /**/
    0b00111000, /**/
    0b11100000, /* b2 */
    0b01110000, /**/
    0b00000000, /**/
    0b00010010, /**/
    0b00100100, /**/
    0b11001000, /**/
    0b11010100, /**/
    0b11100000, /**/
    0b10011000, /* b3 */
    0b01000100, /**/
    0b01100000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Middle */
    0b11111111, /* b0 */
    0b00000000, /**/
    0b01111000, /**/
    0b01001000, /**/
    0b01111000, /**/
    0b00000011, /**/
    0b00000011, /**/
    0b00000011, /**/
    0b01111000, /* b1 */
    0b01001000, /**/
    0b01111000, /**/
    0b00000000, /**/
    0b11111111, /**/
    0b00001010, /**/
    0b00001110, /**/
    0b00001010, /**/
    0b00111111, /* b2 */
    0b00001010, /**/
    0b11001110, /**/
    0b10001010, /**/
    0b00001110, /**/
    0b00011110, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11100100, /* b3 */
    0b11000010, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b10000000, /**/
    0b11111100, /**/
    0b10000010, /**/
    0b10000010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b11111110, /* b1 */
    0b10010010, /**/
    0b11111110, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111000, /* b2 */
    0b10001001, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111011, /**/
    0b10001011, /**/
    0b11111000, /* b3 */
    0b10001001, /**/
    0b11111011, /**/
    0b10001111, /**/
    0b11111110, /**/
    0b10001100, /**/
    0b11111000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_farm[] = {
    /* Top */
    0b11100000, /* b0 */
    0b10100000, /**/
    0b01010000, /**/
    0b00101000, /**/
    0b00010100, /**/
    0b00001010, /**/
    0b00000101, /**/
    0b00001010, /**/
    0b00010100, /* b1 */
    0b00101000, /**/
    0b01010000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11100000, /* b2 */
    0b10100000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11100000, /**/
    0b10100000, /**/
    0b11100000, /* b3 */
    0b11000000, /**/
    0b10000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b11111111, /* b0 */
    0b10000000, /**/
    0b10000000, /**/
    0b11111100, /**/
    0b10000010, /**/
    0b10000010, /**/
    0b11111100, /**/
    0b10000000, /**/
    0b10011110, /* b1 */
    0b10010010, /**/
    0b10011110, /**/
    0b10000000, /**/
    0b11111111, /**/
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111000, /* b2 */
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111000, /**/
    0b10001000, /**/
    0b11111000, /* b3 */
    0b10001001, /**/
    0b11111011, /**/
    0b10001111, /**/
    0b11111110, /**/
    0b10001100, /**/
    0b11111000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmp_lagunita[] = {
    /* Top */
    0b00000001, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111110, /**/
    0b11111111, /**/
    0b11000011, /**/
    0b00000001, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11000000, /**/
    0b11100011, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b00011110, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11100011, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11110000, /**/
    0b11111100, /**/
    0b11111110, /**/
    0b11111111, /**/
    0b00000111, /**/
    0b00000011, /**/
    0b11000011, /**/
    0b11000111, /**/
    0b11001111, /**/
    0b10011111, /**/
    0b11011110, /**/
    0b11000000, /**/
    0b00000011, /**/
    0b11000111, /**/
    0b11111111, /**/
    0b11111110, /**/
    0b11111111, /**/
    0b11000111, /**/
    0b00000011, /**/
    0b00000000, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11000111, /**/
    0b00000011, /**/
    0b00000000, /**/
    0b00000001, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111000, /**/
    0b11100000, /**/
    0b11000001, /**/
    0b00000011, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11000011, /**/
    0b00000001, /**/
    0b00000000, /**/
    0b00000011, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111111, /**/
    0b11000011, /**/
    0b00000011, /**/
    0b00000000, /**/
    0b00011111, /**/
    0b00001111, /**/
    0b00000110, /**/
    0b11000011, /**/
    0b11111111, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111111, /**/
    0b11000011, /**/
    0b00000011, /**/
    0b00000110, /**/
    0b00001111, /**/
    0b00011111, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11000000, /**/
    0b11100011, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b00011110, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11100011, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    /* Bottom */
    0b01000000, /**/
    0b11100000, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111000, /**/
    0b11110000, /**/
    0b11110000, /**/
    0b01110000, /**/
    0b00111000, /**/
    0b00011100, /**/
    0b11001100, /**/
    0b11100000, /**/
    0b01111110, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b11000111, /**/
    0b00001110, /**/
    0b00001110, /**/
    0b11000111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b01111110, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b00001111, /**/
    0b00011111, /**/
    0b00111111, /**/
    0b01111111, /**/
    0b01110000, /**/
    0b11100000, /**/
    0b11100000, /**/
    0b11110000, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b00111111, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00011111, /**/
    0b00111111, /**/
    0b01111111, /**/
    0b11110000, /**/
    0b11100000, /**/
    0b11100000, /**/
    0b11110000, /**/
    0b01111111, /**/
    0b00111111, /**/
    0b00011111, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11100000, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b11100000, /**/
    0b11000001, /**/
    0b00001111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11100000, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11100000, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b11100000, /**/
    0b11000000, /**/
    0b00000000, /**/
    0b00000000, /**/
    0b11000000, /**/
    0b11100000, /**/
    0b01111110, /**/
    0b01111111, /**/
    0b11111111, /**/
    0b11000111, /**/
    0b00001110, /**/
    0b00001110, /**/
    0b11000111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b01111111, /**/
    0b01111110, /**/
    0b11100000, /**/
    0b11000000, /**/
};
