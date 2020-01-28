#!/usr/bin/env python

# coding:utf-8
from cyaron import *
n = randint(5,20)
m = randint(5,20)
print(n,m)
arr = []
for i in range(0,n):
    str = String.random(m,charset="........................................XXXXXXXXXXXXXXXXXXXXXXABab")
    arr.append(str)
x = randint(0,n-1)
y = randint(0,m-1)
s = list(arr[x])
s[y] = 'S'
arr[x] = ''.join(s)

while 1:
    nx = randint(0,n-1)
    ny = randint(0,m-1)
    if( nx == x and y == y):
        continue
    s = list(arr[nx])
    s[ny] = 'G'
    arr[nx] = ''.join(s)
    break
for i in arr:
    print(i)
print(0,0)

