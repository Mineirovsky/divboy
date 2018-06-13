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

#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>
#include <stdio.h>
#include <stdlib.h>

#include "splash.h"
#include "divboy.h"

void VBlankInterrupt(void)
{
	frame += 1;
	scanKeys();
}

inline void Init(void)
{
	/* Initialize interrupts */
	irqInit();

	/* Bind function for VBlank interrupt */
	irqSet(IRQ_VBLANK, VBlankInterrupt);

	/* Enable VBlank interrupt */
	irqEnable(IRQ_VBLANK);

	/* Allow interrupts */
	REG_IME = 1;
}

int main(void) {
	Init();

	ShowSplashScreen();

	while(1)
	{
		VBlankIntrWait();
	}
}


