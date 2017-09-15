audiotest: include/*.c src/*.c main.c
	gcc -o vocoder.out -lportaudio include/*.c src/*.c main.c
