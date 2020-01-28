#!/usr/bin/env python
from cyaron import *

# n = randint(5,10);
n = 4
m = n*(n-1)/2
graph = Graph.graph(n, int(m))
print(1)
print(n,int(m))
for edge in graph.iterate_edges():
    print(edge.start, edge.end)
