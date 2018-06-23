audiotest: include/*.c src/*.c main.c
	gcc -o main.out include/*.c src/*.c main.c -lportaudio
