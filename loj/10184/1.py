s = 1

T = [1,3,4,2,1]
C = [3,2,3,3,4]

# 1, 1, 1
# 1,2,3,4,5,6
splits = []
def split_range(len,n,pre):
    if n == 1:
        t = pre + [len]
        # print(" ".join(map(str,t)))
        splits.append(t)
        return 
    for i in range(1,len-n+1+1):
        split_range(len-i,n-1,pre+[i])

split_range(5,3,[])

for sp in splits: # 计算结论
    print(" ".join(map(str,sp))+" : ")
    ans = 0
    pre = 0
    time = 0
    for i in sp:
        time += s + sum(T[pre:pre+i])
        ans += sum(C[pre:pre+i])*time
        pre += i
    print("      {}".format(ans))

