// Oscillator Module
typedef struct _oscillator {
	float *wave_table;
	float frequency;
	int sample_rate;
	int table_size;
	int phase;
} oscillator;

typedef enum {
	SAW,
	SINE,
	SQUARE,
	TRIANGLE,
	WHITE_NOISE,
} wave_type;

// Constructor
oscillator* osc_new(float gain, float frequency, wave_type type, int sample_rate);

// Calculate the value for an index in the table given the wave_type,
// table_size and index.
float osc_table_value_for_i(wave_type type, int table_size, int i);

// Provides the output of the oscillator
float osc_process(oscillator* osc);

//Destructor
void osc_destroy(oscillator* osc);
