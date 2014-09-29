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
BOOL init()
{
	// start the random number generator
	randomize();

	// allocate our graphic buffers
	buffermem = malloc(LCD_WIDTH * LCD_HEIGHT * 2);
	if (!buffermem)
	{
		// not enough RAM
		DlgMessage(LC_ERROR, LC_MEMORY_ERROR_TEXT, BT_OK, BT_NONE);
		return FALSE;
	}
	lightbuffer = buffermem;
	darkbuffer = buffermem + LCD_WIDTH * LCD_HEIGHT;

	// quit if we can't switch to grayscale
	if (!GrayOn())
	{
		DlgMessage(LC_ERROR, LC_GRAYSCALE_ERROR_TEXT, BT_OK, BT_NONE);
		return FALSE;
	}

	// clear the screen
	ClrScr();

	// get the grayscale plane pointers
	lightplane = GrayGetPlane(LIGHT_PLANE);
	darkplane = GrayGetPlane(DARK_PLANE);

	return TRUE;
}

// clean up and exit gracefully
void deinit()
{
	if (buffermem)
		free(buffermem);
	// turn off or we'd crash the calc
	GrayOff();
}

// entry point
void _main(void)
{
	// some variables for the main loop
	unsigned int lasttick = 0;
	void *keyqueue = kbd_queue();
	unsigned short key;

	if (!init())
	{
		// something went horribly wrong
		deinit();
		return;
	}

	// start at the menu
	gs = GS_MENU;
	
	// main loop
	running = TRUE;
	while (running)
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
					running = FALSE;
				else
				{
					switch (gs)
					{
						case GS_MENU:
							if (key == KEY_ENTER)
								switchgs(GS_GAME);
							else if (key == KEY_ESC)
								running = FALSE;

						case GS_GAME:
							if (key == KEY_ENTER)
								game_flap();
							else if (key == KEY_ESC)
								switchgs(GS_MENU);

						case GS_GAMEOVER:
							if (key == KEY_ENTER)
								switchgs(GS_GAME);
							else if (key == KEY_ESC)
								switchgs(GS_MENU);
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
			FadeOutToBlack_RL_R(lightplane, darkplane, LCD_HEIGHT, LCD_WIDTH / 8, 20);
			break;
		default:
			break;
	}
	// initialize
	switch (newgs)
	{
		default:
			break;
	}
	gs = newgs;
}
