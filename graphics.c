#include "graphics.h"

#include "extgraph/extgraph.h"

void graphics_drawbird(unsigned short x, unsigned short y, unsigned char frame)
{
	// ping-pong the three frames
	frame = abs(((frame + 2) % 4) - 2);
	// draw the 16x12 bird animation
	switch (frame)
	{
		case 0:
			GraySprite16_MASK(
				x, y, 12,
				GRAPHICS_BIRD0_LIGHT, GRAPHICS_BIRD0_DARK,
				GRAPHICS_BIRD_MASK, GRAPHICS_BIRD_MASK,
				lightbuffer, darkbuffer
			);
			break;
		case 1:
			GraySprite16_MASK(
				x, y, 12,
				GRAPHICS_BIRD1_LIGHT, GRAPHICS_BIRD1_DARK,
				GRAPHICS_BIRD_MASK, GRAPHICS_BIRD_MASK,
				lightbuffer, darkbuffer
			);
			break;
		case 2:
			GraySprite16_MASK(
				x, y, 12,
				GRAPHICS_BIRD2_LIGHT, GRAPHICS_BIRD2_DARK,
				GRAPHICS_BIRD_MASK, GRAPHICS_BIRD_MASK,
				lightbuffer, darkbuffer
			);
			break;
	}
}

void graphics_drawpipe(unsigned int x, unsigned int openy, unsigned int opensize)
{
	// get the rect positions
	WIN_RECT down = {x + 1, 0, x + 22, openy - opensize - 12};
	WIN_RECT up = {x + 1, openy + opensize + 12, x + 22, LCD_HEIGHT - 1};

	// fill the pipes with dark gray
	FastFillRect(darkbuffer, down.x0, down.y0, down.x1, down.y1, A_XOR);
	FastFillRect(darkbuffer, up.x0, up.y0, up.x1, up.y1, A_XOR);

	// outline the pipes with black
	FastDrawVLine_R(lightbuffer, down.x0, down.y0, down.y1, A_XOR);
	FastDrawVLine_R(lightbuffer, down.x1, down.y0, down.y1, A_XOR);
	FastDrawVLine_R(lightbuffer, up.x0, up.y0, up.y1, A_XOR);
	FastDrawVLine_R(lightbuffer, up.x1, up.y0, up.y1, A_XOR);

	// draw the 24x12 pipe sprites
	GraySpriteX8_XOR(
		x, openy - opensize - 11, 12,
		GRAPHICS_PIPE_DOWN_LIGHT, GRAPHICS_PIPE_DOWN_DARK, 3,
		lightbuffer, darkbuffer
	);
	GraySpriteX8_XOR(
		x, openy + opensize, 12,
		GRAPHICS_PIPE_UP_LIGHT, GRAPHICS_PIPE_UP_DARK, 3,
		lightbuffer, darkbuffer
	);
}

void graphics_drawgrass(unsigned char frame)
{
	int x = LCD_WIDTH + (8 - abs(frame % 8));
	while (x > 0)
	{
		GrayClipSprite8_RPLC_R(
			x, LCD_HEIGHT - 20, 8,
			GRAPHICS_GRASS_LIGHT, GRAPHICS_GRASS_DARK,
			lightbuffer, darkbuffer
		);
		x -= 8;
	}
}

void graphics_drawlogo(unsigned int x, unsigned int y)
{
	GraySpriteX8_MASK(
		x, y, 24,
		GRAPHICS_LOGO_LIGHT, GRAPHICS_LOGO_DARK,
		GRAPHICS_LOGO_LIGHT, GRAPHICS_LOGO_LIGHT, 10,
		lightbuffer, darkbuffer
	);
}
