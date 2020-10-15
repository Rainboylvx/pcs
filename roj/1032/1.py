need = 20*1000
h,r = map(int,input().split())
one = 3.1415159 * r*r*h;
cnt = 1
while True:
    if cnt*one >= need:
        break
    cnt += 1
print(cnt)


