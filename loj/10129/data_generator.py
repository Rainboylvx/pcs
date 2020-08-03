#!/usr/bin/env python
from cyaron import *
n = 100000
p  = randint(2,10)
print(n,p)
# s1 = String.random((n,n), charset="1") # 生成一个10到20个字母之间的单词，从abcd1234共8个字符中随机选择
# print(" ".join(list(s1)))
a = [str(randint(1,100)) for _ in range(0,n)]
print(' '.join(a))
# m = randint(3,6)
m = 100
print(m)
for _ in range(0,m):
    l = randint(1,n)
    r = randint(1,n)
    if l > r:
        l,r = [r,l]
    op = randint(1,3)
    if op <3:
        print(op,l,r,randint(1,10))
    else:
        print(3,l,r)
