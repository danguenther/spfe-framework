
#include <gtest/gtest.h>
#include <merger.h>

using namespace std;

/*
 * Tests for getRange() function
 */

/*
 * Tests a single ID
 */
TEST (getRange, singleID) {
    string testString = "3928";
    vector<uint32_t> expected = {3928};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * Tests two IDs
 */
TEST (getRange, twoIDs) {
    string testString = "3928 5827";
    vector<uint32_t> expected = {3928, 5827};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * Tests a simple range containing two successive IDs
 */
TEST (getRange, twoIDsRange) {
    string testString = "[ 3928 3929 ]";
    vector<uint32_t> expected = {3928, 3929};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * Tests a range containing two nonsuccessive IDs
 */
TEST (getRange, singleRange) {
    string testString = "[ 1 11 ]";
    vector<uint32_t> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * tests a mix of single IDs and ranges
 */
TEST (getRange, IDsAndRange) {
    string testString = "[ 1 6 ] 8 10 [ 12 17 ] 21 23 27";
    vector<uint32_t> expected = {1, 2, 3, 4, 5, 6, 8, 10, 12, 13, 14, 15, 16, 17, 21, 23, 27};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * tests a mix of single IDs and ranges that also contain the out keyword that interrupts the range
 */
TEST (getRange, outAfterRange) {
    string testString = "1 [ 3 6 ] 9 out 99 [ 100 103 ]";
    vector<uint32_t> expected = {1, 3, 4, 5, 6, 9};

    istringstream iss(testString);
    auto result = getRange(iss, IN);
    EXPECT_EQ(result, expected);
}

/*
 * tests if a ParsingException is thrown when opening two ranges without closing the first one
 */
TEST (getRange, twoOpenRangesWithoutClosing) {
    string testString = "[ 1 [ 3 17 ] ]";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests if a ParsingException is thrown when there is an unopened range closed
 */
TEST (getRange, closingRangeWithoutOpen) {
    string testString = "3 ] [ 7 9 ]";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests if a ParsingException is thrown when a range contains only one operand
 */
TEST (getRange, onlyOneRangeOperand) {
    string testString = "3 [ 7 ] 9";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests if a ParsingException is thrown when a range contains three operands
 */
TEST (getRange, threeRangeOperands) {
    string testString = "3 [ 5 7 9 ] 12";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}

/*
 * tests if a ParsingException is thrown if there a no whitespaces between breakets and IDs within a range
 */
TEST (getRange, rangeWithoutSpaces) {
    string testString = "3 [7 9]";
    istringstream iss(testString);

    try {
        auto result = getRange(iss, IN);
        FAIL() << "Expected Parsing Exception!";
    } catch (ParsingException e) {
        EXPECT_EQ(e.what(), "Parsing Exception!");
    } catch (exception e) {
        FAIL() << "Expected Parsing Exception, but got " << e.what();
    }
}
