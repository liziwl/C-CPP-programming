#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "filecom.hpp"

int mappingcom(char *path1, char *path2, long size) {
    long pagelen = 1000 * getpagesize();
    int value = 1;
    int count = size / pagelen + 1;
    long max;
    int lastpagelen = size - (count - 1) * pagelen;
    for (int j = 0; j < count; ++j) {
        if (count == 1)
            max = size;
        else if (count - j == 1)
            max = lastpagelen;
        else
            max = pagelen;
        int fd1, fd2 = 0;
        char *array1, *array2;
        fd1 = open(path1, O_RDONLY);
        fd2 = open(path2, O_RDONLY);
        if (fd1 == -1 || fd2 == -1) {
            std::cerr << "open: " << strerror(errno) << std::endl;
            return -1;
        }
        array1 = (char *) mmap(NULL, sizeof(char) * max, PROT_READ, MAP_SHARED, fd1, pagelen * j);
        array2 = (char *) mmap(NULL, sizeof(char) * max, PROT_READ, MAP_SHARED, fd2, pagelen * j);
        if ((array1 == (void *) -1) || (array2 == (void *) -1)) {
            std::cerr << "mmap: " << strerror(errno) << std::endl;
            return -1;
        }
        for (int i = 0; i < max; ++i) {
            if (array1[i] != array2[i]) {
                value = 0;
                break;
            }
        }
        munmap(array1, sizeof(char) * max);
        munmap(array2, sizeof(char) * max);
        close(fd1);
        close(fd2);
        if (value == 0)
            break;
    }
    return value;
}

int filecom(char *p1, char *p2, long size) {
    FILE *f1 = fopen(p1, "r");
    FILE *f2 = fopen(p2, "r");
    if( f1 == NULL || f2 == NULL ){
        std::cerr << "fopen: Cannot open files" << std::endl;
        return -1;
    }
    char c1 = fgetc(f1);
    char c2 = fgetc(f2);
    int key = 0;//0 means different, 1 means same.
    while (!feof(f1) && !feof(f2)) {
        if (c1 != c2) {
            key = 0;
            break;
        }
        c1 = fgetc(f1);
        c2 = fgetc(f2);
    }
    if (c1 == EOF && c2 == EOF)
        key = 1;
    else
        key = 0;
    fclose(f1);
    fclose(f2);
    return key;
}

int is_file_same(char *p1,char* name1 , char *p2,char *name2, long size) {
    if(size == 0){
        if(strcmp(name1,name2) == 0)
            return 1;
        else
            return 0;
    }
    char path1[1024];                     // the directory for prev
    char path2[1024];                     // the directory for f
    sprintf(path1, "%s/%s", p1, name1);
    sprintf(path2, "%s/%s", p2, name2);
    int tempre = -1;
    tempre = mappingcom(path1,path2,size);
    if( tempre == -1){
        std::cerr << "Mmap error.Use 'fread' to compare the files." << std::endl;
        tempre = filecom(path1,path2,size);
        if( tempre == -1)
            std::cerr << "file error in '" << path1 << "' and '" << path2 << "%s'" << std::endl;
    }
    return tempre;
}
