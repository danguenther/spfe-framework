
#include <gtest/gtest.h>
#include <merger.h>

/*
 * Tests for stringEndsWith() function
 */

/*
 * tests an empty string that ends with a non empty string
 */
TEST (StringEndsWith, emptyString) {
    bool result = stringEndsWith("", "3gh38");
    EXPECT_FALSE(result);
}

/*
 * tests a string that has an empty suffix
 */
TEST (StringEndsWith, emptySuffix) {
    bool result = stringEndsWith("Teststring", "");
    EXPECT_TRUE(result);
}

/*
 * tests a string that has no line break at the end but the tested suffix has
 */
TEST (StringEndsWith, wrongSuffix1) {
    bool result = stringEndsWith("Teststring", "ing\n");
    EXPECT_FALSE(result);
}

/*
 * tests a string with correct suffix
 */
TEST (StringEndsWith, correctTest1) {
    bool result = stringEndsWith("Teststring", "ing");
    EXPECT_TRUE(result);
}

/*
 * tests another string with correct suffix
 */
TEST (StringEndsWith, correctTest2) {
    bool result = stringEndsWith("38hw8", "hw8");
    EXPECT_TRUE(result);
}

/*
 * tests a string with a one-char suffix
 */
TEST (StringEndsWith, oneCharSuffix) {
    bool result = stringEndsWith("Teststring", "g");
    EXPECT_TRUE(result);
}

/*
 * tests a string with the same suffix
 */
TEST (StringEndsWith, sameLength) {
    bool result = stringEndsWith("Test", "Test");
    EXPECT_TRUE(result);
}

/*
 * tests if string and suffix are case sensitive
 */
TEST (StringEndsWith, caseSensitive) {
    bool result = stringEndsWith("TesT", "est");
    EXPECT_FALSE(result);
}
