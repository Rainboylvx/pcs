import random

rnd = random.randint

n = rnd(3,10)
print(n)
print(rnd(3,10),rnd(3,10))
for i in range(0,n):
    print(rnd(3,10),rnd(3,10))
