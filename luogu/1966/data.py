import os
import random

rnd = random.randint
n = 6
print(n)
a = [i for i in range(1,100)]
b = [i for i in range(1,100)]
random.shuffle(a)
random.shuffle(b)
a = a[:n]
b = b[:n]
print(" ".join(map(str,sorted(a))))
print(" ".join(map(str,sorted(b))))
