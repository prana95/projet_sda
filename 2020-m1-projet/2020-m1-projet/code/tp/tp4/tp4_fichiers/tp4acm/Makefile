PROG=test-acm
CC=gcc
CFLAGS=-Wall -Wfatal-errors -g

all: $(PROG)
test-acm: test-acm.o acm.o graphe-3.o

acm.o: acm.c acm.h graphe-3.h
graphe-3.o: graphe-3.c graphe-3.h
test-acm.o: test-acm.c graphe-3.h acm.h

.PHONY: clean distclean
clean:
	@rm *.o
distclean: clean
	@rm $(PROG)
