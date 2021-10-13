ask2 : ask2main.o ask2func.o
	gcc ask2main.o ask2func.o -o ask2
ask2main.o :ask2main.c ask2declare.h ask2types.h
	gcc -c ask2main.c
ask2func.o :ask2func.c ask2declare.h ask2types.h
	gcc -c ask2func.c
clean:
	rm ask2 ask2main.o ask2func.o
