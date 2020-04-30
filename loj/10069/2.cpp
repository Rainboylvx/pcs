#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 5e4 + 5,maxm = 2e5 + 5;
struct edge {
	int x,y,z,col;
}e[maxm];  
int n,m,need,l,r,mid,fa[maxn],sum,ans;
bool used[maxm];
edge e_n[maxm];

bool cmp(edge a,edge b) {
	return a.z < b.z || (a.z == b.z && a.col < b.col);	
}

int find(int x) {
	if (x == fa[x])
		return fa[x]; else
		return fa[x] = find(fa[x]);	
}

int check(int x) {
	sum = 0;
	int cnt = 0;
	
	for (int i=1; i<=m; i++)
		e_n[i] = e[i];
	memset(used,0,sizeof(used));
	for (int i=1; i<=m; i++)
		if (e_n[i].col == 0)
			e_n[i].z += x;
	sort(e_n + 1,e_n + m + 1,cmp);
	for (int i=1; i<=n; i++)
		fa[i] = i; 
	for (int i=1; i<=m; i++) {
		int x = e_n[i].x,y = e_n[i].y,z = e_n[i].z,col = e_n[i].col;
		if (find(x) != find(y)) {
			if (!col)
				cnt++; 
			used[i] = 1;
			fa[find(x)] = find(y);
			sum += z;
		}
	}
	return cnt; 
}

int main() {
//	freopen("tree.in","r",stdin);
	scanf("%d%d%d",&n,&m,&need);
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].z,&e[i].col);
		e[i].x++,e[i].y++;
	}
		
	l = -105,r = 105;
	int min_l = -1000;
	while (l <= r) {
		mid = (l + r) >> 1;
		int resul = check(mid);
		if (resul >= need) {
			ans = sum - need * mid; 
		 	l = mid + 1; 
		 	min_l = max(min_l,mid);
		} else
			if (resul < need) { 
				r = mid - 1; 
			}
	}
	printf("%d\n",ans);
	printf("min_l = %d\n",min_l);
	int choos = check(min_l);
	printf("%d\n",choos);
	return 0;
}
