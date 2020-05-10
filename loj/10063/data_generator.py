#!/usr/bin/env python
from cyaron import *
n = randint(2,10)
print(n,10)
charsets = "ABCDEFGHIGKMLNOPQRSTUVWXYZ"
for _ in range(0,n):
    k = randint(2,10)
    l = len(charsets)-1
    ll = [charsets[randint(0,l)] for i in range(0,k)]
    print("".join(ll))
# print("".join([charsets[randint(0,l),charsets[randint(0,l)]]]))

