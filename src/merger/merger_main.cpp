#include <iostream>
#include "merger.h"

#define TIME

/**
 * returns the current time in ms
 * @return current time in ms
 */
inline clock_t getMilliSecs() {
    return clock() / (CLOCKS_PER_SEC / 1000);
}

/*
 * main function that simply runs the read_merger function of the merger library. It takes a merging file as input and
 * generates a complete circuit file
 * @param argc number of arguments
 * @param argv array of arguments
 * @return 0 if the merging file exists and can be parsed
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Enter a merging file" << endl;
        return 1;
    } else {
        string mergeFile = argv[1];
        cout << "run merger with file " << mergeFile << endl;
#ifdef TIME
        auto time1 = getMilliSecs();
#endif
        read_merger(mergeFile);
#ifdef TIME
        auto time2 = getMilliSecs();
        cout << "Runtime: " << time2 - time1 << " ms" << endl;
#endif
        cout << "finished merger" << endl;
        return 0;
    }
}
