#include "lab3_head.hpp"
#include "progress_bar.hpp"

extern int is_file_same(char *p1,char* name1 , char *p2,char *name2, long size);

void print_path(char *rawPath, char *name, int skip_length) {
    char *ptr = rawPath + skip_length+1;
    std::cout << ptr << "/" << name << "\t";
}

void print_list(std::vector<file> &v) {
    for (std::vector<file>::iterator it = v.begin(); it != v.end(); it++) {
        std::cerr << "@ File: " << it->path << "/" << it->name << "\t\tsize:" << it->size << std::endl;
    }
}

long get_file_size(const char *path) {
    long filesize = -1;//warn
    struct stat statbuff;
    if (stat(path, &statbuff) < 0) //-1 is an error, 0 represent success. store the info. into stat
        return filesize;
    else
        filesize = statbuff.st_size;//how much byte
    return filesize;
}

int listDir(char *path, std::vector<file> &v) {
    int total = 0;
    DIR *pDir;
    struct dirent *ent;
    char childpath[512];

    pDir = opendir(path);
    memset(childpath, 0, sizeof(childpath)); //struct dirent reset

    if (NULL == pDir)
        return total;

    while ((ent = readdir(pDir)) != NULL) {
        if (ent->d_type & DT_DIR) {

            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            sprintf(childpath, "%s/%s", path, ent->d_name);
            //go to subdirectory
            total += listDir(childpath, v);

        } else {
            Node *f = (Node *) malloc(sizeof(Node));
            strcpy(f->path, path);
            strcpy(f->name, ent->d_name);
            char pre[512];
            sprintf(pre, "%s/%s", path, ent->d_name);
            f->size = get_file_size(pre);
            f->printed = 0;
            f->first = 0;

            ++total;
            v.push_back(*f);
        }
    }
    closedir(pDir);
    return total;
}

int freePtr(std::vector<file> &v) {
    std::vector<file>().swap(v);
    return 0;
}

int list_all_cmp(std::vector<file> &v, int defaultPath_length, int file_count) {
    /*return comparison times
    
    Traverse the vector with 2 pointers, cheak all the file in the same size, 
    if they are same, mark them printed(compared), 
    if not do nothing, go to the next.*/

    int _fc_ = 0; //file counter
    ProgressBar *bar1 = new ProgressBar( file_count, "Find duplicates", std::cerr);
    int pos = 0;//now position
    bar1->Progressed(pos);
    std::vector<file>::iterator current = v.begin();
    std::vector<file>::iterator next = current + 1;
    ++pos;
    while (current != v.end()) {
        if (next == v.end()) {
            ++pos;
            bar1->Progressed(pos);
            break;
        }
        if (
                (current->size > next->size) ||
                ((1 == current->printed) && (0 == current->first))
                ) {
            ++current;
            ++pos;
            bar1->Progressed(pos);
            next = current + 1;
            continue;
        }
        if (current->size == next->size) {
            if (1 == next->printed) {
                ++next;
                continue;
            } else {
                long size = current->size;
                if (1 == is_file_same(current->path, current->name, next->path, next->name, size)) {
                    if (0 == current->printed) {
                        std::cout << std::endl;
                        print_path(current->path, current->name, defaultPath_length);
                        current->printed = 1;
                        current->first = 1;
                    }
                    print_path(next->path, next->name, defaultPath_length);
                    next->printed = 1;
                    ++next;
                    ++_fc_;
                    continue;
                } else {
                    ++next;
                    continue;
                }
            }
        }
    }
    std::cerr << std::endl << "Finished the progress." <<std::endl;
    return _fc_;
}
