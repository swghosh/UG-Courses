//
//  main.c
//  Tower of Hanoi
//
//  Created by Swarup Ghosh on 13/11/18.
//  Copyright © 2018 Swarup Ghosh. All rights reserved.
//

#include <stdio.h>

// tower of hanoi
// disk swaps using
// recursive technique
void towerOfHanoi(int diskId, char fromRodId, char toRodId, char bwRodId) {
    // base case
    if(diskId == 1) {
        printf("Moving disk with id %d from rod %d to %d rod.\n", diskId, fromRodId, toRodId);
    }
    // recursive case
    else {
        towerOfHanoi(diskId - 1, fromRodId, bwRodId, toRodId);
        printf("Moving disk with id %d from rod %d to %d rod.\n", diskId, fromRodId, toRodId);
        towerOfHanoi(diskId - 1, bwRodId, toRodId, fromRodId);
    }
}

int main() {
    int noOfDisks;
    // take user input for number of disks
    printf("How many disks? (integer expected) > ");
    scanf("%d", &noOfDisks);
    
    // from rod X
    // to rod Z
    // with rod in between Y
    towerOfHanoi(noOfDisks, 'X', 'Z', 'Y');
    return 0;
}
