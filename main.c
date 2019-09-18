#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "disjset.h"


#define SIZE 7

int main(void) {
    int edges[SIZE][2] = {
            {0, 1}, {0, 2}, {1, 3},
            {1, 4}, {2, 4}, {2, 5}, {4, 5}
    };
    disjset_cycle_detect(edges, 6, SIZE);
    /**
     *  Êä³öÈçÏÂ£º
     *  cycle detected: 1
     *  cycle detected: 2
     *  cycle count: 2
     *  1 1 1 1 1 1
     * */
    return 0;
}