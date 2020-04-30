n = int(input())
raws = input()
# raws="1234"

for i in range(0,n):
    new_str = raws[:i] #+ raws[i+1,n-1]
print(raws[1:] == raws[0]+raws[2:])


