#ifndef FLAPPY_H
#define FLAPPY_H

// game states
enum GameState {GS_MENU, GS_GAME, GS_GAMEOVER};
unsigned short running;
enum GameState gs;

long int framecounter;

unsigned char birdframe;
float birdx;

// prototypes
void switchgs(enum GameState);

// pointers to the grayscale planes
void *lightplane;
void *darkplane;
// double-buffering
void *buffermem;
void *lightbuffer;
void *darkbuffer;

#endif
