#include <stdio.h>
#include <stdlib.h>

#define TYPE struct resource

TYPE *copy_array(TYPE *array, TYPE len);
void swap(TYPE *from, TYPE *to);
void permute(TYPE *prefix, TYPE *remaining, int pre_len, int rem_len, void (*callback)(TYPE*, int));

void print_array(int *array, int len);