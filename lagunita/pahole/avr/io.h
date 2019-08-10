#pragma once

#define PROGMEM

uint16_t strlen_P(const char* str) { return 0; }
char pgm_read_byte_near(const char* src) {return *src;}
