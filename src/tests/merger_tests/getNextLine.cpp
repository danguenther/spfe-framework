#include <gtest/gtest.h>
#include <merger.h>
#include <fstream>

#define TEST_FILE_GET_NEXT_LINE "src/tests/merger_tests/test_files/getNextLineTest.txt"

/*
 * Tests for getNextLine() function
 */

/*
 * tests if a whole line in a file can be read. This test covers multiple cases:
 * 1. The very first line of a file
 * 2. a line right after and before a comment
 * 3. a line that is completely commented
 * 4. a line that contains uncommented and commented content
 * 5. empty lines
 * 6. no more existing lines
 */
TEST (getNextLine, testFile) {
    string line;
    fstream file(TEST_FILE_GET_NEXT_LINE, ios::in);
    file = fstream(TEST_FILE_GET_NEXT_LINE, ios::in);
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "0123 294 293") << "first line";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "909473") << "sample line after comments";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "028564 658 86hhsg7 37fhb3") << "long line";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "hh438f87") << "line with comment";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "hrjbvh") << "sample line";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "jrbwhb") << "sample line";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "lkadgnrun") << "line right before a comment";
    EXPECT_TRUE(getNextLine(file, line));
    EXPECT_EQ(line, "huh") << "line after some comments";
    EXPECT_FALSE(getNextLine(file, line)) << "no more line available";
}
