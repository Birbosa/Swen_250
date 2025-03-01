EADERS = pfinal.h unit_tests.h

default: test

test:	main.o pfinal.o unit_tests.o
	gcc -g -o test main.o pfinal.o unit_tests.o
	
pfinal.o: pfinal.c $(HEADERS)
	gcc -Wall -g -c pfinal.c

main.o: main.c $(HEADERS)
	gcc -Wall -g -c main.c
	
unit_tests.o: unit_tests.c $(HEADERS)
	gcc -Wall -g -c unit_tests.c

clean:
	-rm -f pfinal.o
	-rm -f main.o
	-rm -f unit_tests.o
	-rm -f test
	
