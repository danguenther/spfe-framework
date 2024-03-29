#include "aby_pfe.h"

/**
 * Takes as inputs the arity of the logical operation (1 or 2), 2 inputs (possibly one dummy), the number defining the function
 * and all the wires previously defined, and returns the result
 * @param arity of the logical operation
 * @param input1 first input
 * @param input2 second input
 * @param function_number the number defining the function (from 0 to 15, the integer representation of the function table)
 * @param wires_carry the std::vector of booleans that carry the already defined wires' values
 * @return result of logical operation
 */
bool calculate(uint8_t arity,
               uint32_t input1,
               uint32_t input2,
               uint32_t function_number,
               std::vector<bool> wires_carry) {
    bool in1;
    bool in2;
    if (arity == 1) {
        in1 = wires_carry[input1];
        switch (function_number) {
            case 0:return false;
            case 1:return !in1;
            case 2:return in1;
            case 3:return true;
            default:std::cerr << "PROBLEM in read_SHDL::calculate: Not correct function number" << std::endl;
                return false;
        }
    } else if (arity == 2) {
        in1 = wires_carry[input1];
        in2 = wires_carry[input2];
        switch (function_number) {
            case 0:return false;
            case 1:return !(in1 | in2);
            case 2:return in1 ^ (in1 | in2);
            case 3:return !(in1);
            case 4:return in2 ^ (in1 | in2);
            case 5:return !(in2);
            case 6:return in1 ^ in2;
            case 7:return !(in1 & in2);
            case 8:return in1 & in2;
            case 9:return !(in1 ^ in2);
            case 10:return in2;
            case 11:return !(in2 ^ (in1 | in2));
            case 12:return in1;
            case 13:return !(in1 ^ (in1 | in2));
            case 14:return in1 | in2;
            case 15:return true;
            default:std::cerr << "PROBLEM in read_SHDL::calculate: Not correct function number" << std::endl;
                return false;
        }
    }
    std::cerr << "PROBLEM in read_SHDL::calculate: Arity is greater than 2 or less than 1: cannot be calculated"
              << std::endl;
    return false;
}

/**
 * Plain evaluation of universal circuit to check correctness
 * @param filename name of file with UC
 * @param input_list_client specified input bits of client
 * @param input_list_server specified input bits of server
 * @param output_list resulting output bits
 */
