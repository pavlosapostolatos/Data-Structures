MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog7
OBJS = main7.o
include $(MODULES)/ask7modules/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)