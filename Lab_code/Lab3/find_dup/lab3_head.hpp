#include <dirent.h>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <errno.h>

typedef struct file {
    char path[512];
    char name[512];
    long size;
    int printed;
    int first;
} Node;