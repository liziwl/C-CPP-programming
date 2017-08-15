#include <dirent.h>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "hashtable.hpp"
#include "listdir.hpp"
#ifndef LENGTH
#define LENGTH 1024
#endif

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "the argument cout is not 2,return 1" << endl;
        return 1;
    }
//----------------------------------------------------------------
    clock_t start, finish;
    double duration;
    double duration2;
    start = clock();
//----------------------------------------------------------------
    int defaultPath = strlen(argv[1]);
    Hashtable *h_table = new Hashtable(defaultPath);
    int file_count = listDir(argv[1], h_table);
//----------------------------------------------------------------
    finish = clock();
    duration = (double) (finish - start) / CLOCKS_PER_SEC;
    cerr << "File count: " << file_count << endl;
    cerr << "Traverse and comparison: " << duration << "s" << endl;
    start = clock();
//----------------------------------------------------------------
    file_count = h_table->print_table();
//----------------------------------------------------------------
    finish = clock();
    duration2 = (double) (finish - start) / CLOCKS_PER_SEC;
    cerr << "Printing the table: " << duration2 << "s" << endl;
    cerr << "Identical file count: " << file_count << endl;
    cerr << "Total time: " << (duration + duration2) << "s" << endl;

    return 0;
}
