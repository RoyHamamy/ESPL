all: files

files: EncoderDebugger.o
	gcc -m32 -g -Wall -o EncoderDebugger EncoderDebugger.o

EncoderDebugger.o: EncoderDebugger.c
	gcc -m32 -g -Wall -c -o EncoderDebugger.o  EncoderDebugger.c

clean:
	rm -f *.o files 
