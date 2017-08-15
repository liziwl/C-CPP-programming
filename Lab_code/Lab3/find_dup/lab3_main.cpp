#include "lab3_head.hpp"

extern int listDir(char *path, std::vector<file> &v);
extern bool cmp(Node x, Node y);
extern void print_list(std::vector<file> &v);
extern int list_all_cmp(std::vector<file> &v, int defaultPath_length, int file_count);
extern int freePtr(std::vector<file> &v);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "the argument cout is not 2,return 1" << std::endl;
        return 1;
    }

    // clock_t start, finish;
    // double duration;
    std::vector<file> v;

    // start = clock();
    int file_count = listDir(argv[1], v);
    stable_sort(v.begin(), v.end(), cmp);
    // finish = clock();

    // std::cerr << std::endl << "after sort:" << std::endl;
    print_list(v);
    std::cerr << std::endl << "Traversed the DIR." << std::endl;
    // duration = (double) (finish - start) / CLOCKS_PER_SEC;
    // std::cerr << "File count: " << file_count << std::endl;
    // std::cerr << "Traverse: " << duration << "s" << std::endl;

    // start = clock();
    int path_length = strlen(argv[1]);
    file_count = list_all_cmp(v, path_length, file_count);
    // finish = clock();

    freePtr(v);

    // duration = (double) (finish - start) / CLOCKS_PER_SEC;
    // std::cerr << "Comparison time: " << duration << "s" << std::endl;
    // std::cerr << "Identical file count: " << file_count << std::endl;
    return 0;
}
