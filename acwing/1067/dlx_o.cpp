#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5510;

int n, m;
int l[N], r[N], u[N], d[N], s[N], row[N], col[N], idx;
int ans[N], top;

void init()
{
    for (int i = 0; i <= m; i ++ )
    {
        l[i] = i - 1, r[i] = i + 1;
        u[i] = d[i] = i;
    }
    l[0] = m, r[m] = 0;
    idx = m + 1;
}

void add(int& hh, int& tt, int x, int y)
{
    row[idx] = x, col[idx] = y, s[y] ++ ; // set x,y,and cnt
    u[idx] = y, d[idx] = d[y], u[d[y]] = idx, d[y] = idx;
    r[hh] = l[tt] = idx; //这一行的开头与结尾
    r[idx] = tt, l[idx] = hh; //
    tt = idx ++ ; // ?
}

//删除 是如何删除的呢?
void remove(int p)
{
    r[l[p]] = r[p], l[r[p]] = l[p]; // <-[] ->
    for (int i = d[p]; i != p; i = d[i]) // 下降
        for (int j = r[i]; j != i; j = r[j]) // 这一行删除
        {
            s[col[j]] -- ;
            u[d[j]] = u[j], d[u[j]] = d[j];
        }
}

void resume(int p) // 恢复 删除
{
    for (int i = u[p]; i != p; i = u[i]) // 
        for (int j = l[i]; j != i; j = l[j])
        {
            u[d[j]] = j, d[u[j]] = j;
            s[col[j]] ++ ;
        }
    r[l[p]] = p, l[r[p]] = p;
}

bool dfs()
{
    if (!r[0]) return true;
    int p = r[0];
    for (int i = r[0]; i; i = r[i]) // 找到最小的列
        if (s[i] < s[p])
            p = i;
    remove(p); // 删除列
    for (int i = d[p]; i != p; i = d[i]) // 遍历这一列
    {
        ans[ ++ top] = row[i]; // 记录这个的行
        for (int j = r[i]; j != i; j = r[j]) remove(col[j]); // 这一行的那些点的列也不要
        if (dfs()) return true;
        for (int j = l[i]; j != i; j = l[j]) resume(col[j]);// 倒过来恢复
        top -- ;
    }
    resume(p);
    return false; // 遇到了一个空的列
}

int main()
{
    scanf("%d%d", &n, &m);
    init(); // 初始化
    for (int i = 1; i <= n; i ++ )
    {
        int hh = idx, tt = idx; // hh 这一行的开头,tt,这一行的结尾
        for (int j = 1; j <= m; j ++ )
        {
            int x;
            scanf("%d", &x);
            if (x) add(hh, tt, i, j); // 一行一行的添加
        }
    }

    if (dfs())
    {
        for (int i = 1; i <= top; i ++ ) printf("%d ", ans[i]);
        puts("");
    }
    else puts("No Solution!");

    return 0;
}
