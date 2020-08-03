#!/usr/bin/env python
from cyaron import *
n = randint(1,100)
m = randint(1,100)
if n > m:
    n,m=[m,n]
print(n,m)
