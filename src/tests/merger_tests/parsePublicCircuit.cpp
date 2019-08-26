#include <gtest/gtest.h>
#include <merger.h>
#include <fstream>

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT "src/tests/merger_tests/test_files/output.txt"
#define CIRCUIT_PATH_PUB "src/tests/merger_tests/test_files/testCircuit1.pub.circ";

using namespace std;
/*
 * Tests for parsePublicCircuit() function
 */

/*
 * tests if circuit is parsed correctly when it occurs at first circuit
 */
TEST(parsePublicCircuit, firstCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;

    fstream file(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::out);

    string circuitPath = CIRCUIT_PATH_PUB;
    istringstream iss("[ 0 2 ] out 3 4");
    parsePublicCircuit(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[3], 4);
    EXPECT_EQ(wires[4], 5);
    EXPECT_EQ(counter, 6);

    fstream file2(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "X 0 1 3");
    getNextLine(file2, line);
    EXPECT_EQ(line, "A 2 3 4");
    getNextLine(file2, line);
    EXPECT_EQ(line, "X 4 -3 5");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}

/*
 * tests if circuit is parsed correctly if circuit occurs at the end or in the middle of the circuit
 */
TEST(parsePublicCircuit, middleCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    wires[3] = 100;
    wires[4] = 168;
    wires[5] = 193;
    wires[6] = 204;
    uint32_t counter = 250;

    fstream file(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::out);

    string circuitPath = CIRCUIT_PATH_PUB;
    istringstream iss("2 4 5 out 7 8");
    parsePublicCircuit(circuitPath, iss, file, wires, counter);
    file.close();

    EXPECT_EQ(wires[7], 251);
    EXPECT_EQ(wires[8], 252);
    EXPECT_EQ(counter, 253);

    fstream file2(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::in);
    string line;

    getNextLine(file2, line);
    EXPECT_EQ (line, "X 2 168 250");
    getNextLine(file2, line);
    EXPECT_EQ(line, "A 193 250 251");
    getNextLine(file2, line);
    EXPECT_EQ(line, "X 251 -3 252");
    EXPECT_FALSE(getNextLine(file2, line));
    file2.close();
}

/*
 * tests, if exception is thrown when number of inputs is not correct
 */
TEST(parsePublicCircuit, wrongNumberOfInputs) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;
    istringstream iss("[ 0 1 ] out 3 4");
    string circuitPath = CIRCUIT_PATH_PUB;

    try {
        fstream file(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::out);
        parsePublicCircuit(circuitPath, iss, file, wires, counter);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests if exception is thrown if number of outputs is not correct
 */
TEST (parsePublicCircuit, wrongNumberOfOutputs) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;
    istringstream iss("[ 0 2 ] out 3 4 5");
    string circuitPath = CIRCUIT_PATH_PUB;

    try {
        fstream file(OUTPUT_FILE_PARSE_PUBLIC_CIRCUIT, ios::out);
        parsePublicCircuit(circuitPath, iss, file, wires, counter);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        string exception = e.what();
        EXPECT_EQ("Parsing Exception!", exception);
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}
