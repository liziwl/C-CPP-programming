#include <string.h>
#include <iostream>
#include "hashtable.hpp"
#include "filecom.cpp"
#ifndef _PRINT_DIR
#define _PRINT_DIR(ptr) { \
          cerr << "@ File: " << ptr->path << "/" << \
          ptr->name << "\t\tsize: " << ptr->size << endl; }
#endif
using std::endl;
using std::cerr;
using std::cout;

int Hashtable::hash_func(unsigned long key) {
    return key % HASH_SIZE;
}

Hashtable::Hashtable() {
    size = HASH_SIZE;
    table = new Node *[size];
    defaultPath = 0;
}

Hashtable::Hashtable(int defaultPath) {
    size = HASH_SIZE;
    table = new Node *[size];
    Hashtable::defaultPath = defaultPath;
}

void Hashtable::insert(Node *f) {
    if (f->size >= 0) {
        int index = hash_func(f->size);
        if (table[index] == NULL) {
            table[index] = new Node();
            strcpy(table[index]->path, f->path);
            strcpy(table[index]->name, f->name);
            table[index]->next = NULL;
            table[index]->size = f->size;
            table[index]->s_count = 0;
            _PRINT_DIR(table[index]);
        } else {
            Node *prev = table[index];

            Node *n = prev->next;
            // The problem with a hashtable is that nodes with different sizes may have identical index(i.e. the hash code)
            //    e.g. if the sizes are 242 and 1, after being divided by 241, the remainders are both 1.
            // The following algorithm arranges the nodes that have same index number, such that:
            // - Nodes with same size are grouped together
            // - Within such group, there are subgroups where identical nodes stay together,
            //   and each member in a specific subgroup has an identical and unique s_count value.
            // - Node added later will be inserted farther.
            //
            // e.g. For nodes   a    b   c1   c2    d    e    (c1 and c2 are identical)
            //          size    1   10   10   10    5  100
            //          s_count 0    1    2    2    3    4
            // If a new node z with size 10 is added to the list, the position will be between c2 and d.
            // to make the s_count to be modified more easiliy, subtraction is used for new node in the middle.
            // i.e.     nodes   a    b   c1   c2  [ z ]  d    e
            //          size    1   10   10   10  [10 ]  5  100
            //          s_count 0    1    2    2  [ 1 ]  3    4

            while (n != NULL) {
                if ((f->size == prev->size) && (prev->s_count != n->s_count)) {
                    long size = f->size;
                    int flag = is_file_same(prev->path, prev->name, f->path, f->name, size);
                    if(-1 == flag)                      // reading file error
                        break;
                    if (1 == flag) {                    // if the file at prev is the same with f
                        f->s_count = prev->s_count;     // mark the node f. s_count's are the same, because f is identical with prev.
                        break;
                    } else if (prev->size !=
                               n->size) { // if there is no identical node && we have to insert f in the middle of the list.
                        f->s_count = prev->s_count - 1;
                        break;
                    }
                }
                prev = n;
                n = n->next;
            }
            if (NULL == n) {
                if (f->size == prev->size) {
                    long size = f->size;
                    int flag = is_file_same(prev->path, prev->name, f->path, f->name, size);
                    if (1 == flag) {
                        f->s_count = prev->s_count;
                    } else if(0 == flag) {
                        f->s_count = prev->s_count + 1;
                    }
                } else {
                    f->s_count = prev->s_count + 1;
                }
            }
            // insert f between prev and n.
            prev->next = f;
            f->next = n;
            _PRINT_DIR(prev->next);
        }
    }

}

int Hashtable::print_table() {
    Node *prev = NULL;
    Node *n = NULL;
    int tmp = 0;
    int i = 0;
    int file_cout = 0;
    for (; i < size; i++) {
        prev = table[i];
        while (prev != NULL) {
            n = prev;
            tmp = prev->s_count;

            char p1[LENGTH];
            sprintf(p1, "%s/%s", prev->path, prev->name);
            char *p1ptr = p1 + defaultPath + 1;                 ///////////
            while ((n = n->next) != NULL && tmp == n->s_count) {
                char p2[LENGTH];
                sprintf(p2, "%s/%s", n->path, n->name);
                char *p2ptr = p2 + defaultPath + 1;               ///////////
                ++file_cout;
                cout << p1ptr << "\t" << p2ptr << endl;
            }
            prev = n;
        }
    }
    return file_cout;
}

Hashtable::~Hashtable() {
    Node *n_ptr = NULL;
    Node *prev = NULL;
    int i;
    for (i = 0; i < size; i++) {
        if ((prev = table[i]) != NULL) {
            while ((n_ptr = prev->next) != NULL) {
                delete prev;
                prev = n_ptr;
            }
            delete prev;
        }
    }
    delete[] table;
}
