//
// Created by Once on 2019/9/18.
//

#ifndef DATALGORITHM_DISJSET_H
#define DATALGORITHM_DISJSET_H

// 不相交集ADT对外接口
typedef struct disjset{
    int *parent;
    int *rank;
    int n;
} DisjSet;

// 不相交集函数声明
extern DisjSet *disjset_new(int n);
extern void disjset_make_set(DisjSet *disjset, int n);
extern int disjset_find(DisjSet *disjset, int x); // root
extern int disjset_union(DisjSet *disjset, int x, int y); // 0: cycle, 1: union
extern int disjset_clear(DisjSet *disjset);
extern void disjset_cycle_detect(int array[][2], int n, int size);

#endif //DATALGORITHM_DISJSET_H
