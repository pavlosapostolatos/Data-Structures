ask1 : ask1main.o ask1func.o
	gcc ask1main.o ask1func.o -o ask1
ask1main.o :ask1main.c ask1declare.h ask1types.h
	gcc -c ask1main.c
ask1func.o :ask1func.c ask1declare.h ask1types.h
	gcc -c ask1func.c
clean:
	rm ask1 ask1main.o ask1func.o