void eval_UC(std::string circuit,
             std::string program,
             std::vector<bool> &input_list_client,
             std::vector<bool> &input_list_server,
             std::vector<bool> &output_list) {
    std::ifstream file;
    file.open(circuit);
    std::ifstream file_xy;
    file_xy.open(program);

    std::vector<bool> wires_carry;

    std::string line;
    std::string line_xy;
    std::vector<uint32_t> tokens;
    std::vector<uint32_t> tokens_xy;
    uint32_t counter = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line != "") {
                tokenize(line, tokens);
                /* Count the number of inputs and initialize a random bool list of inputs */
                if (line.at(0) == 'C') {
                    for (uint32_t j = 0; j < tokens.size() - 1; ++j) {
                        wires_carry.push_back(input_list_client[j]);
                        counter++;
                    }
                }
                if (line.at(0) == 'S') {
                    for (uint32_t j = 0; j < tokens.size() - 1; ++j) {
                        wires_carry.push_back(input_list_client[j]);
                        counter++;
                    }
                }
                if (line.at(0) == 'P') {
                    getline(file_xy, line_xy);
                    if (line_xy.at(0) == '0') {
                        wires_carry.push_back(wires_carry[tokens[1]]);
                        wires_carry.push_back(wires_carry[tokens[2]]);
                    } else if (line_xy.at(0) == '1') {
                        wires_carry.push_back(wires_carry[tokens[2]]);
                        wires_carry.push_back(wires_carry[tokens[1]]);
                    }
#ifdef CIRCUIT_DEBUG
                    std::cout << "X" << wires_carry[tokens[1]] << " " << wires_carry[tokens[2]] << std::endl;
#endif // CIRCUIT_DEBUG
                }
                if (line.at(0) == 'A') {
                    auto temp = 0;
                    if (wires_carry[tokens[1]] == 1 && wires_carry[tokens[2]] == 1) {
                        temp = 1;
                    }
                    wires_carry.push_back(temp);
                }
                if (line.at(0) == 'R') {
                    auto temp = 1;
                    if (wires_carry[tokens[1]] == 0 && wires_carry[tokens[2]] == 0) {
                        temp = 0;
                    }
                    wires_carry.push_back(temp);
                }
                if (line.at(0) == 'X') {
                    auto temp = 1;

                    int threshold = 1000000000;
                    uint32_t x1, x2;
                    auto tk1 = tokens[1];
                    if (tk1 > threshold) {
                        x1 = 1;
                    } else {
                        x1 = wires_carry[tk1];
                    }
                    auto tk2 = tokens[2];
                    if (tk2 > threshold) {
                        x2 = 1;
                    } else {
                        x2 = wires_carry[tk2];
                    }

                    if (x1 == x2) {
                        temp = 0;
                    }
                    wires_carry.push_back(temp);
                }
                if (line.at(0) == 'Y') {
                    getline(file_xy, line_xy);
                    if (line_xy.at(0) == '0') {
                        wires_carry.push_back(wires_carry[tokens[2]]);
                    } else if (line_xy.at(0) == '1') {
                        wires_carry.push_back(wires_carry[tokens[1]]);
                    }
#ifdef CIRCUIT_DEBUG
                    std::cout << "Y" << wires_carry[tokens[1]] << " " << wires_carry[tokens[2]] << std::endl;
#endif // CIRCUIT_DEBUG
                }
                if (line.at(0) == 'U') {
                    getline(file_xy, line_xy);
                    tokenize(line_xy, tokens_xy);
                    auto temp = calculate(2, tokens[1], tokens[2], tokens_xy[0], wires_carry);
                    wires_carry.push_back(temp);
#ifdef CIRCUIT_DEBUG
                    std::cout << "U" << wires_carry[tokens[1]] << " " << wires_carry[tokens[2]] << "\t" << temp << std::endl;
#endif // CIRCUIT_DEBUG
                    // std::cout << "gate " << counter << ": " << temp << std::endl;
                    counter++;
                }
                if (line.at(0) == 'O') {
                    for (uint32_t j = 1; j < tokens.size(); ++j) {
                        output_list.push_back(wires_carry[tokens[j]]);
                    }
                }
            }
        }
    }

    file.close();
    file_xy.close();
}

/**
 * run a PFE application on a given circuit file using ABY with the given parameters
 * @param role role client or server
 * @param address IP address
 * @param port port
 * @param seclvl symmetric security parameter
 * @param nvals number of iterations
 * @param bitlen bitlength
 * @param nthreads number of threads
 * @param mt_alg MT algorithm
 * @param sharing sharing Yao or GMW
 * @param filename filename of the circuit
 * @param p1filename filename of the programming bits
 * @param clientInputs client input vector
 * @param serverInputs server input vector
 * @return the result of the PFE computation
 */
