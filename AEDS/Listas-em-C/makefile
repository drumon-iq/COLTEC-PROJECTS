.PHONY: Lista-Em-C clean

Lista-Em-C: main.o listas.o
	gcc main.o listas.o -o ExerLista.bin -Wall -pedantic

main.o: main.c
	@gcc -c main.c -Wall -pedantic

listas.o: listas.c listas.h
	@gcc -c listas.c -Wall -pedantic

clean:
	rm listas.o main.o

runner:
	sh run.sh ExerLista.bin
