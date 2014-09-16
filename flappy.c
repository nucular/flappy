// 2014 by nucular, MIT license
// tigcc -O2 -Wall flappy.c extgraph/extgraph.a

#include "flappy.h"
#include "graphics.h"

#include <tigcclib.h>
#include "extgraph/extgraph.h"

// pointers to the grayscale planes
void *lightplane;
void *darkplane;

void drawBird(unsigned short x, unsigned short y)
{
	// draw the 16x11 bird sprite
	GraySprite16_XOR(
		x, y, 11,
		GRAPHICS_BIRD_LIGHT, GRAPHICS_BIRD_DARK,
		lightplane, darkplane
	);
}

void drawPipe(unsigned int x, unsigned int openy, unsigned int opensize)
{
	// get the rect positions
	WIN_RECT down = {x + 1, 0, x + 22, openy - opensize - 12};
	WIN_RECT up = {x + 1, openy + opensize + 12, x + 22, LCD_HEIGHT - 1};

	// fill the pipes with dark gray
	FastFillRect(darkplane, down.x0, down.y0, down.x1, down.y1, A_XOR);
	FastFillRect(darkplane, up.x0, up.y0, up.x1, up.y1, A_XOR);

	// outline the pipes with black
	FastDrawVLine_R(lightplane, down.x0, down.y0, down.y1, A_XOR);
	FastDrawVLine_R(lightplane, down.x1, down.y0, down.y1, A_XOR);
	FastDrawVLine_R(lightplane, up.x0, up.y0, up.y1, A_XOR);
	FastDrawVLine_R(lightplane, up.x1, up.y0, up.y1, A_XOR);

	// draw the 24x12 pipe sprites
	GraySpriteX8_XOR(
		x, openy - opensize - 11, 12,
		GRAPHICS_PIPE_DOWN_LIGHT, GRAPHICS_PIPE_DOWN_DARK, 3,
		lightplane, darkplane
	);
	GraySpriteX8_XOR(
		x, openy + opensize, 12,
		GRAPHICS_PIPE_UP_LIGHT, GRAPHICS_PIPE_UP_DARK, 3,
		lightplane, darkplane
	);
}

// entry point
void _main(void)
{
	unsigned int lasttick = 0;
	void *keyqueue = kbd_queue();
	unsigned short key;

	short birdx = 0;
	short pipex = LCD_WIDTH - 24;

	// quit if we can't switch to grayscale
	if (!GrayOn())
		return;

	// clear the screen
	ClrScr();

	// set the clipping area to the full screen
	SetCurAttr(A_XOR);
	SetCurClip(ScrRect);

	// get the grayscale plane pointers
	lightplane = GrayGetPlane(LIGHT_PLANE);
	darkplane = GrayGetPlane(DARK_PLANE);
	
	// pre-draw so the XOR clearing works
	drawBird(birdx, 40);
	drawPipe(pipex, 50, 15);
	
	// main loop
	while (TRUE)
	{
		// run at 20 fps
		if (FiftyMsecTick != lasttick)
		{
			// Check for keypresses
			if (OSdequeue(&key, keyqueue))
			{
				if (key == KEY_ESC)
					break;
			}
			
			// clear, move and draw using XOR
			drawBird(birdx, 40);
			drawPipe(pipex, 50, 15);
			birdx++;
			pipex--;
			drawBird(birdx, 40);
			drawPipe(pipex, 50, 15);
			
			// stuff isn't clipped to the screen yet
			if (birdx >= LCD_WIDTH - 16 || pipex <= 0)
				break;
			
			lasttick = FiftyMsecTick;
		}
	}
	
	// this is important!
	GrayOff();
}
