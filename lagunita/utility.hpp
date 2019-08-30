#pragma once

/* List of headers included by all the other headers. */
#include <Arduboy2.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "Tinyfont.hpp"

extern "C" {
#include <stdint.h>
}

/* Enum class for the 6 input buttons. */
enum class Input : uint8_t { left, right, up, down, a, b };
