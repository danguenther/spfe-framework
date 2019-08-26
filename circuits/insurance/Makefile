CBMC_GC = ../../extern/privdev18-ak2-cbmc-gc/bin/cbmc-gc
CIRCUIT_SIM = ../../extern/privdev18-ak2-cbmc-gc/bin/circuit-sim

.PHONY: clean run-sim run-aby

output.gate.txt: damage.pub.c
	$(CBMC_GC) $^ --unwind 35 --minimization-time-limit 10

run-sim:
	@$(CIRCUIT_SIM) --spec-file "damage.pub.spec"


clean:
	rm -f output.*.txt
