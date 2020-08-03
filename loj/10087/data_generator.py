#!/usr/bin/env python
from cyaron import *

# n = randint(5,10);
n = 5
print(n)
for i in range(0,n):
    a = randint(0,8)
    b = randint(a,10)
    c = randint(0,b-a+1)
    print(a,b,c)
