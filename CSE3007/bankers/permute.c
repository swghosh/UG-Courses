#include "permute.h"

TYPE *copy_array(TYPE *array, TYPE len) {
    int i;
    TYPE *new;
    // whenever copying an array, allow 
    // allocation of 1 extra integer
    new = malloc(sizeof(TYPE) * (len + 1)); 
    for(i = 0; i < len; i++) {
        new[i] = array[i];
    }
    return new; // allocated memory space can hold (len + 1) integers
}

void print_array(int *array, int len) {
    int i;
    for(i = 0; i < len; i++) printf("| %d |", array[i]);
    puts("");
}

void swap(TYPE *from, TYPE *to) {
    TYPE temp = *from;
    *from = *to;
    *to = temp;
}

void permute(TYPE *prefix, TYPE *remaining, int pre_len, int rem_len, void (*callback)(TYPE*, int)) {
    // base case
    if(rem_len == 0) {
        (*callback)(prefix, pre_len);
        return;
    }

    int i;
    TYPE *rem_copy, rem_copy_len;
    TYPE *pre_copy, pre_copy_len;
    for(i = 0; i < rem_len; i++) {
        pre_copy = copy_array(prefix, pre_len);
        pre_copy_len = pre_len;
        pre_copy[pre_copy_len] = remaining[i];
        pre_copy_len++;

        rem_copy = copy_array(remaining, rem_len);
        rem_copy_len = rem_len;
        swap(rem_copy + i, rem_copy + rem_copy_len - 1);
        rem_copy_len--;

        permute(pre_copy, rem_copy, pre_copy_len, rem_copy_len, callback);
    }
}

// int main() {
//     int limit = 4;
//     int a[4] = {1, 2, 3, 4};
    
//     int *b = copy_array(a, limit);
//     int *c = copy_array(a, 0);
//     int init_pre_len = 0, init_rem_len = limit;

//     permute(c, b, init_pre_len, init_rem_len, print_array);
// }