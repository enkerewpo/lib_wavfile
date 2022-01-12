/*
A simple sound library for CSE 20211 by Douglas Thain.
This work is made available under the Creative Commons Attribution license.
https://creativecommons.org/licenses/by/4.0/

For course assignments, you should not change this file.
For complete documentation, see:
http://www.nd.edu/~dthain/courses/cse20211/fall2013/wavfile
*/

#ifndef WAVFILE_H
#define WAVFILE_H

#pragma warning(disable : 4996)

#include <cstdio>
#include <cinttypes>
#include <cmath>

const double M_PI = acos(-1.);

FILE * wavfile_open( const char *filename );
void wavfile_write( FILE *file, short data[], int length );
void wavfile_close( FILE * file );

constexpr auto WAVFILE_SAMPLES_PER_SECOND = 48000;

#endif