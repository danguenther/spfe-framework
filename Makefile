CBMC_GC = extern/privdev18-ak2-cbmc-gc
MAKE = make

.PHONY: clean

all: compile-cbmc-gc

compile-cbmc-gc: download-sat
	$(MAKE) -C $(CBMC_GC)

download-sat:
	$(MAKE) -C $(CBMC_GC) minisat2-download

clean:
	$(MAKE) -C $(CBMC_GC) clean

