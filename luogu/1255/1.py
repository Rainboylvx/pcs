import os
a = [ 0 for i in range(0,50005)]
a[0]=0
a[1]=1
a[2]=2
n = int(input())
for i in range(3,n+1):
    a[i] = a[i-1]+a[i-2]
print(a[n])
