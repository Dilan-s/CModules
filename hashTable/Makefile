CC = gcc
CFLAGS = -Wall --pedantic -g
LIB = liblinkedList.a
LIBOBJS = linkedList.o
BUILD = $(LIB)

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o core *~

$(LIB): $(LIBOBJS)
	ar rcs $(LIB) $(LIBOBJS)

linkedList.o: linkedList.h
