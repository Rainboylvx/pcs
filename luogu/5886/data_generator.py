#!/usr/bin/env python
from cyaron import *
import random

# n = randint(5,10);
n = int(1e6)
m = randint(5,10);
p = randint(1,n);

print(n,m,p)

## 不重复的选n个数
def not_repeat_choice(_list,n):
    ans = []
    for _ in range(0,n):
        idx = random.choice(list(range(0,len(_list))))
        ans.append(_list[idx])
        _list.pop(idx)
    return ans

for i in range(0,n):
    k = randint(0,m)
    a = [k]
    a += not_repeat_choice(list(range(1,m+1)),k)
    print(' '.join( map(str,a)))
