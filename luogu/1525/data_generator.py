#!/usr/bin/env python
from cyaron import *

n = randint(5,10)
m = randint(n,(n*n-n)/2)
graph = Graph.graph(n, m, weight_limit=2000000) # 生成一个n点，m边的无向图，边权范围是1到20
print(n,m)
for edge in graph.iterate_edges(): # 遍历所有边，其中edge内保存的也是Edge对象
    # edge.start # 获取这条边的起点
    # edge.end # 获取这条边的终点
    # edge.weight # 获取这条边的边权
    # io.input_writeln(edge) # 输出这条边，以u v w的形式
    print(edge.start,edge.end,edge.weight)
