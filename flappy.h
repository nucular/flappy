#ifndef FLAPPY_H
#define FLAPPY_H

// game states
enum GameState {GS_NONE, GS_MENU, GS_GAME, GS_GAMEOVER};
enum GameState gs = GS_NONE;

long int framecounter;

unsigned char birdframe;
float birdx;

// prototypes
void error(char*);
void switchgs(enum GameState);

// pointers to the grayscale planes
void *lightplane;
void *darkplane;
// double-buffering
void *buffermem;
void *lightbuffer;
void *darkbuffer;

#endif
