//
//  charset.c
//  Minimum Spanning Tree
//
//  Created by Swarup Ghosh on 07/11/19.
//  Copyright © 2019 Swarup Ghosh. All rights reserved.
//

#include "charset.h"

void init(CHARSET *cs) {
    cs->presence = calloc(SET_MAX, sizeof(bool));
}
void reinit(CHARSET *cs) {
    free(cs->presence);
    init(cs->presence);
}
void insert(CHARSET *cs, char item) {
    cs->presence[item] = true;
}
void delete(CHARSET *cs, char item) {
    cs->presence[item] = false;
}
bool contains(CHARSET *cs, char item) {
    return cs->presence[item];
}
