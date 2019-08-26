#include <gtest/gtest.h>
#include <merger.h>
#include <fstream>

#define OUTPUT_FILE_PARSE_UC "src/tests/merger_tests/test_files/output.txt"
#define CIRCUIT_PATH_UC "src/tests/merger_tests/test_files/testCircuit1.priv.uc"

using namespace std;
/*
 * Tests for parseUC() function
 */

/*
 * tests if circuit is parsed correctly when it occurs at first circuit
 */
TEST(parseUC, firstCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    uint32_t counter = 2;

    fstream file(OUTPUT_FILE_PARSE_UC, ios::out);

    string circuitPath = CIRCUIT_PATH_UC;
    istringstream iss("[ 0 1 ] out 2 3");
    parseUC(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[2], 3);
    EXPECT_EQ(wires[3], 5);
    EXPECT_EQ(counter, 6);

    fstream file2(OUTPUT_FILE_PARSE_UC, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "P 0 1 2 3");
    getNextLine(file2, line);
    EXPECT_EQ(line, "Y 1 2 4");
    getNextLine(file2, line);
    EXPECT_EQ(line, "U 3 4 5");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}

/*
 * tests if circuit is parsed correctly when it occurs at the end or in the middle of the circuit
 */
TEST(parseUC, middleCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    wires[3] = 100;
    wires[4] = 168;
    wires[5] = 193;
    wires[6] = 204;
    uint32_t counter = 250;

    fstream file(OUTPUT_FILE_PARSE_UC, ios::out);

    string circuitPath = CIRCUIT_PATH_UC;
    istringstream iss("3 5 out 7 8");
    parseUC(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[7], 251);
    EXPECT_EQ(wires[8], 253);
    EXPECT_EQ(counter, 254);

    fstream file2(OUTPUT_FILE_PARSE_UC, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "P 100 193 250 251");
    getNextLine(file2, line);
    EXPECT_EQ(line, "Y 193 250 252");
    getNextLine(file2, line);
    EXPECT_EQ(line, "U 251 252 253");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}

/*
 * tests, if exception is throwns when number of inputs is not correct
 */
TEST(parseUC, wrongNumberOfInputs) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;
    istringstream iss("[ 0 2 ] out 3 4");
    string circuitPath = CIRCUIT_PATH_UC;

    try {
        fstream file(OUTPUT_FILE_PARSE_UC, ios::out);
        parsePublicCircuit(circuitPath, iss, file, wires, counter);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        string exception = e.what();
        EXPECT_EQ("Parsing Exception!", exception);
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests, if exception is thrown when number of inputs is not correct
 */
TEST(parseUC, wrongNumberOfOutputs) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;
    istringstream iss("[ 0 1 ] out 3 4 5");
    string circuitPath = CIRCUIT_PATH_UC;

    try {
        fstream file(OUTPUT_FILE_PARSE_UC, ios::out);
        parsePublicCircuit(circuitPath, iss, file, wires, counter);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        string exception = e.what();
        EXPECT_EQ("Parsing Exception!", exception);
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}
