
#ifndef MERGER_MERGER_H
#define MERGER_MERGER_H

#include <string>
#include <vector>
#include <map>

#define COMMENT "#"
#define CIRCUIT_ENDING ".circ"
#define UC_ENDING ".uc"
#define PROG_ENDING ".prog"
#define PUBLIC_CIRCUIT_ENDING ".pub.c"
#define PRIVATE_CIRCUIT_ENDING ".priv.c"

#define WIRE_1 -3

using namespace std;

/**
 * Exception thrown by parsing error
 */
struct ParsingException : public std::exception {
    const char *what() const throw() {
        return "Parsing Exception!";
    }
};

/**
 * the information that the parser expect next
 */
enum parseType {
    CIRC_IN, // inputs for the whole circuit (from client or server)
    SEMI_IN, // inputs for the whole circuit (from client or server) or inputs of a sub-circuit
    IN, // inputs of a sub-circuit
    OUT, // outputs of a sub-circuit
    CIRC_OUT // outputs for the whole circuit
};

bool stringEndsWith(const string &str, const string &ending);

bool isNumber(string s);

string removeComments(string line);

bool getNextLine(fstream &file, string &line);

bool isValidParsingString(string str, parseType type);

vector<uint32_t> getRange(istringstream &iss, parseType type);

void handleInputs(string current, istringstream &iss, fstream &file, map<uint32_t, uint32_t> &wires, uint32_t &counter);

void parsePublicCircuit(string circuitPath,
                        istringstream &iss,
                        fstream &file,
                        map<uint32_t, uint32_t> &wires,
                        uint32_t &counter);

void parseUC(string circuitPath, istringstream &iss, fstream &file, map<uint32_t, uint32_t> &wires, uint32_t &counter);

void handleCircuits(string path,
                    string circuitName,
                    istringstream &iss,
                    fstream &file,
                    fstream &pfile,
                    map<uint32_t, uint32_t> &wires,
                    uint32_t &counter);

void read_merger(string mergeFileName);

#endif //MERGER_MERGER_H
