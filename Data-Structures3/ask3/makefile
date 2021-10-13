MODULES = ../modules3
CFLAGS = -g -Wall -I.
PROGRAM = prog3
OBJS = main3.o
include $(MODULES)/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)