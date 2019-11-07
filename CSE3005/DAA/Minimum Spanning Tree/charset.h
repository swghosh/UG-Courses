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

#define SET_MAX 256

struct charset {
    bool *presence;
};
#define CHARSET struct charset

void init(CHARSET *cs);
void reinit(CHARSET *cs);
void insert(CHARSET *cs, char item);
void delete(CHARSET *cs, char item);
bool contains(CHARSET *cs, char item);

#endif /* charset_h */
