#!/bin/env python3
import math
a = int(input())
wei = a * math.log10(2)
print(math.ceil(wei))
ans = pow(2,a)-1
idx = 1
num_500 = []

while idx <= 500 or ans != 0:
    num_500.append(ans % 10)
    ans = ans // 10
    idx+=1

while len(num_500) < 500:
    num_500.append(0)

ls = list(reversed(num_500))
for i in range(500):
    print(ls[i],end='')
    if (i+1) % 50 == 0:
        print()
