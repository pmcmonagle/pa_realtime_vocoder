#include "oscillator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

// Constructor
oscillator* osc_new(float frequency, int sample_rate, int frames_per_buffer) {
	int i;
	// TODO
	// Frequency should be calculated from the sample_rate,
	// frames_per_buffer and the TABLE_SIZE
	float gain = 0.6;
	float freq = 4.0;

	oscillator* osc = (oscillator*) malloc(sizeof(oscillator));
	if (osc == NULL) {
		printf("Error while allocating memory for oscillator");
		return osc;
	}

	osc->frames_per_buffer = frames_per_buffer;
	osc->frequency = frequency;
	osc->phase = 0;

	// Initialize the wave_table.
	// Let's start with sine, and add others later.
	for (i=0; i<TABLE_SIZE; i++) {
		osc->wave_table[i] = (float) sin(
			(((double) i / (double) TABLE_SIZE) * M_PI * 2.0) * freq 
		) * gain;
	}

	return osc;
}

// Simply return the value at our current position in the
// wave_table; rolling over if necessary.
float osc_process(oscillator* osc) {
	float out = osc->wave_table[osc->phase];
	osc->phase++;

	if (osc->phase >= TABLE_SIZE)
		osc->phase -= TABLE_SIZE;

	return out;
}

// Destructor
void osc_destroy(oscillator* osc) {
	free(osc);
}
