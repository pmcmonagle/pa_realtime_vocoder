# PortAudio Realtime Vocoder
My goal is to write a reatime vocoder in C using PortAudio.
In it's current state, it is nowhere near complete.

## Setup
- Make sure you have gcc and make available
- Install portaudio (eg. apt-get install portaudio)
- Clone this repository
- Copy libportaudio.a to the repo folder
- Run make

## Tasks Complete
- WaveTable Synthesizer
- BiQuad Filter (borrowed from somewhere else)

## TODO
- Pass the modulator (microphone) through a series of narrow bandpass filters
- Analyze the volume of each band
- Apply the volume to the carrier (wavetable synth)
- Maybe include envelopes somewhere in the process
