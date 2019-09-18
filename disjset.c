//
// Created by Once on 2019/9/18.
//

#include "disjset.h"
#include <stdlib.h>
#include <stdio.h>

DisjSet *disjset_new(int n){
    if(n < 1){
        perror("n is too small");
        return NULL;
    }
    DisjSet *disjset = (DisjSet*)malloc(sizeof(DisjSet));
    if(!disjset){
        perror("alloc memory for disjset error");
        return NULL;
    }
    disjset->n = n;
    disjset->parent = (int*)malloc(n * sizeof(int));
    if(!disjset->parent){
        perror("alloc memory for parent error");
        free(disjset);
        return NULL;
    }
    disjset_make_set(disjset, n);
    disjset->rank = (int*)malloc(n * sizeof(int));
    if(!disjset->rank){
        perror("alloc memory for rank error");
        free(disjset->parent);
        free(disjset);
        return NULL;
    }
    for (int j = 0; j < n; ++j)
        disjset->rank[j] = 0;
    return disjset;
}

void disjset_make_set(DisjSet *disjset, int n){
    if(disjset == NULL){
        perror("disjset null");
        return;
    }
    for (int i = 0; i < n; ++i)
        disjset->parent[i] = i;
}

int disjset_find(DisjSet *disjset, int x){
    if(disjset == NULL){
        perror("disjset null");
        return 0;
    }
    // 压缩路径
    if(disjset->parent[x] != x)
        disjset->parent[x] = disjset_find(disjset, disjset->parent[x]);
    return disjset->parent[x];
}

int disjset_union(DisjSet *disjset, int x, int y){
    if(disjset == NULL){
        perror("disjset null");
        return 0;
    }
    int x_root = disjset_find(disjset, x);
    int y_root = disjset_find(disjset, y);
    if(x_root == y_root)
        return 0;
    // 按秩合并
    if(disjset->rank[x_root] > disjset->rank[y_root])
        disjset->parent[y_root] = x_root;
    else if(disjset->rank[x_root] < disjset->rank[y_root])
        disjset->parent[x_root] = y_root;
    else{
        disjset->parent[x_root] = y_root;
        disjset->rank[y_root] = disjset->rank[x_root] + 1;
    }
    return 1;
}

int disjset_clear(DisjSet *disjset){
    if(disjset == NULL)
        return 0;
    free(disjset->parent);
    free(disjset->rank);
    free(disjset);
    return 1;
}

void disjset_cycle_detect(int array[][2], int n, int size){
    if(array == NULL || size < 1)
        return;
    DisjSet *disjset = disjset_new(n);
    if(!disjset)
        return;
    int x, y, j = 0;
    for (int i = 0; i < size; ++i) {
        x = array[i][0];
        y = array[i][1];
        if(disjset_union(disjset, x, y) == 0)
            printf("cycle detected: %d\n", ++j);
    }
    if(j == 0)
        printf("cycle not found.\n");
    else
        printf("cycle count: %d\n", j);
    for (int k = 0; k < n; ++k) {
        printf("%d ", disjset->parent[k]);
    }
    disjset_clear(disjset);
}
