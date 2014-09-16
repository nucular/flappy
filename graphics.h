#ifndef GRAPHICS_H
#define GRAPHICS_H

static unsigned short int GRAPHICS_BIRD_LIGHT[] = {
	0b0000111111110000,
	0b0001111110001000,
	0b0111111110010100,
	0b1000011110000100,
	0b1000001111000100,
	0b1000001111111110,
	0b0100011111111111,
	0b0011111111111110,
	0b0010000001111110,
	0b0001000000111100,
	0b0000111111000000
};

static unsigned short int GRAPHICS_BIRD_DARK[] = {
	0b0000111111110000,
	0b0001000010001000,
	0b0111100010010100,
	0b1000010010000100,
	0b1000001001000100,
	0b1000001000111110,
	0b0100010001000001,
	0b0011100010111110,
	0b0011111111000010,
	0b0001111111111100,
	0b0000111111000000
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