all: bv qs.o

bv: bv.c
	gcc -o bv bv.c

qs: qs.c
	gcc -o qs.o qs.c

.PHONY: clean
clean:
	rm bv *.o

