TARGET_NAME = program.out
CC = gcc
LIBS = -lhelper -L$(PATH)
SHARED = shared_helper.o
ODIR ?= build


SRCS := $(subst ./,,$(shell find . -name "*.c"))

OBJS := $(filter-out $(SHARED), $(patsubst %.c,%.o,$(SRCS)))


%.o: %.c
	$(CC) $< -lhelper -L`pwd` -o $@
	
%.so: shared_helper.c shared_helper.h
	$(CC) -shared -fPIC shared_helper.c -o libhelper.so

all: %.so $(OBJS)

.PHONY: clean
clean:
	rm -rf *.o *.so