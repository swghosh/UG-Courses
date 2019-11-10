//
//  charset.c
//  Minimum Spanning Tree
//
//  Created by Swarup Ghosh on 07/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include "charset.h"

void init(CHARSET *cs) {
    cs->presence = calloc(CHARSET_MAX, sizeof(bool));
}
void reinit(CHARSET *cs) {
    free(cs->presence);
    init(cs->presence);
}
void insert(CHARSET *cs, char item) {
    cs->presence[item] = true;
}
void remove(CHARSET *cs, char item) {
    cs->presence[item] = false;
}
bool contains(CHARSET *cs, char item) {
    return cs->presence[item];
}

CHARSET *difference(CHARSET *cs1, CHARSET *cs2) {
    CHARSET *diff;
    diff = malloc(sizeof(CHARSET));
    init(diff);
    
    int iter;
    for(iter = 0; iter < CHARSET_MAX; iter++) {
        diff->presence[iter] = cs1->presence[iter] - cs2->presence[iter];
    }
}

