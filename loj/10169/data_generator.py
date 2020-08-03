#!/usr/bin/env python
from cyaron import *
n = randint(100,2000)
m = randint(100,2000)
if n > m:
    n,m =[m,n]
print(n,m)
