MODULES = ../modules2
CFLAGS = -g -Wall -I.
PROGRAM = prog2
OBJS = main2.o
include $(MODULES)/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)