#pragma once

/* List of headers included by all the other headers. */
#include "Tinyfont.hpp"
#include <Arduboy2.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

extern "C" {
#include <stdint.h>
}

/* Enum class for the 6 input buttons. */
enum class Input : uint8_t { left, right, up, down, a, b };
