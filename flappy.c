// 2014 by nucular, MIT license
// tigcc -O2 -Wall flappy.c extgraph/extgraph.a -DLC_LANG=LC_ENGLISH

#include "flappy.h"

// configuration headers
#include "locale.h"
#include "config.h"

#include <tigcclib.h>

#include "graphics.c"
#include "menu.c"
#include "game.c"
#include "gameover.c"

// allocate and set up stuff
void init()
{
	// start the random number generator
	randomize();

	// allocate our graphic buffers
	buffermem = malloc(LCD_WIDTH * LCD_HEIGHT * 2);
	// not enough RAM
	if (!buffermem)
		error(LC_MEMORY_ERROR_TEXT);
	lightbuffer = buffermem;
	darkbuffer = buffermem + LCD_WIDTH * LCD_HEIGHT;

	// quit if we can't switch to grayscale
	if (!GrayOn())
		error(LC_GRAYSCALE_ERROR_TEXT);

	// clear the screen
	ClrScr();

	// get the grayscale plane pointers
	lightplane = GrayGetPlane(LIGHT_PLANE);
	darkplane = GrayGetPlane(DARK_PLANE);
}

// clean up and exit gracefully
void deinit()
{
	if (buffermem)
		free(buffermem);
	// turn this off or we'd crash the calc
	GrayOff();
	// for good measure
	ClrScr();
}

// generic error handler
void error(char* text)
{
	switchgs(GS_NONE);
	deinit();
	DlgMessage(LC_ERROR, text, BT_OK, BT_NONE);
	exit(1);
}

// entry point
void _main(void)
{
	// some variables for the main loop
	unsigned int lasttick = 0;
	void *keyqueue = kbd_queue();
	unsigned short key;

	// initiate all the stuff
	init();

	// start at the menu
	switchgs(GS_MENU);
	
	// main loop
	while (gs != GS_NONE)
	{
		// run at 20 fps
		if (FiftyMsecTick != lasttick)
		{
			// Check for keypresses
			if (!OSdequeue(&key, keyqueue))
			{
				if (key == KEY_ON)
					off();
				else if (key == KEY_QUIT)
					switchgs(GS_NONE);
				else
				{
					switch (gs)
					{
						case GS_MENU:
							if (key == KEY_ENTER)
								switchgs(GS_GAME);
							else if (key == KEY_ESC)
								switchgs(GS_NONE);
							break;
						case GS_GAME:
							if (key == KEY_ENTER)
								game_flap();
							else if (key == KEY_ESC)
								switchgs(GS_MENU);
							break;
						case GS_GAMEOVER:
							if (key == KEY_ENTER)
								switchgs(GS_GAME);
							else if (key == KEY_ESC)
								switchgs(GS_MENU);
							break;
						default:
							break;
					}
				}
			}

			// draw to the buffers
			GrayClearScreen2B(lightbuffer, darkbuffer);
			switch (gs)
			{
				case GS_MENU:
					menu_update();
					menu_draw();
					break;
				case GS_GAME:
					game_update();
					game_draw();
					break;
				case GS_GAMEOVER:
					gameover_update();
					game_draw();
					gameover_draw();
					break;
				default:
					break;
			}

			// flip the buffers
			FastCopyScreen(darkbuffer, darkplane);
			FastCopyScreen(lightbuffer, lightplane);

			lasttick = FiftyMsecTick;
			framecounter++;
		}
	}

	// important!
	deinit();
}

// switch between gamestates
void switchgs(enum GameState newgs)
{
	FastClearScreen_R(lightbuffer);
	FastClearScreen_R(darkbuffer);

	birdframe = 0;
	// deinitialize
	switch (gs)
	{
		case GS_MENU:
			menu_deinit(newgs);
			break;
		case GS_GAME:
			game_deinit(newgs);
			break;
		case GS_GAMEOVER:
			gameover_deinit(newgs);
			break;
		default:
			break;
	}
	// initialize
	switch (newgs)
	{
		case GS_MENU:
			menu_init(gs);
			break;
		case GS_GAME:
			game_init(gs);
			break;
		case GS_GAMEOVER:
			gameover_init(gs);
			break;
		default:
			break;
	}
	gs = newgs;
}
