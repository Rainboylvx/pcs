/*
本题的图是一个 n 个点 n 条边的图，由于不保证整张图连通，因此根据定义可以知道这是一个基环树森林。

基环树森林中每一个连通块都是一个单独的基环树，根据渡船的规则可知一旦离开一颗基环树，就不能再渡船回来。

因此只需要对于每棵基环树内部，求一个最长简单路径，即基环树的直径。

所以本题的答案就是所有基环树的直径之和。

剩下的问题就是如何求出每棵基环树的直径。

首先对于每棵基环树的直径都能分成两种情况：

1. 在去掉 环 之后的某棵子树中。
2. 经过 环，其两端分别在去掉 环 上所有边之后的两棵不同子树中。

先用 dfs 找出基环树的 环，把 环 上的节点做上标记，设环上的节点为 s[1], s[2], ..., s[t]

从每个 s[i] 出发，在不经过环上其他节点的前提下，再次执行 dfs，访问去掉 环 之后以 s[i] 为根的子树，
在这样的每棵子树中，按照求树的直径的方法进行 树型dp 并更新答案，即可处理第一种情况，同时还可以计算出 d[s[i]]，
表示从节点 s[i] 出发走向以 s[i] 为根的子树，能够到达的最远节点的距离。

最后，考虑第二种情况，相当于找到环上两个不同的节点 s[i], s[j]，使得 d[s[i]] + d[s[j]] + dist(s[i], s[j]) 最大。
其中 dist(s[i], s[j]) 表示 s[i], s[j] 在环上的距离，有逆时针、顺时针两种走法，取较长的一种，可以将 环 断开
成链在复制一遍，用单调队列来求。
*/

#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx; //邻接表
int dfn[N], timestamp; //dfn[i] 表示节点 i 的时间戳(dfs序)
int fa[N]; //fa[i] 表示走到节点 i 的边的编号
int s[N * 2], cnt; //存储所有环上的节点，cnt表示环上节点数量
int q[N * 2]; //队列
LL d[N]; //d[i] 表示每个节点不经过环上节点能到达的最远距离
LL sum[N * 2]; //sum[i] 表示 d[1] ~ d[i] 的和(前缀和)
LL res, res_sum; //res 记录每棵基环树的直径长度，res_sum 记录所有基环树的直径长度之和
bool st[N]; //记录每个节点是否搜索过，树形dp时使用

void add(int a, int b, int c) //添加边
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void get_cycle(int a, int b, int c) //找出整个环
{
    sum[1] = c;
    while(a != b) //回推整个环
    {
        s[++cnt] = b;
        sum[cnt + 1] = w[fa[b]]; //记录边权
        b = e[fa[b] ^ 1]; //回推
    }
    s[++cnt] = a;

    for(int i = 1; i <= cnt; i++) //将环断开，复制一份到结尾
    {
        st[s[i]] = true; //标记环中节点
        s[cnt + i] = s[i];
        sum[cnt + i] = sum[i];
    }
    for(int i = 1; i <= cnt * 2; i++) sum[i] += sum[i - 1]; //求前缀和
}

void dfs(int u, int father) //求整个基环树的dfs序
{
    dfn[u] = ++timestamp;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue; //不往回搜

        if(!dfn[j])
        {
            fa[j] = i;
            dfs(j, u);
        }
        //如果当前子节点已经被遍历过，且时间戳比当前节点大，说明当前子节点是通过当前节点的另一个子节点找到走到的，即找到了环
        else if(dfn[u] < dfn[j])
            get_cycle(u, j, w[i]); //将 u -> j 的整个环找出来
    }
}

void dp(int u) //树形dp求以u为根节点的子树中的直径
{
    st[u] = true;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            dp(j);
            res = max(res, d[u] + d[j] + w[i]);
            d[u] = max(d[u], d[j] + w[i]);
        }
    }
}

int main()
{
    scanf("%d", &n);

    memset(h, -1, sizeof h); //初始化邻接表

    for(int i = 1; i <= n; i++)
    {
        int b, c;
        scanf("%d%d", &b, &c);
        add(i, b, c), add(b, i, c); //无向边
    }

    for(int u = 1; u <= n; u++) //枚举所有节点
        if(!dfn[u]) //如果当前节点第一次搜索到，说明找到新的基环树
        {
            cnt = 0, res = 0; //重置环中节点个数、基环树直径长度

            dfs(u, -1); //求整个基环树的dfs序

            for(int i = 1; i <= cnt; i++) dp(s[i]); //情况1

            //情况2
            int hh = 0, tt = -1;
            for(int i = 1; i <= 2 * cnt; i++) //单调队列
            {
                while(hh <= tt && q[hh] < i - cnt + 1) hh++;
                //直径 = i 能到达的最远距离 + q[hh] 能到达的最远距离 + dist(i, q[hh])
                if(hh <= tt) res = max(res, d[s[i]] + d[s[q[hh]]] + sum[i] - sum[q[hh]]);

                //保证每次的d[s[q[hh]]] - sum[q[hh]]都是最大值 (单调递减)
                while(hh <= tt && d[s[q[tt]]] - sum[q[tt]] <= d[s[i]] - sum[i]) tt--;
                q[++tt] = i;
            }
            res_sum += res; //累加当前基环树的直径长度
        }
    printf("%lld\n", res_sum);

    return 0;
}
