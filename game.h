#ifndef GAME_H
#define GAME_H

#define GAME_GRAVITY 0.7
#define GAME_FLAPSTRENGTH 5
#define GAME_OPENY 10
#define GAME_MAXPIPES 100

// prototypes
void game_init();
void game_deinit();
void game_update();
void game_draw();
void game_flap();

// bird animation
unsigned char game_birdframe = 0;
unsigned short game_birdy;
unsigned short game_birdx;
float game_birdvy = 0;

// pipes
typedef struct {
	unsigned short x;
	unsigned short openy;
} Pipe;
Pipe *game_pipes = NULL;

#endif
