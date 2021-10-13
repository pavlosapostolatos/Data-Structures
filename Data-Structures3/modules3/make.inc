CFLAGS += -I$(MODULES)
OBJS += $(MODULES)/similar.o
CFLAGS += -I$(MODULES)/../ask6modules
OBJS += $(MODULES)/../ask6modules/ask6func.o
include $(MODULES)/../modules2/make.inc
