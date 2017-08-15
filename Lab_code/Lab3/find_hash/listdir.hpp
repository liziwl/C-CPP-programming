#ifndef _LISTDIR_HPP
#define _LISTDIR_HPP
#include "hashtable.hpp"
long get_file_size(const char *path);
int listDir(char *path, Hashtable *h_table);
#endif
