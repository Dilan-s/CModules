CC = gcc
CFLAGS = -Wall -g
BUILD = testFile

all: $(BUILD)

clean:
	/bin/rm -f *.o *~ core $(BUILD)

testFile: tree.o testFile.o

testFile.o: tree.h

tree.o: tree.h
