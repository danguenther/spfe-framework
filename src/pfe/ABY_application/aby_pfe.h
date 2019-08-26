
#ifndef INSURANCECALCULATOR_ABY_PFE_H
#define INSURANCECALCULATOR_ABY_PFE_H

//Utility libs
#include <ENCRYPTO_utils/crypto/crypto.h>
#include <ENCRYPTO_utils/parse_options.h>
//ABY Party class
#include "abycore/aby/abyparty.h"
#include "abycore/circuit/booleancircuits.h"
#include "abycore/sharing/sharing.h"

#include <assert.h>
#include <iostream>

bool calculate(uint8_t arity,
               uint32_t input1,
               uint32_t input2,
               uint32_t function_number,
               std::vector<bool> wires_carry);

void eval_UC(std::string circuit,
             std::string program,
             std::vector<bool> &input_list_client,
             std::vector<bool> &input_list_server,
             std::vector<bool> &output_list);

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
                                             std::vector<uint32_t> p2inputs,
                                             std::vector<uint32_t> p1inputs);

#endif //INSURANCECALCULATOR_ABY_PFE_H