std::vector<uint32_t> test_universal_circuit(e_role role,
                                             char *address,
                                             uint16_t port,
                                             seclvl seclvl,
                                             uint32_t nvals,
                                             uint32_t bitlen,
                                             uint32_t nthreads,
                                             e_mt_gen_alg mt_alg,
                                             e_sharing sharing,
                                             const std::string filename,
                                             const std::string p1filename,
                                             std::vector<uint32_t> clientInputs,
                                             std::vector<uint32_t> serverInputs) {
    std::cout << "Evaluating Universal circuit in " << get_sharing_name(sharing) << " Sharing" << std::endl;
    /* NO CHANGE ----------------------------------------------------*/
    /**
     Step 1: Create the ABYParty object which defines the basis of all the
     operations which are happening.	Operations performed are on the
     basis of the role played by this object.
     */
    ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads,
                                   mt_alg);

    /* NO CHANGE ----------------------------------------------------*/
    /**
     Step 2: Get to know all the sharing types available in the program.
     */
    std::vector<Sharing *> &sharings = party->GetSharings();

    /* NO CHANGE ----------------------------------------------------*/
    /**
     Step 3: Create the circuit object on the basis of the sharing type
     being inputed.
     */
    BooleanCircuit *circ =
        (BooleanCircuit *) sharings[sharing]->GetCircuitBuildRoutine();

    assert(circ->GetCircuitType() == C_BOOLEAN);

    srand(time(NULL));

    /* NO CHANGE ----------------------------------------------------*/
    /**
     Step 4: Creating the share objects - s_x_vec, s_y_vec which
     are used as inputs to the computation. Also, s_out which stores the output.
     */

    /* xvals should be size of the file p1filename */
    /**
     Step 5: Allocate the xvals and yvals that will hold the plaintext values.
     */
    uint32_t client_input_bits, server_programming_bits, server_input_bits;
    circ->GetInputLengthFromFile(filename, client_input_bits, server_programming_bits, server_input_bits);
    //server_input_bits = circ->GetServerInputLengthFromFile(p1filename);
    //uint32_t client_input_bits = circ->GetClientInputLengthFromFile(filename);
    //std::cout << "Server input bits = " << server_input_bits << ", client input bits = " << client_input_bits << std::endl;

    /**
     Step 6: Fill the arrays xvals and yvals with the generated random values.
     Both parties use the same seed, to be able to verify the
     result. In a real example each party would only supply
     one input value. Copy the randomly generated std::vector values into the respective
     share objects using the circuit object method PutINGate().
     Also mention who is sharing the object.
     The values for the party different from role is ignored,
     but PutINGate() must always be called for both roles.
     */

    std::vector<uint32_t> p1inputs, p2inputs, results, outputs;
    std::vector<bool> verif_p2inputs, verif_results;
    struct timespec cstart, cend;
    clock_gettime(CLOCK_MONOTONIC, &cstart);

    uint32_t temp = 0;

    for (uint32_t j = 0; j < client_input_bits; ++j) {
        if (role == SERVER) {
            temp = rand() % 2;
        } else {
            temp = clientInputs[j];
        }
        verif_p2inputs.push_back(temp);
        p2inputs.push_back(circ->PutSIMDINGate(nvals, temp, CLIENT));
    }
    std::cout << std::endl << "Inputs ";
    for (uint32_t j = 0; j < client_input_bits; ++j) {
        std::cout << verif_p2inputs[j] << " ";
    }
    for (uint32_t j = client_input_bits; j < client_input_bits + server_input_bits; ++j) {
        if (role == CLIENT) {
            temp = rand() % 2;
        } else {
            temp = serverInputs[j - client_input_bits];
        }
        verif_p2inputs.push_back(temp);
        p1inputs.push_back(circ->PutSIMDINGate(nvals, temp, SERVER));

    }

    std::cout << std::endl;
    //std::cout << "PutInGate for CLIENT done" << std::endl;

    /**
	 Step 7: Call the build method for building the circuit for the
	 problem by passing the shared objects and circuit object.
	 Don"t forget to type cast the circuit object to type of share
	 */
    results =
        circ->PutUniversalCircuitFromFile(filename, p1filename, p1inputs, p2inputs, nvals, server_programming_bits);

    /**
      Step 8: Output the value of s_out (the computation result) to both parties
    */
    for (uint32_t i = 0; i < results.size(); i++) {
        outputs.push_back(circ->PutOUTGate(results[i], ALL));
    }

    clock_gettime(CLOCK_MONOTONIC, &cend);
    std::cout << "BuildTime = \t" << getMillies(cstart, cend) << " ms" << std::endl;

    /**
     Step 9: Executing the circuit using the ABYParty object evaluate the
     problem.
     */
    party->ExecCircuit();

    uint32_t val = 0;
    std::vector<uint32_t> result;
    std::cout << std::endl << "OUTPUTS:" << std::endl;
    for (uint32_t i = 0; i < outputs.size(); i++) {
        val = circ->GetOutputGateValue(outputs[i])[0];
        std::cout << val << " ";
        result.push_back(val);
    }
    std::cout << std::endl;

    /**
     Step 10: Type caste the plaintext output to 16 bit unsigned integer.
     */

    std::ofstream file;
    std::cout << "Total time / comm: " << party->GetTiming(P_TOTAL) << " ms / " <<
              party->GetSentData(P_TOTAL) + party->GetReceivedData(P_TOTAL) << " bytes " << std::endl;

    /*eval_UC(filename, p1filename, verif_p2inputs, verif_results);
    for(uint32_t i = 0; i < verif_results.size(); ++i){
        std::cout << verif_results[i] << " ";
    }*/
    std::cout << std::endl;

    file.close();
    delete party;

    return result;
}