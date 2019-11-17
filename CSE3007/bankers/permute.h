#include <stdio.h>
#include <stdlib.h>

#ifndef TYPE

#define TYPE int

#endif

TYPE *copy_array(TYPE *array, int len);
void swap(TYPE *from, TYPE *to);
void permute(TYPE *prefix, TYPE *remaining, int pre_len, int rem_len, void (*callback)(TYPE*, int));

void print_int_array(int *array, int len);