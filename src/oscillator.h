// Oscillator Module
typedef struct _oscillator {
	float *wave_table;
	float frequency;
	int sample_rate;
	int table_size;
	int phase;
} oscillator;

// Constructor
oscillator* osc_new(float gain, float frequency, int sample_rate);

// Provides the output of the oscillator
float osc_process(oscillator* osc);

//Destructor
void osc_destroy(oscillator* osc);
