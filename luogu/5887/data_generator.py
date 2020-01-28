#!/usr/bin/env python
from cyaron import *

n = randint(4,10)
m = randint(2,5)
k = randint(1,n)
print(n,m,k)
l = [str(randint(0,n-1)) for i in range(0,m)]
print(' '.join(l))
