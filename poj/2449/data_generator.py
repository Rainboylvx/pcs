#!/usr/bin/env python
from cyaron import *

n = randint(5,10);
m = randint(10,80);
r = randint(1,5);

graph = Graph.graph(n, m, directed=True, weight_limit=(5, 300)) # 生成一个n点，m边的有向图，边权范围是5到300
# io.input_writeln(graph) # 输出这个图，以每条边u v w一行的格式
print(n,m)
print(graph.to_str())
print(1,n,r)

