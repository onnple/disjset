# 不相交集(disjoint set)
不相交集操作函数说明  

### 1、创建一个不相交集
extern DisjSet *disjset_new(int n);

### 2、创建n个集合
extern void disjset_make_set(DisjSet *disjset, int n);

### 3、在集合中查找x
extern int disjset_find(DisjSet *disjset, int x); // root

### 4、合并两个集合
extern int disjset_union(DisjSet *disjset, int x, int y); // 0: cycle, 1: union

### 5、清空集合
extern int disjset_clear(DisjSet *disjset);

### 6、图的环检测
extern void disjset_cycle_detect(int array[][2], int n, int size);
