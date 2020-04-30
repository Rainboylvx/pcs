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
int n, m;
int st, p;
struct node {
    int to, next, w;
}e[20005];
int head[20005];
int dfn[20005], low[20005];
bool vis[20005];
int cnt = 1;
void add(int x, int y) {
    e[++cnt] = (node){y, head[x]};
    head[x] = cnt;
}
int x[20005], y[20005];
int tot;
int num;
stack<int> s;
int id[20005];
void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    s.push(x);
    for (int i = head[x]; i; i = e[i].next) {
        if (!vis[i]) {
            vis[i] = vis[i ^ 1] = 1;
            if (!dfn[e[i].to]) {
                tarjan(e[i].to);
                low[x] = min(low[x], low[e[i].to]);
            } else {
                low[x] = min(low[x], dfn[e[i].to]);
            }
        }
    }
    if(low[x] == dfn[x]) {
        tot++;
        int k = -1;
        while(x != k) {
            k = s.top();
            s.pop();
            id[k] = tot;
        }
    }
}
int du[20005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x[i], &y[i]);
        add(x[i], y[i]);
        add(y[i], x[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (id[x[i]] != id[y[i]]) {
            du[id[x[i]]]++;
            du[id[y[i]]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (du[i] == 1) ans++;
    }
    //printf("%d\n",tot);
    //printf("%d\n",ans);
    printf("%d\n", ans + 1 >> 1);
    return 0;
}
