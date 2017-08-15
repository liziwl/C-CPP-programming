#ifndef _HASHTABLE_HPP
#define _HASHTABLE_HPP
#define HASH_SIZE 509   // Better be a prime number to reduce collision.
#define LENGTH 1024
typedef struct file {
    char path[LENGTH];
    char name[LENGTH];
    long size;
    file *next;
    int s_count;
    // to specify whether the this file is the same with its neighbours.
    // if its neighbours are the same with itself, their s_count will be set to be the same.
    // e.g. for files having the same hash code: a1, a2, b, c1, and c2. a1 is the same with a2; c1 and c2 are the same.
    //                        a1  a2  b   c1  c2
    // their s_count will be: 0   0   1   2   2
} Node;


class Hashtable {
    Node **table;
    int size;
    int hash_func(unsigned long key);
    int defaultPath;
public:
    Hashtable();
    Hashtable(int s);
    void insert(Node *n);
    int print_table();
    ~Hashtable();
};

#endif
