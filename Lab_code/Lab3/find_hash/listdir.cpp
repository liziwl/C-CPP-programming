#include <dirent.h>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "hashtable.hpp"

long get_file_size(const char *path) {
    long filesize = -1;
    struct stat statbuff;
    if (stat(path, &statbuff) < 0) //-1 is an error, 0 represent success. store the info. into stat
        return filesize;
    else
        filesize = statbuff.st_size;//how much byte
    return filesize;
}


int listDir(char *path, Hashtable *h_table) {
    int total = 0;
    DIR *pDir;
    struct dirent *ent;
    char childpath[LENGTH];

    pDir = opendir(path);
    memset(childpath, 0, sizeof(childpath)); //struct dirent reset

    if (NULL == pDir)
        return total;

    while ((ent = readdir(pDir)) != NULL) {
        if (ent->d_type & DT_DIR) {

            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;

            sprintf(childpath, "%s/%s", path, ent->d_name);

            total += listDir(childpath, h_table);

        } else {
            Node *f = (Node *) malloc(sizeof(Node));  // The Node pointer for current file
            strcpy(f->path, path);
            strcpy(f->name, ent->d_name);
            char pre[LENGTH];
            sprintf(pre, "%s/%s", path, ent->d_name);
            f->size = get_file_size(pre);

            ++total;
            h_table->insert(f);

        }
    }
    closedir(pDir);
    return total;
}
