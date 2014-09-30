#include "menu.h"

void menu_init(enum GameState oldgs)
{
}

void menu_deinit(enum GameState newgs)
{
}

void menu_draw()
{
	graphics_drawbird((int)(LCD_WIDTH / 2) - 8, 45 + menu_birdy, menu_birdframe);
	graphics_drawlogo((int)(LCD_WIDTH / 2) - 40, 10);
}

void menu_update()
{
	// every second frame
	if (framecounter&1)
		menu_birdframe++;
	
	// bird "bobbing"
	menu_birdy = sin(framecounter / 3) * 2;
}
