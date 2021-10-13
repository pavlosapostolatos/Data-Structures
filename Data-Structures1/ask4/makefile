ask4 : ask4main.o ask4func.o
	gcc ask4main.o ask4func.o -o ask4
ask4main.o :ask4main.c ask4declare.h ask4types.h
	gcc -c ask4main.c
ask4func.o :ask4func.c ask4declare.h ask4types.h
	gcc -c ask4func.c
clean:
	rm ask4 ask4main.o ask4func.o
