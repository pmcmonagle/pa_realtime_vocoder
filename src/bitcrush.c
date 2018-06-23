#include "bitcrush.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constructor
bitcrush* bitc_new(int precision) {
	bitcrush* bitc = (bitcrush*) malloc(sizeof(bitcrush));
	if (bitc == NULL) {
		printf("Error while allocating memory for bitcrush module");
		return bitc;
	}

	bitc->precision = pow(10, precision);

	return bitc;
}

float bitc_process(bitcrush* bitc, float input){
	float output = roundf(input * bitc->precision) / bitc->precision;
	return output;
}
