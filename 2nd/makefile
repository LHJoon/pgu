CC=gcc
CFLAGS=-Wall
OBJS=testlib.o project1.o test.o
TARGET=project1

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

test.o: testlib.h test.c
testlib.o: project1.h testlib.h testlib.c
project1.o: project1.h project1.c

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
