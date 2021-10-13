MODULES = ../modules
CFLAGS = -g -Wall -I.
PROGRAM = prog1
OBJS = main1.o
include $(MODULES)/modules1/make.inc
$(PROGRAM): clean $(OBJS)
	gcc $(OBJS) -o $(PROGRAM) -lm
clean:
	rm -f $(PROGRAM) $(OBJS)

run: $(PROGRAM)
	./$(PROGRAM)