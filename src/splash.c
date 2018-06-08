/*
	MIT License

	Copyright (c) 2018 Gabriel Mineiro

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/
/**
 * Provides a splash screen
 */

#include "splash.h"
#include "divboy.h"

#include "gba_video.h"
#include "gba_systemcalls.h"
#include "gba_input.h"
#include "gba_interrupt.h"
#include "pcx.h"
#include "fade.h"

#include <stdlib.h>

#include "splash_pcx.h"



/**
 * @brief Wait for a number of frames
 *
 * @param frames each second has 60 frames
 */
void wait(unsigned int frames)
{
	do {
		VBlankIntrWait();
		frames--;
	} while (frames);
}

void ShowSplashScreen(void)
{
	u16 PaletteBuffer[256];

	// Set video to bitmap 8bpp mode with palette. Requires BG2_ON to work.
	SetMode(MODE_4 | BG2_ON);

	// Decode the splash.pcx into VRAM data
	DecodePCX(splash_pcx, (u16*)VRAM, PaletteBuffer);

	// Fade-in
	FadeToPalette(PaletteBuffer, 60);
	// Wait for 3 seconds
	wait(3*60);
	// Fade-out
	FadeToGrayScale(31, 60);
}