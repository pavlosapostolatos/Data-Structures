include $(MODULES)/modules1/make.inc
CFLAGS += -I$(MODULES)/ask4modules
ifeq ($(BT_IMPL),pointers)
	# linked implementation
	CFLAGS += -DBT_IMPL_LINKED
	OBJS += $(MODULES)/ask4modules/module4_1.o
else
	# sequential implementation (default)
	CFLAGS += -DBT_IMPL_SEQUENTIAL
	OBJS += $(MODULES)/ask4modules/module4_1.o
endif