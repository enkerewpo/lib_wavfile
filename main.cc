/*
This example program makes use of the simple
sound library to generate a sine wave and write the
output to sound.wav.
For complete documentation on the library, see:
http://www.nd.edu/~dthain/courses/cse20211/fall2013/wavfile
Go ahead and modify this program for your own purposes.
*/


#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cerrno>

#include "wavfile.h"

const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND * 2);

short waveform[NUM_SAMPLES];

int main() {

	memset(waveform, 0, sizeof waveform);
	double frequency = 440.0; // note C4 frequency
	int volume = 32000;
	// int length = NUM_SAMPLES;
	int length = 109;

	for(int i = 0; i < length; i++) {
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
		waveform[i] += volume * sin(frequency * t * 2 * M_PI);
	}

	char output_name[] = "sound.wav";
	FILE *f = wavfile_open(output_name);
	if(!f) {
		printf("couldn't open %s for writing: %s\n", output_name, strerror(errno));
		return 1;
	}
	else {
		printf("successfully writing waveform to file - %s\n", output_name);
	}

	wavfile_write(f, waveform, length);
	wavfile_close(f);

	return 0;
}