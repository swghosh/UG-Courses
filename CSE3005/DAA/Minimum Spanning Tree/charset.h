//
//  charset.h
//  Minimum Spanning Tree
//
//  Created by Swarup Ghosh on 07/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#ifndef charset_h
#define charset_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// will use a set data structure that can contain
// set of characters (0-225), limitation: max length
// of set is 256

// the set will be used with references of
// vertices in the graph for use with
// Prim's algorithm

struct charset {
    bool *presence;
};
#define CHARSET struct charset
#define CHARSET_MAX 256

void init(CHARSET *cs);
void reinit(CHARSET *cs);
void insert(CHARSET *cs, char item);
bool contains(CHARSET *cs, char item);

CHARSET *difference(CHARSET *cs1, CHARSET *cs2);
int element(CHARSET *cs, int position);

#endif /* charset_h */
