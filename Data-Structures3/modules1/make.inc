CFLAGS += -I$(MODULES)/
CFLAGS += -I$(MODULES)/../ask1
OBJS += $(MODULES)/common.o
ifeq ($(HT_IMPL),separate_chain)
	# separate_chaining implementation
	CFLAGS += -DHT_IMPL_CHAIN
	OBJS += $(MODULES)//hash1.o
else
	# open addressing implementation (default)
	CFLAGS += -DHT_IMPL_OPEN
	OBJS += $(MODULES)//hash2.o
endif