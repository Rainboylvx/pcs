import random

n = random.randint(5,100)
m = random.randint(5,100)
s = random.randint(-100,100)
print(n,m,s)
for i in range(0,n):
    print(random.randint(1,200),random.randint(1,200))
for i in range(0,m):
    a = random.randint(1,n)
    b = random.randint(1,n)
    print(min(a,b),max(a,b))

