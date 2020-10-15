import itertools
n = int(input())
a = list(map(int,input().split()))
# print(a)
b = itertools.product([1,2,3],repeat=n)
# 1 不操作
# 2 买
# 3 卖

# 检查是否合法
def check(l):
    l =list(map(lambda x: -1 if x == 2 else 1,filter(lambda x: not x == 1,list(l))))
    if( l.count(-1) != l.count(1)):
        return 0
    if len(l) ==0:
        return 0
    ll = list(itertools.accumulate(l))
    if not any([x > 0 for x in list(ll)]):
        return 1
    return 0
# 计算赚钱
def calc(l):
    return sum(map( lambda x,y:x*y,a,map(lambda x:[0,-1,1][x-1],l)))

cnt = 0
ans = 0

for l in b:
    if check(l):
        ans = max(ans,calc(l))
        cnt+=1 # 正确的买入的数量
print(ans)

