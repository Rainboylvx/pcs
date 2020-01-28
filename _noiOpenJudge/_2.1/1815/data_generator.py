#!/usr/bin/env python
from cyaron import *

# n = randint(2,10);
n=3
print(n)
charsets = "wy"
for i in range(0,n):
    str = String.random(n,charset=charsets)
    print(str)
