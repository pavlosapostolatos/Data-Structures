ask7 : ask7main.o ask7func.o
	gcc ask7main.o ask7func.o -o ask7
ask7main.o :ask7main.c ask7declare.h ask7types.h
	gcc -c ask7main.c
ask7func.o :ask7func.c ask7declare.h ask7types.h
	gcc -c ask7func.c
clean:
	rm ask7 ask7main.o ask7func.o
