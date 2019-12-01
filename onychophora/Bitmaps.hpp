#pragma once

const unsigned char PROGMEM bmpRock[] = {
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
};

const unsigned char PROGMEM bmpSoil[] = {
    0b01010101, /**/
    0b10101010, /**/
    0b01010101, /**/
    0b10101010, /**/
    0b01010101, /**/
    0b10101010, /**/
    0b01010101, /**/
    0b10101010, /**/
};

const unsigned char PROGMEM bmpFood[] = {
    0b00000000, /**/
    0b00010010, /**/
    0b00111110, /**/
    0b00111100, /**/
    0b01111000, /**/
    0b01111000, /**/
    0b01001100, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpGoal[] = {
    0b00000000, /**/
    0b11111000, /**/
    0b00000100, /**/
    0b00000010, /**/
    0b00000010, /**/
    0b00000100, /**/
    0b11111000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpPoop[] = {
    0b10000000, /**/
    0b11000000, /**/
    0b11110000, /**/
    0b11111100, /**/
    0b11111110, /**/
    0b11101000, /**/
    0b11100000, /**/
    0b10000000, /**/
};

const unsigned char PROGMEM bmpNail[] = {
    0b00000000, /**/
    0b00000000, /**/
    0b10000000, /**/
    0b11100000, /**/
    0b11111110, /**/
    0b11100000, /**/
    0b10000000, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpWormHead[] = {
    /* 0 degrees */
    0b01111110, /**/
    0b01111110, /**/
    0b01011110, /**/
    0b01010010, /**/
    0b01010010, /**/
    0b01011110, /**/
    0b00011100, /**/
    0b00000000, /**/
    /* 90 degrees */
    0b00000000, /**/
    0b11111100, /**/
    0b11100110, /**/
    0b11100110, /**/
    0b11111110, /**/
    0b11000000, /**/
    0b11111100, /**/
    0b00000000, /**/
    /* 180 degrees */
    0b00000000, /**/
    0b00011100, /**/
    0b01011110, /**/
    0b01010010, /**/
    0b01010010, /**/
    0b01011110, /**/
    0b01111110, /**/
    0b01111110, /**/
    /* 270 degrees */
    0b00000000, /**/
    0b00111111, /**/
    0b01100111, /**/
    0b01100111, /**/
    0b01111111, /**/
    0b00000011, /**/
    0b00111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpWormBody[] = {
    /* 0 degrees */
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    0b01111110, /**/
    /* 90 degrees */
    0b00000000, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b11111111, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpWormTail[] = {
    /* 0 degrees */
    0b00000000, /**/
    0b00111000, /**/
    0b01111000, /**/
    0b01111000, /**/
    0b01111100, /**/
    0b01111100, /**/
    0b01111110, /**/
    0b01111110, /**/
    /* 90 degrees */
    0b00000000, /**/
    0b00000011, /**/
    0b00001111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b00111111, /**/
    0b00000000, /**/
    /* 180 degrees */
    0b01111110, /**/
    0b01111110, /**/
    0b01111100, /**/
    0b01111100, /**/
    0b01111000, /**/
    0b01111000, /**/
    0b00111000, /**/
    0b00000000, /**/
    /* 270 degrees */
    0b00000000, /**/
    0b11000000, /**/
    0b11110000, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111100, /**/
    0b00000000, /**/
};

const unsigned char PROGMEM bmpWormJoin[] = {
    /* 0 degrees */
    0b01111110, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b00111111, /**/
    0b00011111, /**/
    0b00000000, /**/
    /* 90 degrees */
    0b01111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111100, /**/
    0b11111000, /**/
    0b00000000, /**/
    /* 180 degrees */
    0b00000000, /**/
    0b11111000, /**/
    0b11111100, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b11111110, /**/
    0b01111110, /**/
    /* 270 degrees */
    0b00000000, /**/
    0b00011111, /**/
    0b00111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111111, /**/
    0b01111110, /**/
};

const unsigned char PROGMEM bmpArrow[] = {
    0b00000000, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b00011100, /**/
    0b01111111, /**/
    0b00111110, /**/
    0b00011100, /**/
    0b00001000, /**/
};

const unsigned char PROGMEM bmpLogo[] = {
    /* Top */
    0b00000000,
    0b00000110,
    0b00000111,
    0b00000011,
    0b00000111,
    0b10001110,
    0b11111100,
    0b11110000,
    0b00110000,
    0b10110000,
    0b00110000,
    0b10110000,
    0b00110000,
    0b00111000,
    0b01111100,
    0b11101110,
    0b11000111,
    0b00000011,
    0b00000111,
    0b10000110,
    0b11110000,
    0b01110000,
    0b11110000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00010000,
    0b00010000,
    0b11110000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11100000,
    0b00110000,
    0b00010000,
    0b10000000,
    0b11000000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b01110000,
    0b01100000,
    0b01000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b11110000,
    0b01110000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00000000,
    0b10000000,
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b01110000,
    0b11100000,
    0b11000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b11110000,
    0b11100000,
    0b00000000,
    0b10000000,
    0b11110000,
    0b01110000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00000000,
    0b10000000,
    0b11000000,
    0b01100000,
    0b01100000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b01110000,
    0b11100000,
    0b11000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b11110000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11000000,
    0b11110000,
    0b11110000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    /* Bottom */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b11111111,
    0b11111111,
    0b00011000,
    0b00110010,
    0b00110100,
    0b10110100,
    0b11110100,
    0b11110010,
    0b00011000,
    0b00001100,
    0b00000111,
    0b10000011,
    0b11111000,
    0b11111110,
    0b00001111,
    0b00000011,
    0b00000000,
    0b00000001,
    0b00000111,
    0b10001110,
    0b11111100,
    0b11111111,
    0b00000011,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b11111111,
    0b11111111,
    0b00000011,
    0b00000001,
    0b10000000,
    0b11110000,
    0b11111111,
    0b00011111,
    0b00111000,
    0b00110000,
    0b10110000,
    0b11110000,
    0b11110000,
    0b00011000,
    0b00011000,
    0b00001000,
    0b00000000,
    0b10000000,
    0b11111000,
    0b11111111,
    0b00000111,
    0b00000011,
    0b00000011,
    0b10000011,
    0b11111111,
    0b11111111,
    0b00000111,
    0b10000000,
    0b11111111,
    0b11111111,
    0b00011000,
    0b00110000,
    0b00110000,
    0b10110000,
    0b11110000,
    0b11110000,
    0b00011000,
    0b00001100,
    0b00000111,
    0b10000011,
    0b11111000,
    0b11111110,
    0b00001111,
    0b00000011,
    0b00000011,
    0b00000011,
    0b00000011,
    0b10000001,
    0b11100001,
    0b11111000,
    0b00111111,
    0b00000111,
    0b00000011,
    0b10000011,
    0b11100011,
    0b11111111,
    0b00111111,
    0b00000111,
    0b10000000,
    0b11111111,
    0b11111111,
    0b00011000,
    0b00110000,
    0b00110000,
    0b10110000,
    0b11110000,
    0b11110000,
    0b00011000,
    0b00001100,
    0b00000111,
    0b00000011,
    0b10000000,
    0b11110000,
    0b11111110,
    0b00011111,
    0b00000011,
    0b00001110,
    0b00111110,
    0b10110010,
    0b11100011,
    0b11100001,
    0b00110000,
    0b00111100,
    0b00001110,
    0b00000111,
    0b00000111,
    0b00000110,
    0b00000111,
    0b10111111,
    0b11111110,
    0b11110000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
};
