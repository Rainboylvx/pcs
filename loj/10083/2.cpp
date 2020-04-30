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
int n, m, s, e;
struct node{
    int to, next, w, t;
}edge[605];
int cnt = 0;
int head[605];
void add(int p, int r, int c, int t) {
    edge[++cnt] = (node){r, head[p], c, t};
    head[p] = cnt;
    edge[++cnt] = (node){p, head[r], c, t};
    head[r] = cnt;
}
int dis[105][10005];
bool vis[105][10005];
queue< pair<int, int> > q;
void spfa() {
    memset(dis, 0x3f, sizeof(dis));
    dis[s][0] = 0;
    vis[s][0] = 1;
    q.push(make_pair(s, 0));
    while (!q.empty()) {
        int u = q.front().first, w = q.front().second;
        vis[u][w] = 0;
        q.pop();
        for (int i = head[u]; i; i = edge[i].next) {
            if (w + edge[i].w <= 10000) {
                if (dis[edge[i].to][w + edge[i].w] > dis[u][w] + edge[i].t) {
                    dis[edge[i].to][w + edge[i].w] = dis[u][w] + edge[i].t;
                    printf("%d %d %d\n", edge[i].to ,w + edge[i].w,dis[edge[i].to][w + edge[i].w]);
                    if (!vis[edge[i].to][w + edge[i].w]) {
                        vis[edge[i].to][w + edge[i].w] = 1;
                        q.push(make_pair(edge[i].to, w + edge[i].w));
                    }
                }
            }
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &e);
    int p, r, c, t;
    for (int i = 1; i <= m; i++) {
        cin >> p >> r >> c >> t;
        add(p, r, c, t);
    }
    spfa();
    int maxn = 0x3f3f3f3f, ans = 0;
    for (int i = 0; i <= 10000; i++) {
        if (dis[e][i] < maxn) {
            maxn = dis[e][i];
            ans++;
        }
    }
   printf("%d", ans);
    return 0;
}
