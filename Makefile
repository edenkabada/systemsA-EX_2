main.o: main.c
	gcc -Wall -c main.c my_mat.h

my_mat.o: my_mat.c
	gcc -Wall  -c my_mat.c my_mat.h

connections: main.o my_mat.o
	gcc -Wall -o connections main.o my_mat.o

all: connections

clean:
	rm -f *.o *.gch *.exe *.out connections

.PHONY: clean all	