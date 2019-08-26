#include <gtest/gtest.h>
#include <merger.h>
#include <fstream>

#define OUTPUT_FILE_HANDLE_INPUTS "src/tests/merger_tests/test_files/output.txt"

using namespace std;

/**
 * tests if the testInputs function writes the correct line in the file on the given parameters
 * @param current S if it is Server input, C if it is Client input
 * @param iss stream of the range of the input numbers
 * @param minValue smalles wire id of the input
 * @param maxValue highest wire id of the input
 * @param filename name of the file
 * @param counter current number of wires
 * @param wires mapping from the wires in the mering file to the wires in the ABY format file (updated in this function)
 */
void testInputs(string current,
                istringstream &iss,
                int minValue,
                int maxValue,
                string filename,
                uint32_t counter,
                map<uint32_t, uint32_t> &wires) {
    fstream file(filename, ios::out);
    handleInputs(current, iss, file, wires, counter);
    file.close();

    fstream file2(filename, ios::in);
    string line;
    getNextLine(file2, line);
    istringstream is(line);

    string cur;
    is >> cur;
    EXPECT_EQ(cur, current);

    for (int i = minValue; i <= maxValue; i++) {
        EXPECT_EQ(wires[i], i);
        is >> cur;
        EXPECT_TRUE(isNumber(cur));
        long lvalue = stoul(cur, nullptr, 10);
        auto value = static_cast<uint32_t>(lvalue);
        EXPECT_EQ(value, i);
    }
    file2.close();
}

/*
 * Tests for handleInputs() function
 */

/*
 * test for only client inputs
 */
TEST (handleInputs, clientInput) {
    string current = "C";
    istringstream iss("[ 0 4 ]");
    map<uint32_t, uint32_t> wires;
    testInputs(current, iss, 0, 4, OUTPUT_FILE_HANDLE_INPUTS, 0, wires);
}

/*
 * test for only server inputs
 */
TEST (handleInputs, serverInput) {
    string current = "S";
    istringstream iss("[ 0 12 ]");
    map<uint32_t, uint32_t> wires;
    testInputs(current, iss, 0, 12, OUTPUT_FILE_HANDLE_INPUTS, 0, wires);
}

/*
 * tests for client and server inputs. Client's inputs are specified first
 */
TEST (handleInputs, clientAndServerInput) {
    string current = "C";
    istringstream iss("[ 0 5 ]");
    map<uint32_t, uint32_t> wires;
    testInputs(current, iss, 0, 5, OUTPUT_FILE_HANDLE_INPUTS, 0, wires);
    current = "S";
    istringstream iss2("[ 6 18 ]");
    testInputs(current, iss2, 6, 18, OUTPUT_FILE_HANDLE_INPUTS, 6, wires);
}

/*
 * tests for server and client inputs. Server's inputs are specified first
 */
TEST (handleInputs, serverAndClientInput) {
    string current = "S";
    istringstream iss("[ 0 5 ]");
    map<uint32_t, uint32_t> wires;
    testInputs(current, iss, 0, 5, OUTPUT_FILE_HANDLE_INPUTS, 0, wires);
    current = "C";
    istringstream iss2("[ 6 18 ]");
    testInputs(current, iss2, 6, 18, OUTPUT_FILE_HANDLE_INPUTS, 6, wires);
}
