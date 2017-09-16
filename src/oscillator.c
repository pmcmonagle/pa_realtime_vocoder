#include "oscillator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

// Constructor
// Gain should be between 0 and 1
// Frequency is controlled via the size of the table, calculated as
// sample_rate / frequency. Lower frequencies require large tables.
oscillator* osc_new(float gain, float frequency, int sample_rate) {
	int table_size = (int) (sample_rate / frequency),
		i;

	oscillator* osc = (oscillator*) malloc(sizeof(oscillator));
	if (osc == NULL) {
		printf("Error while allocating memory for oscillator");
		return osc;
	}

	osc->wave_table = malloc(table_size * sizeof(float));
	osc->table_size = table_size;
	osc->frequency = frequency;
	osc->phase = 0;

	// Initialize the wave_table.
	// Let's start with sine, and add others later.
	for (i=0; i<table_size; i++) {
		osc->wave_table[i] = (float) sin(
			((double) i / (double) table_size) * M_PI * 2.0
		) * gain;
	}

	return osc;
}

// Simply return the value at our current position in the
// wave_table; rolling over if necessary.
float osc_process(oscillator* osc) {
	float out = osc->wave_table[osc->phase];
	osc->phase++;

	if (osc->phase >= osc->table_size)
		osc->phase -= osc->table_size;

	return out;
}

// Destructor
void osc_destroy(oscillator* osc) {
	free(osc->wave_table);
	free(osc);
}
