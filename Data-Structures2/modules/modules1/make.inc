CFLAGS += -I$(MODULES)/modules1
CFLAGS += -I$(MODULES)/../ask1
ifeq ($(BT_IMPL),pointers)
	# linked implementation
	CFLAGS += -DBT_IMPL_LINKED
	OBJS += $(MODULES)/modules1/module1.o
else
	# sequential implementation (default)
	CFLAGS += -DBT_IMPL_SEQUENTIAL
	OBJS += $(MODULES)/modules1/module2.o
endif