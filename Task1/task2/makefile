all: files

files: EncoderDebugger2.o
	gcc -m32 -g -Wall -o EncoderDebugger2 EncoderDebugger2.o

EncoderDebugger2.o: EncoderDebugger2.c
	gcc -m32 -g -Wall -c -o EncoderDebugger2.o  EncoderDebugger2.c

clean:
	rm -f *.o files 
