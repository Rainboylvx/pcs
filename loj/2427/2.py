from math import *
n = 100
for n in range(2,100):
    a = sum([ n//x for x in range(1,n+1)])
    print(n,a,(n*log(n,2)))
