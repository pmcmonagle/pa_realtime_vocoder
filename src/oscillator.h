// Oscillator Module
#define TABLE_SIZE (1024)
typedef struct _oscillator {
	float wave_table[TABLE_SIZE];
	float frequency;
	int phase;
	int frames_per_buffer;
} oscillator;

// Constructor
oscillator* osc_new(float frequency, int sample_rate, int frames_per_buffer);

// Provides the output of the oscillator
float osc_process(oscillator* osc);

//Destructor
void osc_destroy(oscillator* osc);
