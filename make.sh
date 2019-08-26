# folder including all your public and private c programs
PROJECT=circuits/insurance

# Merge Filename
MERGE_FILE="insurance.merge" # should end with ".merge"

# settings
TEST=true # set to true if you want to test all circuits
RUN_CBMC_GC=true # set to true if you want to compile your c code into boolean circuits. Set this only to false if you already have the boolean circuits
RUN_UC=true # set to true if you want to compile the private circuits into Universal circuits. Set this only to false if you already have the UCs
RUN_MERGE=true # set to true if you want to merge alle the circuits. Set this only to false if you already have the merged files

TESTRESULTFILE="testresults.txt"
CBMC_MINIMIZATION_TIME=10 # number of seconds CBMC-GC shall minimize the circuit
BIN_DIR=build # directory where you CMAKE binaries are included
UC_VERSION=4 # version of the UC (4 for 4-way, 2 for 2-way, 0 for hybrid)

# settings for CBMCGC
CBMCGC_DIR=extern/privdev18-ak2-cbmc-gc
CBMCGC=${CBMCGC_DIR}/bin/cbmc-gc
CIRCUIT_SIM=${CBMCGC_DIR}/bin/circuit-sim
CIRCUIT_UTILS=${CBMCGC_DIR}/bin/circuit-utils

# serttings for executables
BRISTOL=${BIN_DIR}/bristol
UC=${BIN_DIR}/UC
MERGE=${BIN_DIR}/merge
ABY=${BIN_DIR}/InsuranceCalculator
MERGE_TEST=${BIN_DIR}/runMergerTests

# initialize test file
if $TEST;
then
	echo "===TESTFILE===" > ${TESTRESULTFILE};
fi

# translate c programs into bristol circuits
if $RUN_CBMC_GC;
then
if $TEST;
then
	echo $'\r'$'\r'"===CIRCUIT TESTS==="$'\r' >> ${TESTRESULTFILE};
fi
	for circuit in $PROJECT/*.c; 
		do 
		specifications="";
		if [ -e "${circuit%.c}.conf" ]
		then
			specifications=`cat ${circuit%.c}.conf`;
		fi
		$CBMCGC "$circuit" --minimization-time-limit ${CBMC_MINIMIZATION_TIME} ${specifications};
		if $TEST; 
		then
			if [ -e "${circuit%.c}.spec" ]
			then
				echo $'\r'$'\r'"===TESTS FOR ${circuit%.c}==="$'\r' >> ${TESTRESULTFILE};
				$CIRCUIT_SIM --spec-file "${circuit%.c}.spec" >> ${TESTRESULTFILE};
			fi
		fi
		$CIRCUIT_UTILS --as-bristol "${circuit%.c}.circ";
		rm -f output.*.txt;
	done;
fi;
#translate private circuits into Universal Circuits
if $RUN_UC;
then
	for circuit in $PROJECT/*.priv.circ;
		do
		$BRISTOL "$circuit";
		$UC "${circuit}_SHDL.circuit" -version "$UC_VERSION";
		mv "${circuit}_SHDL.circuit_Mod_SHDL.circuit_circ.txt" "${circuit%.circ}.uc";
		mv "${circuit}_SHDL.circuit_Mod_SHDL.circuit_prog.txt" "${circuit%.circ}.prog";
	done;
fi;

#merge public and universal circuits into one circuit
if $RUN_MERGE;
then
	${MERGE} "${PROJECT}/${MERGE_FILE}";
	if $TEST;
	then
		echo $'\r'$'\r'"===MERGE TESTS==="$'\r' >> ${TESTRESULTFILE};
		$MERGE_TEST >> ${TESTRESULTFILE}
	fi
fi;

#run ABY as Server and Client in new terminals
xterm -hold -e $ABY -r 0 -f "${PROJECT}/${MERGE_FILE%.merge}".circuit -e "${PROJECT}"/"${MERGE_FILE%.merge}".circuit.prog -z "${PROJECT}"/serverInputFile.txt & xterm -hold -e $ABY -r 1 -f "${PROJECT}/${MERGE_FILE%.merge}.circuit" -e "${PROJECT}"/"${MERGE_FILE%.merge}".circuit.prog;



