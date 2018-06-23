#include "include/biquad.h"
#include "src/oscillator.h"
#include "src/bitcrush.h"
#include "portaudio.h"
#include <stdio.h>

// 44100, 22050, 11025
#define NUM_SECONDS (2000)
#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (256)

biquad* bq;
bitcrush* bitc;
oscillator* osc;

static int callback (
	const void* input,
	void* output,
	unsigned long framesPerBuffer,
	const PaStreamCallbackTimeInfo* time_info,
	PaStreamCallbackFlags flags,
	void* userData
) {
	float* in = (float*) input;
	float* out = (float*) output;
	unsigned int i;

	for(i = 0; i < framesPerBuffer; i++){
		*out++ = 
			bq_process(bq,
			bitc_process(bitc,
				*in++
			)
		);
		//*out++ = osc_process(osc);
	}

	return 0;
}

void print_error(PaError err) {
	printf("Error: %s\n", Pa_GetErrorText(err));
}

int main(int argc, char** argv) {
	bq = bq_new(LOWPASS, 1000.0, 5.0, 1.0, SAMPLE_RATE);
	osc = osc_new(0.4, 120.0, SAW, SAMPLE_RATE);
	bitc = bitc_new(1);

	// Initialize PortAudio
	PaError err;
	err = Pa_Initialize();
	if (err != paNoError){
		print_error(err);
	}

	// Open a stream
	PaStream* stream;
	err = Pa_OpenDefaultStream(
		&stream,
		1,
		1,
		paFloat32,
		SAMPLE_RATE,
		FRAMES_PER_BUFFER,
		callback,
		NULL
	);
	if (err != paNoError){
		print_error(err);
	}

	// Start the stream
	err = Pa_StartStream(stream);
	if (err != paNoError){
		print_error(err);
	}

	const PaStreamInfo* info = Pa_GetStreamInfo(stream);
	printf("\nStream Information:\n");
	printf("StructVersion: %d\n",info->structVersion);
	printf("inputLatency: %f\n",info->inputLatency);
	printf("outputLatency: %f\n",info->outputLatency);
	printf("Sample Rate: %f\n\n",info->sampleRate);

	// Sleep while stream operates
	Pa_Sleep(NUM_SECONDS*1000);

	// Close the stream
	err = Pa_CloseStream(stream);
	if (err != paNoError){
		print_error(err);
	}

	// Terminate Port Audio. We're done!
	err = Pa_Terminate();
	if (err != paNoError){
		print_error(err);
	}

	bq_destroy(bq);
	osc_destroy(osc);

	return 0;
}
