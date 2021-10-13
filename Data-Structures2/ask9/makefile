MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog9
OBJS = ask9main.o
CFLAGS += -I$(MODULES)/../ask9
include $(MODULES)/pairheap/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)