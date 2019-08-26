
#include <gtest/gtest.h>
#include <merger.h>

/*
 * Tests for removeComments() function
 */

/*
 * tests an empty string
 */
TEST (removeComments, emptyString) {
    string result = removeComments("");
    EXPECT_EQ(result, "");
}

/*
 * tests a string without comments
 */
TEST (removeComments, noComments) {
    string testString = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\n\t/&()?+-";
    string result = removeComments(testString);
    EXPECT_EQ(result, testString);
}

/*
 * tests a string that contains uncommented and commented content
 */
TEST (removeComments, oneCommentMark) {
    string testString = "02857sjfh#58048371";
    string result = removeComments(testString);
    EXPECT_EQ(result, "02857sjfh");
}

/*
 * tests a string that contains uncommented and commented content with two comment marks.
 */
TEST (removeComments, twoCommentMarks) {
    string testString = "0123456#7890#9621";
    string result = removeComments(testString);
    EXPECT_EQ(result, "0123456");
}

/*
 * tests a whole commented string
 */
TEST (removeComments, wholeComment) {
    string testString = "#0123456";
    string result = removeComments(testString);
    EXPECT_EQ(result, "");
}
/*
 * tests a string that only contains the comment mark
 */

TEST (removeComments, onlyCommentMark) {
    string testString = "#";
    string result = removeComments(testString);
    EXPECT_EQ(result, "");
}

