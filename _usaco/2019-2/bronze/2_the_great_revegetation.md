---
title: "usaco 2019-2 铜牌组-2 the great revegetation"
level: 3
author: rainboy
create_time: 2019-07-02 17:44
update_time: 2019-07-02 17:44
tags:
    - usaco
    - 性质
source:
    - 
      oj: usaco
      url: http://usaco.org/index.php?page=viewproblem2&cpid=917
---

## 题目大意 && 解析

有$N$个点,每个点可以染成$4$种颜色,每个点关联的点不超过$3$个(也就是说一定有解!),关联点颜色不能一样,答案**字典序最小**.


思考:

第一个点,一定就$1$,因为一定有解,无论$1$号位置上的值就多少,利用替换的方式,都可以变成$1$

第二个点,一定就$1$或$2$,按同样的思想来.

如果$1,2$有冲突,那$2$号可以就$2,3,4$,同样可以用替换的思想变成$2$


## 代码


```c
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
    int N, M;
    int A[151], B[151], G[101];
    ifstream fin ("revegetate.in");
    fin >> N >> M;
    for (int i=0; i<M; i++) { 
        fin >> A[i] >> B[i];
        if (A[i] > B[i]) swap (A[i], B[i]);
    }

    ofstream fout ("revegetate.out");  
    for (int i=1; i<=N; i++) {
        int g;
        for (g = 1; g <= 4; g++) {
            bool ok = true;
            for (int j=0; j<M; j++) 
	            if (B[j] == i && G[A[j]] == g) ok = false;
            if (ok) break;
        }
        G[i] = g;
        fout << g;
    }
    fout << "\n";
    return 0;
}
```


