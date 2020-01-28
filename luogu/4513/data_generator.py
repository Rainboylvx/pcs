#!/usr/bin/env python
from cyaron import *

n = 5
m = 5
print(n,m)
charsets = "wy"
a = [str(randint(-n,n)) for _ in range(0,n)]
print(' '.join(a))
for _ in range(0,m):
    k = randint(1,2)
    if( k == 1):
        print( k,randint(1,n),randint(1,n))
    else:
        print( k,randint(1,n),randint(-n,n))

