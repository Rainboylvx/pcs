#!/usr/bin/env python
from cyaron import *

n = 1000;
tree = Graph.tree(n) # 生成一棵n个节点的随机树
k = 1000;
for i in range(0,1000):
    print(n,k)
    for edge in tree.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
        edge.start # 获取这条边的起点
        edge.end # 获取这条边的终点
        edge.weight # 获取这条边的边权
        print(edge.start,edge.end,edge.weight)
print(0,0)
