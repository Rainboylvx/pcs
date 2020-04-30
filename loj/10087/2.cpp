#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f

#define eps 1e-15
#define maxn 50005

#define mem(a) memset(a, 0, sizeof(a))

struct EDGE {
  int v;
  int w;
  int next;
} edge[3 * maxn];
int head[maxn], d[maxn], vis[maxn], N, n, Max, Min;

void add(int u, int v, int w) {
  edge[N].v = v;
  edge[N].w = w;
  edge[N].next = head[u];
  head[u] = N++;
}

void spfa() {
  for (int i = Min; i <= Max; i++)
    d[i] = -inf;
  d[Min] = 0;
  queue<int> q;
  q.push(Min);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vis[x] = 0;
    for (int e = head[x]; e != -1; e = edge[e].next)
      if (d[edge[e].v] < d[x] + edge[e].w) {
        d[edge[e].v] = d[x] + edge[e].w;
        if (!vis[edge[e].v]) {
          q.push(edge[e].v);
          vis[edge[e].v] = 1;
        }
      }
  }
}

int main() {
  while (~scanf("%d", &n)) {
    // int u, v, w;
    int a, b, c;
    N = 0;
    memset(head, -1, sizeof(head));
    mem(vis);
    mem(edge);
    Min = inf;
    Max = -inf;
    for (int i = 0; i < n; i++) {
      // b-(a-1)>=c
      scanf("%d%d%d", &a, &b, &c);
      add(a, b + 1, c);
      Min = min(Min, a);
      Max = max(Max, b + 1);
    }
    for (int i = Min; i < Max; i++) {
      // s[i+1]-s[i]>=0

      // s[i+1]-s[i]<=1
      // s[i]-s[i+1]>=-1
      add(i, i + 1, 0);
      add(i + 1, i, -1);
    }
    spfa();
    printf("%d\n", d[Max]);
  }
  return 0;
}
