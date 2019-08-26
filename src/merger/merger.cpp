#include "merger.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <map>
#include <cmath>

using namespace std;

/**
 * checks, if a given string ends with the given suffix
 * @param str the given string to check
 * @param ending the suffix to check
 * @return true if str ends with ending
 */
bool stringEndsWith(const string &str, const string &ending) {
    return str.size() >= ending.size() && 0 == str.compare(str.size() - ending.size(), ending.size(), ending);
}

/**
 * checks, if a given string represents a number
 * @param s the given string
 * @return true if s represents a number
 */
bool isNumber(string s) {
    return s.find_first_not_of("0123456789") == string::npos && !s.empty();
}

/**
 * removes all comments of a given string. Comments start with "#"
 * @param line the given string
 * @return the same string without comments
 */
string removeComments(string line) {
    string s = line;
    string::size_type n = s.find(COMMENT);
    if (n != string::npos) {
        s.erase(n);
    }
    return s;
}

/**
 * get the next line of a file that contains information for the parser. Empty lines or commented lines are filtered.
 * @param file the input filestream
 * @param line the address where the next line shall be saved
 * @return true if a next line was found
 */
bool getNextLine(fstream &file, string &line) {
    while (getline(file >> ws, line)) {
        line = removeComments(line);
        if (line.empty()) continue;
        return true;
    }
    return false;
}

/**
 * checks if a given string can be interpreted by the parser with the given parseType
 * @param str the given string
 * @param type the information that the parser expect next in the given string
 * @return true if the given string can be interpreted
 */
bool isValidParsingString(string str, parseType type) {
    if (str == "out") {
        return type == IN;
    } else if (str == "outputs") {
        return type == IN;
    } else if (str == "C" || str == "S") {
        return type == CIRC_IN || type == SEMI_IN;
    } else if (str == "[" || str == "]" || isNumber(str)) {
        return true;
    } else if (stringEndsWith(str, ".c")) {
        return type == IN || type == SEMI_IN;
    }
    return false;
}

/**
 * Extracts the whole range of wire id's of a given string with the given parseType.
 * Id's are specified as a range from x to y with [ x y ] or listes as its own or a combination of both.
 * Example: [ 1 3 ] 6 8 [ 10 16 ] represents the range {1, 2, 3, 6, 8, 10, 11, 12, 13, 14, 15, 16}
 * @param iss the given string
 * @param type the information that the parser expects
 * @throws ParsingException is thrown if the syntax of the range is incorrect
 * @return all id's of the range
 */
vector<uint32_t> getRange(istringstream &iss, parseType type) {
    bool rangeStart = false;
    bool rangeBeginSet = false;
    bool rangeEndSet = false;
    vector<uint32_t> result;

    uint32_t rangeBegin, rangeEnd;
    uint32_t i;
    string current;
    iss >> current;
    while (isValidParsingString(current, type)) {
        if (current == "[") {
            if (!rangeStart) {
                rangeStart = true;
            } else {
                cerr << "Error: find two open [ without closing ]" << endl;
                throw ParsingException();
            }
        } else if (current == "]") {
            if (rangeStart && rangeBeginSet && rangeEndSet) {
                rangeStart = false;
                rangeBeginSet = false;
                rangeEndSet = false;
                for (i = rangeBegin; i <= rangeEnd; i++) {
                    result.push_back(i);
                }
            } else {
                cerr << "Error: find closing range ] but no opening range or the ranges aren't set correctly" << endl;
                throw ParsingException();
            }
        } else if (current == "out") {
            if (type != IN) {
                cerr << "Error: unexpected 'out'" << endl;
                throw ParsingException();
            }
            break;
        } else if (isNumber(current)) {
            long lvalue = stoul(current, nullptr, 10);
            auto value = static_cast<uint32_t>(lvalue);
            if (rangeStart) {
                if (rangeBeginSet) {
                    if (rangeEndSet) {
                        cerr << "Error: can only parse two values in range [ ]" << endl;
                        throw ParsingException();
                    } else {
                        rangeEnd = value;
                        rangeEndSet = true;
                    }
                } else {
                    rangeBegin = value;
                    rangeBeginSet = true;
                }
            } else {
                result.push_back(value);
            }
        } else {
            cerr << "Error: could not read " << current << endl;
            throw ParsingException();
        }
        if (iss.peek() == EOF) break;
        iss >> current;
    }

    if (!isValidParsingString(current, type) && current != "" && current != "out") {
        cerr << "Error: could not read " << current << endl;
        throw ParsingException();
    }

    return result;
}

/**
 * reads the inputs of the whole circuit in a given string and writes them into the ABY format file.
 * @param current the character that has to be put at the beginning of the input line: can be S for Server or C for Client
 * @param iss the given string
 * @param the ABY format file
 * @param wires mapping from the wires in the mering file to the wires in the ABY format file (updated in this function)
 * @param counter number of wires (updated in this function)
 */
