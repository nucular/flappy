#ifndef GRAPHICS_H
#define GRAPHICS_H

static unsigned short int GRAPHICS_BIRD0_LIGHT[] = {
	0b0000001111100000,
	0b0000111110010000,
	0b0001111100001000,
	0b0111111100010100,
	0b1000011100010100,
	0b1000001110000100,
	0b1000001111111110,
	0b0100011111111111,
	0b0011100111111110,
	0b0010000011111110,
	0b0001100001111100,
	0b0000011110000000
};

static unsigned short int GRAPHICS_BIRD0_DARK[] = {
	0b0000001111100000,
	0b0000110010010000,
	0b0001000100001000,
	0b0111100100010100,
	0b1000010100010100,
	0b1000001010000100,
	0b1000001001111110,
	0b0100010010000001,
	0b0011111101111110,
	0b0011111110000010,
	0b0001111111111100,
	0b0000011110000000
};

static unsigned short int GRAPHICS_BIRD1_LIGHT[] = {
	0b0000001111100000,
	0b0000111110010000,
	0b0001111100001000,
	0b0011111100010100,
	0b0111111100010100,
	0b0111111110000100,
	0b1000001111111110,
	0b1000001111111111,
	0b0111110111111110,
	0b0010000011111110,
	0b0001100001111100,
	0b0000011110000000
};

static unsigned short int GRAPHICS_BIRD1_DARK[] = {
	0b0000001111100000,
	0b0000110010010000,
	0b0001000100001000,
	0b0010000100010100,
	0b0100000100010100,
	0b0111110010000100,
	0b1000001001111110,
	0b1000001010000001,
	0b0111111101111110,
	0b0011111110000010,
	0b0001111111111100,
	0b0000011110000000
};

static unsigned short int GRAPHICS_BIRD2_LIGHT[] = {
	0b0000001111100000,
	0b0000111110010000,
	0b0001111100001000,
	0b0011111100010100,
	0b0111111100010100,
	0b0111111110000100,
	0b0111111111111110,
	0b1000011111111111,
	0b1000100111111110,
	0b1001000011111110,
	0b0111000001111100,
	0b0000111110000000
};

static unsigned short int GRAPHICS_BIRD2_DARK[] = {
	0b0000001111100000,
	0b0000110010010000,
	0b0001000100001000,
	0b0010000100010100,
	0b0100000100010100,
	0b0100000010000100,
	0b0111100001111110,
	0b1000010010000001,
	0b1000111101111110,
	0b1001111110000010,
	0b0111111111111100,
	0b0000111110000000
};

static unsigned char GRAPHICS_PIPE_DOWN_LIGHT[] = {
	0b01000000, 0b00000000, 0b00000010,
	0b11111111, 0b11111111, 0b11111111,
	0b10000000, 0b00000000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b11100000, 0b00011111, 0b10000001,
	0b11111111, 0b11111111, 0b11111111
};

static unsigned char GRAPHICS_PIPE_DOWN_DARK[] = {
	0b01111111, 0b11111111, 0b11111110,
	0b11111111, 0b11111111, 0b11111111,
	0b11111111, 0b11111111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000000, 0b01111111,
	0b11111111, 0b11111111, 0b11111111
};

static unsigned char GRAPHICS_PIPE_UP_LIGHT[] = {
	0b11111111, 0b11111111, 0b11111111,
	0b11100000, 0b00011111, 0b10000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000001, 0b11111000, 0b00000001,
	0b10000000, 0b00000000, 0b00000001,
	0b11111111, 0b11111111, 0b11111111,
	0b01000000, 0b00000000, 0b00000010
};

static unsigned char GRAPHICS_PIPE_UP_DARK[] = {
	0b11111111, 0b11111111, 0b11111111,
	0b10000000, 0b00000000, 0b01111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b10000000, 0b00000111, 0b11111111,
	0b11111111, 0b11111111, 0b11111111,
	0b11111111, 0b11111111, 0b11111111,
	0b01111111, 0b11111111, 0b11111110
};

#endif
