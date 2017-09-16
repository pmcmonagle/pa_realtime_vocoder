audiotest: include/*.c src/*.c main.c
	gcc -o vocoder.out include/*.c src/*.c main.c -lportaudio
