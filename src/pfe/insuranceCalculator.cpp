#include "ABY_application/aby_pfe.h"

/*
 * only define if you want to test the circuit on the Client side
 * Note: if you define it, you have to specify the server programming and input files
 * during the Client call
 */
//#define EVAL_CIRCUIT

/**
 * read the test options and writes them into the given parameters
 * @param argcp number of options
 * @param argvp array of all options
 * @param role role client or server
 * @param bitlen bit length
 * @param secparam symmetric security bits
 * @param address ip address
 * @param port port
 * @param sharing sharing GMW or Yao
 * @param filename UC filename
 * @param p1filename programming filename
 * @param nruns number of repeated iterations
 * @param p1InputFilename server input filename
 * @return
 */
int32_t read_test_options(int32_t *argcp,
                          char ***argvp,
                          e_role *role,
                          uint32_t *bitlen,
                          uint32_t *secparam,
                          std::string *address,
                          uint16_t *port,
                          e_sharing *sharing,
                          std::string *filename,
                          std::string *p1filename,
                          uint32_t *nruns,
                          std::string *p1InputFilename) {

    uint32_t int_role = 0, int_port = 0;

    parsing_ctx options[] =
        {{(void *) &int_role, T_NUM, "r", "Role: 0/1", true, false},
         {(void *) bitlen, T_NUM, "b", "Bit-length, default 32", false, false},
         {(void *) secparam, T_NUM, "s", "Symmetric Security Bits, default: 128", false, false},
         {(void *) address, T_STR, "a", "IP-address, default: localhost", false, false},
         {(void *) sharing, T_NUM, "c", "Sharing [0: GMW, 1: Yao), default: Yao", false, false},
         {(void *) &int_port, T_NUM, "p", "Port, default: 7766", false, false},
         {(void *) filename, T_STR, "f", "UC file", false, false},
         {(void *) p1filename, T_STR, "e", "Programming file", false, false},
         {(void *) nruns, T_NUM, "i", "Number of repeated Iterations, default: 1", false, false},
         {(void *) p1InputFilename, T_STR, "z", "Server Input File", false, false}
        };

    if (!parse_options(argcp, argvp, options,
                       sizeof(options) / sizeof(parsing_ctx))) {
        print_usage(*argvp[0], options, sizeof(options) / sizeof(parsing_ctx));
        std::cout << "Exiting" << std::endl;
        exit(0);
    }

    assert(int_role < 2);
    *role = (e_role) int_role;

    if (int_port != 0) {
        assert(int_port < 1 << (sizeof(uint16_t) * 8));
        *port = (uint16_t) int_port;
    }

    assert(*sharing < 2 && *sharing >= 0);
    std::cout << std::endl;

    return 1;
}

/**
 * runs the Insurance Calculator
 * @param argc number of arguments
 * @param argv arguments array
 * @return exit code
 */
int main(int argc, char **argv) {

    e_role role;
    uint32_t bitlen = 32, nvals = 1, secparam = 128, nthreads = 1, nruns = 1;
    uint16_t port = 7766;
    uint32_t p2input = 0;
    std::string address = "127.0.0.1";
    e_mt_gen_alg mt_alg = MT_OT;
    e_sharing sharing = S_BOOL;
    std::string filename;
    std::string p1programmingfilename;
    std::string p1inputFilename;

    read_test_options(&argc,
                      &argv,
                      &role,
                      &bitlen,
                      &secparam,
                      &address,
                      &port,
                      &sharing,
                      &filename,
                      &p1programmingfilename,
                      &nruns,
                      &p1inputFilename);

    seclvl seclvl = get_sec_lvl(secparam);

    std::vector<uint32_t> p1inputs, p2inputs;


    if (role == CLIENT) {
	    for (int i = 0; i < 296; i++) {
			p2inputs.push_back(0);
	    }
    }

    if (role == SERVER
#ifdef EVAL_CIRCUIT
        || role == CLIENT
#endif
        ) {
        std::fstream serverFile(p1inputFilename, std::ios::in);
        if (!serverFile.good()) {
            std::cerr << "Specify your input file as server!" << std::endl;
            return 1;
        }

        std::string line;

        while (getline(serverFile, line)) {
            p1inputs.push_back(stoi(line));
        }
    }

    std::vector<uint32_t> results = test_universal_circuit(role,
                                                           (char *) address.c_str(),
                                                           port,
                                                           seclvl,
                                                           nvals,
                                                           bitlen,
                                                           nthreads,
                                                           mt_alg,
                                                           sharing,
                                                           filename,
                                                           p1programmingfilename,
                                                           p2inputs,
                                                           p1inputs);



#ifdef EVAL_CIRCUIT
    if (role == CLIENT) {
        std::vector<bool> verif_results, verif_p2inputs, verif_p1inputs;
        for (auto x : p2inputs) {
            verif_p2inputs.push_back(x == 1);
        }
        for (auto x: p1inputs) {
            verif_p1inputs.push_back(x == 1);
        }
        eval_UC(filename, p1programmingfilename, verif_p2inputs, verif_p1inputs, verif_results);
        for(uint32_t i = 0; i < verif_results.size(); ++i){
            std::cout << verif_results[i] << " ";
        }
    }
#endif

    return 0;
}
