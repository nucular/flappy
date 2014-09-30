#ifndef MENU_H
#define MENU_H

// prototypes
void menu_init();
void menu_deinit();
void menu_update();
void menu_draw();

// bird animation
unsigned char menu_birdframe = 0;
float menu_birdy;

#endif
