CFLAGS += -I$(MODULES)/ask7modules
ifeq ($(PQ_IMPL),bh)
	# linked implementation
	CFLAGS += -DPQ_IMPL_BH
	include $(MODULES)/ask5modules/make.inc
	OBJS += $(MODULES)/ask7modules/PQ1.o
else
	# sequential implementation (default)
	CFLAGS += -DPQ_IMPL_BST
	include $(MODULES)/ask6modules/make.inc
	OBJS += $(MODULES)/ask7modules/PQ2.o
endif
