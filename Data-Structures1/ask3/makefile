ask3 : ask3main.o ask3func.o
	gcc ask3main.o ask3func.o -o ask3
ask3main.o :ask3main.c ask3declare.h ask3types.h
	gcc -c ask3main.c
ask3func.o :ask3func.c ask3declare.h ask3types.h
	gcc -c ask3func.c
clean:
	rm ask3 ask3main.o ask3func.o
