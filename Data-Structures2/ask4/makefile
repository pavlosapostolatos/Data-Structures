MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog4
OBJS = main4.o
include $(MODULES)/ask4modules/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)