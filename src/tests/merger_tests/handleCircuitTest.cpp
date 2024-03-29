#include <gtest/gtest.h>
#include <merger.h>
#include <fstream>

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define PATH_HANDLE_CIRCUIT "src/tests/merger_tests/test_files"
#define OUTPUT_FILE_HANDLE_CIRCUIT "src/tests/merger_tests/test_files/output.txt"
#define OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT "src/tests/merger_tests/test_files/outputRef.txt"

#define CIRCUIT_FILE_PUB_HANDLE_CIRCUIT "testCircuit1.pub.c"
#define CIRCUIT_PATH_PUB_HANDLE_CIRCUIT "src/tests/merger_tests/test_files/testCircuit1.pub.circ"
#define CIRCUIT_FILE_PRIV_HANDLE_CIRCUIT "testCircuit1.priv.c"
#define CIRCUIT_PATH_PRIV_HANDLE_CIRCUIT "src/tests/merger_tests/test_files/testCircuit1.priv.uc"

#define PROG_OUTPUT_HANDLE_CIRCUIT "src/tests/merger_tests/test_files/prog.txt"

using namespace std;
/*
 * Tests for handleCircuit() function
 */

/*
 * tests if public circuit is handled correctly
 */
TEST(handleCircuit, publicCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    wires[2] = 2;
    uint32_t counter = 3;

    fstream file(OUTPUT_FILE_HANDLE_CIRCUIT, ios::out);
    fstream pfile(PROG_OUTPUT_HANDLE_CIRCUIT, ios::out);

    string path = PATH_HANDLE_CIRCUIT;
    string circuitFile = CIRCUIT_FILE_PUB_HANDLE_CIRCUIT;
    istringstream iss("[ 0 2 ] out 3 4");

    handleCircuits(path, circuitFile, iss, file, pfile, wires, counter);
    file.close();
    pfile.close();

    string circuitPath = CIRCUIT_PATH_PUB_HANDLE_CIRCUIT;
    istringstream iss2("[ 0 2 ] out 3 4");
    map<uint32_t, uint32_t> wires2;
    wires2[0] = 0;
    wires2[1] = 1;
    wires2[2] = 2;
    uint32_t counter2 = 3;
    fstream refFile(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::out);
    parsePublicCircuit(circuitPath, iss2, refFile, wires2, counter2);
    refFile.close();

    EXPECT_EQ(wires[3], wires2[3]);
    EXPECT_EQ(wires[4], wires2[4]);
    EXPECT_EQ(counter, counter2);

    fstream file3(OUTPUT_FILE_HANDLE_CIRCUIT, ios::in);
    fstream file4(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::in);
    string line, line2;

    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ (line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    EXPECT_FALSE(getNextLine(file3, line));
    file3.close();
    file4.close();
}

/*
 * tests if private circuit is handled correctly
 */
TEST(handleCircuit, privateCircuit) {
    map<uint32_t, uint32_t> wires;
    wires[0] = 0;
    wires[1] = 1;
    uint32_t counter = 2;

    fstream file(OUTPUT_FILE_HANDLE_CIRCUIT, ios::out);
    fstream pfile(PROG_OUTPUT_HANDLE_CIRCUIT, ios::out);

    string path = PATH_HANDLE_CIRCUIT;
    string circuitFile = CIRCUIT_FILE_PRIV_HANDLE_CIRCUIT;
    istringstream iss("[ 0 1 ] out 2 3");

    handleCircuits(path, circuitFile, iss, file, pfile, wires, counter);
    file.close();
    pfile.close();

    string circuitPath = CIRCUIT_PATH_PRIV_HANDLE_CIRCUIT;
    istringstream iss2("[ 0 1 ] out 2 3");
    map<uint32_t, uint32_t> wires2;
    wires2[0] = 0;
    wires2[1] = 1;
    uint32_t counter2 = 2;
    fstream refFile(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::out);
    parseUC(circuitPath, iss2, refFile, wires2, counter2);
    refFile.close();

    EXPECT_EQ(wires[2], wires2[2]);
    EXPECT_EQ(wires[3], wires2[3]);
    EXPECT_EQ(counter, counter2);

    fstream file3(OUTPUT_FILE_HANDLE_CIRCUIT, ios::in);
    fstream file4(OUTPUT_REFERENCE_FILE_HANDLE_CIRCUIT, ios::in);
    string line, line2;

    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ (line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    getNextLine(file3, line);
    getNextLine(file4, line2);
    EXPECT_EQ(line, line2);
    EXPECT_FALSE(getNextLine(file3, line));
    file3.close();
    file4.close();
}
