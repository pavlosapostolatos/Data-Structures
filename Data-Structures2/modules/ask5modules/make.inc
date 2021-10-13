include $(MODULES)/ask4modules/make.inc
CFLAGS += -I$(MODULES)/ask5modules
ifeq ($(BT_IMPL),pointers)
	# linked implementation
	CFLAGS += -DBT_IMPL_LINKED
	OBJS += $(MODULES)/ask5modules/module5_1.o
else
	# sequential implementation (default)
	CFLAGS += -DBT_IMPL_SEQUENTIAL
	OBJS += $(MODULES)/ask5modules/module5_1.o
endif
