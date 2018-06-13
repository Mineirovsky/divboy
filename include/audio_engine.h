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
#ifndef _audio_engine_h_
#define _audio_engine_h_

#if __cplusplus
extern "C" {
#endif

/* Note structure */
typedef enum
{
	NOTE_C,
	NOTE_CS, /* C#/Db */
	NOTE_D,
	NOTE_DS, /* D#/Eb */
	NOTE_E,
	NOTE_F,
	NOTE_FS, /* F#/Gb */
	NOTE_G,
	NOTE_GS, /* G#/Ab */
	NOTE_A,
	NOTE_AS,  /* A#/Bb */
	NOTE_B
} NoteName;

typedef struct
{
	NoteName     note;
	unsigned int octave;
} pitch;


typedef struct
{
	pitch pitch;
	duration
} note;


/* Sequence structure */

/* Piece structure */

#if __cplusplus
} /* extern "C" */
#endif
#endif /* _audio_engine_h_ */