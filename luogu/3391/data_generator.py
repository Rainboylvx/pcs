#!/usr/bin/env python
from cyaron import *
n = randint(10,20)
m = randint(10,20)
print(n,m)
for i in range(0,m):
    t1 = randint(1,n)
    t2 = randint(t1,n)
    print(t1,t2)
