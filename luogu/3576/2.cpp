#include <bits/stdc++.h>
#define rep(x, l, r) for(int x = l; x <= r; x++)
using namespace std;
typedef long long ll;

const ll INF = 1 << 30;
const int MAXN = 1e7 + 5;

int n, m, k, cnt, root1, root2;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1];
int a[MAXN];
ll dp1[MAXN], dp2[MAXN], c[MAXN];

void addedge(int u, int v){
	cnt++;
	nxt[cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

void add(int u, int v){
	addedge(u, v);
	addedge(v, u);
	c[u]++; c[v]++;
}

void dfs(int u, int fa){
	for(int e = head[u]; e; e = nxt[e]){
		int v = to[e];
		if(v == fa) continue;
		dp1[v] = min(INF, dp1[u] * (c[u] - 1));//防止炸longlong
		dp2[v] = min(INF, (dp2[u] + 1) * (c[u] - 1) - 1); 
		dfs(v, u);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m) scanf("%d", &a[i]);
	sort(a + 1, a + m + 1);
	scanf("%d%d", &root1, &root2);
	add(0, root1);//建一个0点与两个根节点连边
	add(0, root2);
	rep(i, 1, n - 2){
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	dp1[0] = dp2[0] = k;
	dfs(0, -1);
	ll ans = 0;
	rep(i, 1, n)
		if(c[i] == 1){
			ans += upper_bound(a + 1, a + m + 1, dp2[i]) - lower_bound(a + 1, a + m + 1, dp1[i]);
		}
	printf("%lld\n", ans * k);//最后记得要乘上k
	return 0;
}
