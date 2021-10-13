MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog5
OBJS = main5.o
include $(MODULES)/ask5modules/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)