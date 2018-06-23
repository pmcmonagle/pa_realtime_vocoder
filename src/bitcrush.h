// Bitcrush Module
typedef struct _bitcrush {
	int precision;
} bitcrush;

// Constructor
bitcrush* bitc_new(int precision);

// Process each sample
float bitc_process(bitcrush* bitc, float input);
