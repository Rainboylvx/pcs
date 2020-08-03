max_dep = 3
def dfs(dep,pre):
    if dep == max_dep:
        return
    for i in range(0,10):
        print("{} {}".format("l"+str(dep)+str(pre),"l"+str(dep+1)+str(i)))
        dfs(dep+1,i)
dfs(1,0)
