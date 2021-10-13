ask5 : ask5main.o ask5func.o
	gcc ask5main.o ask5func.o -o ask5
ask5main.o :ask5main.c ask5declare.h ask5types.h
	gcc -c ask5main.c
ask5func.o :ask5func.c ask5declare.h ask5types.h
	gcc -c ask5func.c
clean:
	rm ask5 ask5main.o ask5func.o
