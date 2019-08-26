
#include <gtest/gtest.h>
#include <merger.h>

/*
 * the main function for running the test suites of the merger
 * @param argc number of arguments
 * @param argv array of arguments
 * @return 0 if all tests pass, otherwise 1
 */
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

