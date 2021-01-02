#!/usr/bin/env python
from functools import reduce
from itertools import *
import sys

# 读入所有的数据
data = [ list(map(int,line.split())) for line in sys.stdin ]
n,m = data[0]
a = data[1][:]
a.insert(0,0)
for i in data[2:]:
    if len(i) == 4:
        o,x,y,z = i
        for j in range(x,y+1):
            a[j]+=z
    else:
        o,x,y = i
        s = 0
        for j in range(x,y+1):
            s+=a[j]
        print(s)
