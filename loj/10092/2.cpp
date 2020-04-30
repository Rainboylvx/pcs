#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define inf 0x3f3f3f3f
int n, m, mod;
int a[100005];
struct node {
    int to, next;
}e[2000005], e2[2000005];
int head[2000005];
int head2[2000005];
int dfn[100005], low[100005];
bool vis[100005];
int cnt;
int cnt2;
void add(int x, int y) {
    e[++cnt] = (node){y, head[x]};
    head[x] = cnt;
}
void add2(int x, int y) {
    e2[++cnt2] = (node){y, head2[x]};
    head2[x] = cnt2;
}
int ans;
int tot;
int num;
stack<int> s;
int id[100005];
int sum[100005];
int size[100005];
int f[100005];
int g[100005];
int used[100005];
void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    s.push(x);
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next) {
        if (!dfn[e[i].to]) {
            tarjan(e[i].to);
            low[x] = min(low[x], low[e[i].to]);
        } else if (vis[e[i].to]) {
            low[x] = min(low[x], dfn[e[i].to]);
        }
    }
    if(low[x] == dfn[x]) {
        int k = -1;
        tot++;
        while(x != k) {
            k = s.top();
            s.pop();
            vis[k] = 0;
            id[k] = tot;
            sum[tot]++;
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &mod);
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = sum[i];
        g[i] = 1;
        for (int j = head[i]; j; j = e[j].next) {
            if (id[i] != id[e[j].to]) {
                add2(id[i], id[e[j].to]);
            }
        }
    }
    for (int i = tot; i >= 1; i--) {
        for (int j = head2[i]; j; j = e2[j].next) {
            if (used[e2[j].to] == i) continue;
            used[e2[j].to] = i;
            if(f[e2[j].to] < f[i] + sum[e2[j].to]) {
                f[e2[j].to] = f[i] + sum[e2[j].to];
                g[e2[j].to] = g[i];
            } else if(f[e2[j].to] == f[i] + sum[e2[j].to]) {
                g[e2[j].to] += g[i];
                g[e2[j].to] %= mod;
            }
        }
    }
    int ans2 = 0;
    for (int i = 1; i <= tot; i++) {
        if(f[i] > ans) {
            ans = f[i];
            ans2 = g[i];
        } else if(f[i] == ans) {
            ans2 += g[i];
            ans2 %= mod;
        }
    }
    printf("%d\n%d\n", ans, ans2);
    return 0;
}
