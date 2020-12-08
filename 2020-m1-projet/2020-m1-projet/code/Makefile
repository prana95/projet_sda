PROG=main
CC=gcc
CFLAGS=-Wall -Wfatal-errors -g 

all: $(PROG)
main: main.o acm.o graphe-3.o citiesReader.o

acm.o: acm.c acm.h graphe-3.h
graphe-3.o: graphe-3.c graphe-3.h citiesReader.h

main.o: main.c graphe-3.h acm.h citiesReader.h 

.PHONY: clean distclean
clean:
	@rm *.o
distclean: clean
	@rm $(PROG)
