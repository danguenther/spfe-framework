
#include <gtest/gtest.h>
#include <merger.h>

/*
 * Tests for isNumber() function
 */

/*
 * test an empty string
 */
TEST (isNumber, emptyString) {
    bool result = isNumber("");
    EXPECT_FALSE(result);
}

/*
 * tests a word, no number
 */
TEST (isNumber, noNumber) {
    bool result = isNumber("hufuwG");
    EXPECT_FALSE(result);
}

/*
 * tests a single char, no number
 */
TEST (isNumber, singleCharNoNumber) {
    bool result = isNumber("g");
    EXPECT_FALSE(result);
}

/*
 * tests a mix of digits and chars
 */
TEST (isNumber, mixedDigitsAndLetters) {
    bool result = isNumber("389h8");
    EXPECT_FALSE(result);
}

/*
 * tests a correct number
 */
TEST (isNumber, correctNumber) {
    bool result = isNumber("3892");
    EXPECT_TRUE(result);
}

