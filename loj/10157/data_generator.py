#!/usr/bin/env python
from cyaron import *

vis = [ 0 for i in range(0,100)]
node = [ [] for i in range(0,100)]
n = randint(5,10);
print(n)
tree = Graph.tree(n) # 生成一棵n个节点的随机树

def dfs(u):
    vis[u] = 1
    for e in tree.edges[u]:
        v= e.end;
        if vis[v] == 1:
            continue
        node[u].append(str(v))
        dfs(v)
dfs(1)
for i in range(1,n+1):
    a = []
    a.append(str(i))
    a.append(str(randint(1,30)))
    # a.append(str(i))
    a.append(str(len(node[i])))
    a += node[i]
    print(' '.join(a))
