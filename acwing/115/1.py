a = input().split()
l = len(a)
a = list(map(int,a))
sum = 0
for i in range(0,l):
    sum += (i+1)*a[i]
print(sum)
