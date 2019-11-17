//
//  sort.h
//  Radix Sort
//
//  Created by Swarup Ghosh on 14/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>

unsigned int *counting_sort(unsigned int *array, size_t size, unsigned int radix);
unsigned int max(unsigned int *array, size_t size);

#endif /* sort_h */
