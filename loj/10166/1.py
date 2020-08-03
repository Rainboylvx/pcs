raw = input()
a,b,c=map(int,raw.split(' '))
cnt = 0;
for _ in range(0,a+1):
    s = sum(map(int,list(str(_))))
    if s % 2 ==0:
        cnt+=1
        print("%d : %d" % (cnt,_))
cnt=0
print('\n')
print('\n')
for _ in range(0,b+1):
    s = sum(map(int,list(str(_))))
    if s % 2 ==0:
        cnt+=1
        print("%d : %d" % (cnt,_))
