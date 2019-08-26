
#include <gtest/gtest.h>
#include <merger.h>

/*
 * Tests for isValidParsingString() function
 */

/*
 * tests keyword "out" in IN state and OUT state
 */
TEST (isValidParsingString, validIn1) {
    EXPECT_TRUE(isValidParsingString("out", IN));
    EXPECT_FALSE(isValidParsingString("out", OUT));
}

/*
 * tests keyword "outputs" in IN state and OUT state
 */
TEST (isValidParsingString, validIn2) {
    EXPECT_TRUE(isValidParsingString("outputs", IN));
    EXPECT_FALSE(isValidParsingString("outputs", OUT));
}

/*
 * tests keyword "C" in CIRC_IN state, SEMI_IN state, CIRC_OUT state and OUT state
 */
TEST (isValidParsingString, validCircInC) {
    EXPECT_TRUE(isValidParsingString("C", CIRC_IN));
    EXPECT_TRUE(isValidParsingString("C", SEMI_IN));
    EXPECT_FALSE(isValidParsingString("C", CIRC_OUT));
    EXPECT_FALSE(isValidParsingString("C", OUT));
}

/*
 * tests keyword "S" in CIRC_IN state, SEMI_IN state, CIRC_OUT state and OUT state
 */
TEST (isValidParsingString, validCircInS) {
    EXPECT_TRUE(isValidParsingString("S", CIRC_IN));
    EXPECT_TRUE(isValidParsingString("S", SEMI_IN));
    EXPECT_FALSE(isValidParsingString("S", CIRC_OUT));
    EXPECT_FALSE(isValidParsingString("S", OUT));
}

/*
 * tests components of a range in CIRC_OUT state
 */
TEST (isValidParsingString, range) {
    EXPECT_TRUE(isValidParsingString("[", CIRC_OUT));
    EXPECT_TRUE(isValidParsingString("]", CIRC_OUT));
    EXPECT_TRUE(isValidParsingString("7737982", CIRC_OUT));
}

/*
 * tests a circuit in IN state and OUT state
 */
TEST (isValidParsingString, circuitType) {
    EXPECT_TRUE(isValidParsingString("circuit.c", IN));
    EXPECT_FALSE(isValidParsingString("circuit.c", OUT));
}

/*
 * tests a wrong circuit format in all states
 */
TEST (isValidParsingString, wrongCircuit) {
    EXPECT_FALSE(isValidParsingString("abcd", IN));
    EXPECT_FALSE(isValidParsingString("abcd", OUT));
    EXPECT_FALSE(isValidParsingString("abcd", CIRC_IN));
    EXPECT_FALSE(isValidParsingString("abcd", CIRC_OUT));
}
