#!/usr/bin/env python
from cyaron import *

n = 5
m = 10
print(n,m)
for i in range(1,11):
    a = randint(1,3)
    if a == 1:
        print(a,randint(1,n),randint(1,n))
    elif a == 2:
        print(a,randint(0,i-1))
    else:
        print(a,randint(1,n),randint(1,n))