void handleInputs(string current,
                  istringstream &iss,
                  fstream &file,
                  map<uint32_t, uint32_t> &wires,
                  uint32_t &counter) {
    ostringstream oss;
    oss << current;
    vector<uint32_t> range = getRange(iss, CIRC_IN);
    for (auto i : range) {
        oss << " " << i;
        wires[counter] = i;
        counter++;
    }
    file << oss.str();
}

/**
 * the given line represents the input/output wire description of a public circuit. The public circuit description file
 * is opened and read in and translated into the ABY format file. The number of wires is updated as well as the list of
 * mappings between merging file wire ID's and ABY format file wire ID's
 * @param circuitPath the path to the public circuit
 * @param iss the given line of the merger file
 * @param file the ABY output file
 * @param wires the map between wire ID's in the merger file and the ABY file (updated in this function)
 * @param counter number of wires (updated in this function)
 * @throws ParsingException if number of inputs/outputs of the merger file differs from real number of inputs/outputs
 *                          of sub circuit
 */
void parsePublicCircuit(string circuitPath, istringstream &iss, fstream &file, map<uint32_t, uint32_t> &wires,
                        uint32_t &counter) {
    fstream circuitFile(circuitPath, ios::in);
    vector<uint32_t> inputs = getRange(iss, IN);
    vector<uint32_t> outputs = getRange(iss, OUT);
    map<uint32_t, uint32_t> circuitWires;
    uint32_t oldCounter = counter;

    uint32_t inputA, inputB, numberOfOutputs, numberOfGates, numberOfWires;
    circuitFile >> numberOfGates >> numberOfWires >> inputA >> inputB >> numberOfOutputs;
    uint32_t numberOfInputs = inputA + inputB;

    if (numberOfOutputs != outputs.size()) {
        cerr << "sub circuit " << circuitPath << " has " << numberOfOutputs << " outputs " <<
             " but " << outputs.size() << " outputs are expected!" << endl;
        throw ParsingException();
    }

    if (numberOfInputs != inputs.size()) {
        cerr << "sub circuit " << circuitPath << " has " << numberOfInputs << " inputs " <<
             " but " << inputs.size() << " inputs are expected!" << endl;
        throw ParsingException();
    }

    // handle inputs
    for (uint32_t i = 0; i < numberOfInputs; i++) {
        uint32_t k = wires[inputs[i]];
        circuitWires[i] = k;
    }

    uint32_t upperBoundOutput = numberOfWires - 1;
    uint32_t lowerBoundOutput = upperBoundOutput - numberOfOutputs + 1;

    string line;
    uint32_t gateInputs, gateOutputs, input1, input2, output;
    string gate;
    while (getNextLine(circuitFile, line)) {
        istringstream circLine(line);
        circLine >> gateInputs >> gateOutputs >> input1;
        if (gateInputs == 2) {
            circLine >> input2;
        }
        circLine >> output >> gate;

        uint32_t realInput1 = circuitWires[input1];
        int32_t realInput2 = gateInputs == 2 ? circuitWires[input2] : WIRE_1;
        uint32_t realOutput = counter;
        circuitWires[output] = realOutput;

        if (lowerBoundOutput <= output && output <= upperBoundOutput) {
            wires[outputs[output - lowerBoundOutput]] = realOutput;
        }

        string gateChar;
        if (gate == "AND") {
            gateChar = "A";
        } else if (gate == "OR") {
            gateChar = "R";
        } else {
            gateChar = "X";
        }

        ostringstream oss;
        oss << endl << gateChar << " " << realInput1 << " " << realInput2 << " " << realOutput;
        file << oss.str();
        counter++;
    }

    counter = oldCounter + numberOfGates;
    circuitFile.close();
}

/**
 * the given line represents the input/output wire description of a private circuit (Universal Circuit). The UC file
 * is opened and read in and translated into the ABY format file. The number of wires is updated as well as the list of
 * mappings between merging file wire ID's and ABY format file wire ID's
 * @param circuitPath the path to the UC
 * @param iss the given line of the merger file
 * @param file the ABY output file
 * @param wires the map between wire ID's in the merger file and the ABY file (updated in this function)
 * @param counter number of wires (updated in this function)
 * @throws ParsingException is thrown if the UC file format is incorrect
 */
