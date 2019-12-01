#include "Levels.hpp"

const char tutorial0[] PROGMEM = "";
const char tutorial1[] PROGMEM =
    "\tUSE THE D-PAD TO MOVE\n\tON THE SOLID ROCK\n\tAND REACH THE EXIT";
const char tutorial2[] PROGMEM = "BORDERS ARE SOLID ROCK";
const char tutorial3[] PROGMEM = "CLIMB AND DON'T GET STUCK";
const char tutorial4[] PROGMEM = "EAT ROOTS TO GROW";
const char tutorial5[] PROGMEM = "EAT GARBAGE TO SHRINK";
const char tutorial6[] PROGMEM = "DIG AND DON'T GET BURIED";
const char tutorial7[] PROGMEM = "BEWARE OF SPIKES!";

const Levels levelsData[Levels::levelsCount] PROGMEM = {
    /* clang-format off */
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial1,   6, 14,   6, 3,   6, 2,   6, 1,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b1111111111111111, /**/
      0b1111111111111111, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1000000000000001, /**/
      0b1111111111111111, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial2,   7, 0,    5, 13,  5, 14,  5, 15,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000011111, /**/
      0b0000011111111111, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial3,   6, 15,   6, 2,   6, 1,   6, 0,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000100000110000, /**/
      0b0001110000010000, /**/
      0b1111111111111111, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial4,   6, 11,   6, 2,   6, 1,   6, 0,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000100000111101, /**/
      0b0000000000100001, /**/
      0b0000100000101101, /**/
      0b0000100000101101, /**/
      0b1111111111111111, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000100000000000, /**/
      0b0000000000000000, /**/
      0b0000100000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial5,   6, 11,   6, 2,   6, 1,   6, 0,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000100000111101, /**/
      0b0000000000100001, /**/
      0b0000100000101101, /**/
      0b0000100000101101, /**/
      0b1111111111111111, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000100000000000, /**/
      0b0000000000000000, /**/
      0b0000100000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000110000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial6,   1, 15,   7, 2,   7, 1,   7, 0,
    /* Rock */
    {
      0b1111111111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000001, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0011100000111110, /**/
      0b0011100000111110, /**/
      0b0011111111111110, /**/
      0b0011111111111110, /**/
      0b0011111111111110, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,   1, 0,    3, 0,   4, 0,   5, 0,
    /* Rock */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b1110000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000111, /**/
      0b0000000000000011, /**/
      0b1100000000000001, /**/
      0b1100000000000000, /**/
    },
    /* Soil */
    {
      0b0010000000011000, /**/
      0b0010100001111000, /**/
      0b1110111111011000, /**/
      0b0010100000000000, /**/
      0b0010000000000000, /**/
      0b0011100000011000, /**/
      0b0001111111110000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,   5,13,    5, 2,   5, 1,   5, 0,
    /* Rock */
    {
      0b0000001111110101, /**/
      0b0000000001000000, /**/
      0b1111110000000000, /**/
      0b1110110111111110, /**/
      0b1110000110000010, /**/
      0b0000110110111010, /**/
      0b0110110110111110, /**/
      0b0000110110000000, /**/
    },
    /* Soil */
    {
      0b0111110000000000, /**/
      0b0111110000001010, /**/
      0b0000000111111111, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b1000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0110000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000001, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b1000000000000000, /**/
      0b1000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial7,   0,12,    4, 2,   4, 1,   4, 0,
    /* Rock */
    {
      0b1111111111110000, /**/
      0b1100000000011100, /**/
      0b1000000000001100, /**/
      0b0000000000000110, /**/
      0b0000000000000000, /**/
      0b1110010101000011, /**/
      0b1100000000000001, /**/
      0b1000000000000001, /**/
    },
    /* Soil */
    {
      0b0000000000000111, /**/
      0b0011111111100000, /**/
      0b0111111111110000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000001000000, /**/
      0b0001000010110000, /**/
      0b0000000100000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000001, /**/
      0b0000000000000001, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0111111111111110, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,   2,15,    7, 2,   7, 1,   7, 0,
    /* Rock */
    {
      0b0000000000001000, /**/
      0b0100000000001000, /**/
      0b0101000011101000, /**/
      0b0001000000000011, /**/
      0b0101000000000011, /**/
      0b0000000000000011, /**/
      0b1110000000000011, /**/
      0b0000000000000011, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Food */
    {
      0b0100000000000000, /**/
      0b0000000000110000, /**/
      0b0000000000000000, /**/
      0b0100000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000111111111111, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,   0,14,    7, 2,   7, 1,   7, 0,
    /* Rock */
    {
      0b0000000000000001, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
      0b0000000000000011, /**/
    },
    /* Soil */
    {
      0b0000000111000000, /**/
      0b0001110111000000, /**/
      0b0001110111001000, /**/
      0b0001110111001000, /**/
      0b0001110111001000, /**/
      0b0001110111001000, /**/
      0b0001110111001000, /**/
      0b0001110000001000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,   0,14,    7, 8,   7, 7,   7, 6,
    /* Rock */
    {
      0b1000000000000001, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
      0b1100000000000011, /**/
    },
    /* Soil */
    {
      0b0000000000000000, /**/
      0b0000111001110000, /**/
      0b0000111001110000, /**/
      0b0000111001110000, /**/
      0b0000111001110000, /**/
      0b0000111001110000, /**/
      0b0000111001110000, /**/
      0b0000110000110000, /**/
    },
    /* Food */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000001000000, /**/
    },
    /* Poop */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0011000000001100, /**/
    }
  },
  {
    /* Tutorial, Goal,    Head,   Body,   Tail     */
    tutorial0,    3,0,    4, 5,   4, 6,   4, 7,
    /* Rock */
    {
      0b1000000000000000, /**/
      0b1000000000000000, /**/
      0b1111000000000000, /**/
      0b0100000000000000, /**/
      0b0100100000000000, /**/
      0b0100111111111110, /**/
      0b0111111111111110, /**/
      0b0000000000000000, /**/
    },
    /* Soil */
    {
      0b0000110000000000, /**/
      0b0000111111000010, /**/
      0b0000111111000010, /**/
      0b0000100000000010, /**/
      0b1000000000000010, /**/
      0b1011000000000000, /**/
      0b1000000000000000, /**/
      0b1000000000000000, /**/
    },
    /* Food */
    {
      0b0100000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0011000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    },
    /* Poop */
    {
      0b0000000000000010, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000010, /**/
    },
    /* Nail */
    {
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000011111100, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
      0b0000000000000000, /**/
    }
  },
    /* clang-format on */
};

const char* Levels::tutorial() const {
  return pgm_read_ptr(&_tutorial);
}

const void Levels::goal(Cell* res) const {
  res->x = pgm_read_byte(&_goalX);
  res->y = pgm_read_byte(&_goalY);
}

const void Levels::head(Cell* res) const {
  res->x = pgm_read_byte(&_headX);
  res->y = pgm_read_byte(&_headY);
}

const void Levels::body(Cell* res) const {
  res->x = pgm_read_byte(&_bodyX);
  res->y = pgm_read_byte(&_bodyY);
}

const void Levels::tail(Cell* res) const {
  res->x = pgm_read_byte(&_tailX);
  res->y = pgm_read_byte(&_tailY);
}

const void Levels::rock(uint16_t* res) const {
  for (uint8_t row = 0; row < 8; row++) {
    res[row] = pgm_read_word(&_rock[row]);
  }
}

const void Levels::soil(uint16_t* res) const {
  for (uint8_t row = 0; row < 8; row++) {
    res[row] = pgm_read_word(&_soil[row]);
  }
}

const void Levels::food(uint16_t* res) const {
  for (uint8_t row = 0; row < 8; row++) {
    res[row] = pgm_read_word(&_food[row]);
  }
}

const void Levels::poop(uint16_t* res) const {
  for (uint8_t row = 0; row < 8; row++) {
    res[row] = pgm_read_word(&_poop[row]);
  }
}

const void Levels::nail(uint16_t* res) const {
  for (uint8_t row = 0; row < 8; row++) {
    res[row] = pgm_read_word(&_nail[row]);
  }
}

const void Levels::setupCells(Cell* rGoal,
                              Cell* rHead,
                              Cell* rBody,
                              Cell* rTail,
                              const uint8_t id) {
  levelsData[id].goal(rGoal);
  levelsData[id].head(rHead);
  levelsData[id].body(rBody);
  levelsData[id].tail(rTail);
}

const void Levels::setupTiles(uint16_t* rRock,
                              uint16_t* rSoil,
                              uint16_t* rFood,
                              uint16_t* rPoop,
                              uint16_t* rNail,
                              const uint8_t id) {
  levelsData[id].rock(rRock);
  levelsData[id].soil(rSoil);
  levelsData[id].food(rFood);
  levelsData[id].poop(rPoop);
  levelsData[id].nail(rNail);
}

const char* Levels::tutorial(const uint8_t id) {
  return levelsData[id].tutorial();
}
