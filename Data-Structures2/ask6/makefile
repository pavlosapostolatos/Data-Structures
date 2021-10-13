MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog6
OBJS = main6.o
include $(MODULES)/ask6modules/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)