void parseUC(string circuitPath, istringstream &iss, fstream &file, map<uint32_t, uint32_t> &wires, uint32_t &counter) {
    fstream circuitFile(circuitPath, ios::in);
    vector<uint32_t> inputs = getRange(iss, IN);
    vector<uint32_t> outputs = getRange(iss, OUT);
    map<uint32_t, uint32_t> circuitWires;

    string line;

    // handle inputs
    getNextLine(circuitFile, line);
    istringstream circuitInputs(line);
    circuitInputs >> line;
    uint32_t i = 0;
    while (circuitInputs.peek() != EOF) {
        circuitInputs >> line;
        if (!isNumber(line)) {
            throw ParsingException();
        }
        i = static_cast<uint32_t>(stoi(line));
        uint32_t k = wires[inputs[i]];
        circuitWires[i] = k;
    }

    while (getNextLine(circuitFile, line)) {
        istringstream circuitLine(line);
        string gate;
        uint32_t input1, input2, output1, output2;
        circuitLine >> gate;
        if (gate == "O") {
            uint32_t j = 0;
            while (circuitLine.peek() != EOF) {
                uint32_t k;
                circuitLine >> k;
                wires[outputs[j]] = circuitWires[k];
                j++;
            }
            continue;
        }
        circuitLine >> input1 >> input2 >> output1;
        if (gate == "X") {
            gate = "P";
            circuitLine >> output2;
        }

        ostringstream oss;
        oss << gate << " " << circuitWires[input1] << " " << circuitWires[input2] << " " << counter;
        circuitWires[output1] = counter;
        counter++;
        if (gate == "P") {
            oss << " " << counter;
            circuitWires[output2] = counter;
            counter++;
        }
        file << endl << oss.str();
    }
    circuitFile.close();
}

/**
 * the given line represents the input/output wire description of a circuit. The path to the circuit file is build and
 * distinguish if it is a public or private circuit. At the end of the function the circuit is translated into the
 * ABY file format considering the wire mappings between merger file and ABY file.
 * @param path the path to the circuit
 * @param circuitName the name of the circuit
 * @param iss the given line
 * @param file the ABY output file
 * @param pfile the programming bits of the UC components
 * @param wires the map between wire ID's in the merger file and the ABY file (updated in this function)
 * @param counter number of wires (updated in this function)
 */
void handleCircuits(string path,
                    string circuitName,
                    istringstream &iss,
                    fstream &file,
                    fstream &pfile,
                    map<uint32_t, uint32_t> &wires,
                    uint32_t &counter) {
    size_t lastIndex = circuitName.find_last_of('.');
    string rawName = circuitName.substr(0, lastIndex);
    string circuitFilename = path + "/" + rawName;
    string progFilename = circuitFilename;
    bool pub;
    if (stringEndsWith(circuitName, PUBLIC_CIRCUIT_ENDING)) {
        circuitFilename += CIRCUIT_ENDING;
        pub = true;
    } else if (stringEndsWith(circuitName, PRIVATE_CIRCUIT_ENDING)) {
        circuitFilename += UC_ENDING;
        progFilename += PROG_ENDING;
        pub = false;
    } else {
        cerr << circuitName << " is an invalid file name" << endl;
        throw ParsingException();
    }
    if (pub) {
        parsePublicCircuit(circuitFilename, iss, file, wires, counter);
    } else {
        fstream ucProgFile(progFilename, ios::in);
        string line;
        while (getline(ucProgFile, line)) {
            pfile << line << endl;
        }
        parseUC(circuitFilename, iss, file, wires, counter);
    }
}

/**
 * reads the merger file and translate it into the ABY file format
 * @param path to merger file
 */
void read_merger(string mergeFileName) {
    size_t lastIndex = mergeFileName.find_last_of('.');
    string rawName = mergeFileName.substr(0, lastIndex);
    lastIndex = rawName.find_last_of('/');
    string path;
    if (lastIndex != string::npos) {
        path = rawName.substr(0, lastIndex);
    }
    string outputFileName = rawName.append(".circuit");
    string outputProgrammingFileName = rawName.append(".prog");

    fstream mergeFile(mergeFileName, ios::in);
    mergeFile = fstream(mergeFileName, ios::in);
    fstream outputFile(outputFileName, ios::out);
    fstream outputProgrammingFile(outputProgrammingFileName, ios::out);

    map<uint32_t, uint32_t> wireMap;
    uint32_t counter = 0;
    string line;
    parseType type = CIRC_IN;
    while (getNextLine(mergeFile, line)) {
        istringstream mergeLine(line);
        string current;
        mergeLine >> current;
        if (isValidParsingString(current, type)) {
            if (current == "C" || current == "S") {
                if (type == SEMI_IN) {
                    outputFile << endl;
                }
                handleInputs(current, mergeLine, outputFile, wireMap, counter);
                type = type == SEMI_IN ? IN : SEMI_IN; // allow only one time SEMI_IN state
            } else if (current == "outputs") {
                type = CIRC_OUT;
                ostringstream oss;
                oss << endl << "O";
                vector<uint32_t> range = getRange(mergeLine, type);
                for (auto i : range) {
                    oss << " ";
                    oss << wireMap[i];
                }
                outputFile << oss.str();
            } else { // must be a circuit file
                handleCircuits(path, current, mergeLine, outputFile, outputProgrammingFile, wireMap, counter);
                type = IN;
            }
        } else {
            cerr << "Couldn't parse " << current << endl;
            throw ParsingException();
        }
    }
    outputProgrammingFile.close();
    outputFile.close();
    mergeFile.close();
}
