#!/usr/bin/env python
from cyaron import *

n = randint(5,10);
m = randint(n,n*(n-1)/2);
print(n,m)
graph = Graph.graph(n, m) # 生成一个n点，m边的无向图，边权均为1
for edge in graph.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
    print(edge.start,edge.end)
n = randint(5,10);
m = randint(n,n*(n-1)/2);
print(n,m)
graph = Graph.graph(n, m) # 生成一个n点，m边的无向图，边权均为1
for edge in graph.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
    print(edge.start,edge.end)
