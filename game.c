#include "game.h"

void game_init(enum GameState oldgs)
{
	game_birdx = LCD_WIDTH / 5;
}

void game_deinit(enum GameState newgs)
{
}

void game_update()
{
	game_birdvy = game_birdvy + GAME_GRAVITY;
	game_birdy = game_birdy + game_birdvy;

	if (framecounter&1)
		game_birdframe++;
}

void game_draw()
{
	if (game_birdy >= 0 && game_birdy + 12 < LCD_HEIGHT)
		graphics_drawbird(game_birdx, game_birdy, game_birdframe);
}

void game_flap()
{
	game_birdvy = -GAME_FLAPSTRENGTH;
}
