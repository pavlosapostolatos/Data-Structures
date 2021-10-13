ask6 : ask6main.o ask6func.o
	gcc ask6main.o ask6func.o -o ask6
ask6main.o :ask6main.c ask6declare.h ask6types.h
	gcc -c ask6main.c
ask6func.o :ask6func.c ask6declare.h ask6types.h
	gcc -c ask6func.c
clean:
	rm ask6 ask6main.o ask6func.o
