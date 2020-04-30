#!/usr/bin/env python
from cyaron import *


# n = randint(5,8);
n = 5
m = randint(1,n)
print(n,m)
tree = Graph.tree(n) # 生成一棵n个节点的随机树
for edge in tree.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
    print(edge.start,edge.end)
    # edge.start # 获取这条边的起点
    # edge.end # 获取这条边的终点
    # edge.weight # 获取这条边的边权
    # io.input_writeln(edge) # 输出这条边，以u v w的形式
for _ in range(0,m):
    print(randint(1,n),randint(1,n))
