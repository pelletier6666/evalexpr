#ifndef MY_GETOPT_H
#define MY_GETOPT_H

#include <stddef.h>

enum traversal_type 
{
    none,
    prefix,
    infix,
    suffix
};

struct opt
{
    char *base;
    char *opr;
    enum traversal_type p;
    char l;
    char h;
};

struct opt *my_getopt(int argc, char **argv, int *error);

#endif /* MY_GETOPT_H */
