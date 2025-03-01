HEADERS = bits.h unit_tests.h

default: test

test:	bits.o unit_tests.o main.o
	gcc -g -o test bits.o unit_tests.o main.o
	
main.o: main.c $(HEADERS)
	gcc -g -Wall -c main.c

bits.o: bits.c $(HEADERS)
	gcc -g -Wall -c bits.c

unit_tests.o: unit_tests.c $(HEADERS)
	gcc -g -Wall -c unit_tests.c

clean:
	rm -f *.o
	rm -f test
	
