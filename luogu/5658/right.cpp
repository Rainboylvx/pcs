#include<bits/stdc++.h>
#define orz 0
#define inf 0x3f3f3f3f
#define ll long long
#define maxn 500005

using namespace std;

int n;
char c[maxn];
int head[maxn], nxt[maxn], to[maxn], cnt, fa[maxn];
ll lst[maxn], sum[maxn], ans;
int s[maxn], top;

void add_edge(int u, int v)
{
	nxt[++ cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

void dfs(int x)
{
	int tmp = 0;
	if(c[x] == ')')
	{
		if(top)
		{
			tmp = s[top];
			lst[x] = lst[fa[tmp]] + 1;
			-- top; 
		}
	}
	else if(c[x] == '(') s[++ top] = x; 
	sum[x] = sum[fa[x]] + lst[x]; //如上所述 
	for(int i = head[x]; i; i = nxt[i])
		dfs(to[i]); //递归 
	//回溯复原操作
	if(tmp != 0) s[++ top] = tmp; //不为 0 代表有信息被弹出 
	else if(top) -- top; 
	//为 0 代表没有弹出，如果栈不为空说明一定压入了一个信息，需要弹出这个信息复原 
}

int main()
{
	scanf("%d", &n);
	scanf("%s", c + 1);
	for(int i = 2; i <= n; i ++)
	{
		int f;
		scanf("%d", &f);
		add_edge(f, i);
		fa[i] = f;
	}
	dfs(1);
	for(int i = 1; i <= n; i ++)
    {
        std::cout << i << " : " << sum[i] << "\n";
		ans ^= sum[i] * (ll)i;
    }
	printf("%lld", ans);
	return orz;
}
