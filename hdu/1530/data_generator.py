#!/usr/bin/env python
from cyaron import *

# n = randint(5,10);
n = 4
m = n*(n-1)/2
graph = Graph.graph(n, m)
print(n)
a = [ [ 0 for j in range(0,n+1)] for i in range(0,n+1)]
for edge in graph.iterate_edges():
    if( edge.end != edge.start):
        a[edge.start][edge.end] = 1
        a[edge.end][edge.start] = 1
    
for i in range(1,n+1):
    print(" ".join(list(map(str,a[i][1:]))))
