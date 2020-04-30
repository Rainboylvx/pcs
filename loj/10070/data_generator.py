#!/usr/bin/env python
from cyaron import *

n = randint(5,10);
m = randint(n,(n*(n-1))/2)
print(n,m)
g = Graph.graph(n,m,weight_limit=10)
for edge in g.iterate_edges():
    print(edge.start,edge.end,edge.weight)
