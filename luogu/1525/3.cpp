#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct edge{
	int v;
	int w;
};

vector<edge>e[100000+5];
int l=-1,r,mid;
int n,m;
int d[20000+5],color[100000+5];

void dfs(int k,int x) {
	color[k]=x;
	int len=e[k].size();
	for(int i=0;i<len;i++) {
		if(e[k][i].w>d[mid]&&color[e[k][i].v]==-1) {
			dfs(e[k][i].v,!x);
		}
	}
	return;
}

bool judge(int cur) {
	memset(color,-1,sizeof(color));
	for(int i=0;i<n;i++) {
		if(color[i]==-1) {
			dfs(i,0);
		}
	}
	for(int i=0;i<n;i++) {
		int len=e[i].size();
		for(int j=0;j<len;j++) {
			if(e[i][j].w>d[mid]&&color[i]==color[e[i][j].v])return false;
		}
	}
	return true;
}

int main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;
		b--;
		edge r;
		r.v=b;
		r.w=c;
		e[a].push_back(r);
		r.v=a;
		e[b].push_back(r);
		d[i]=c;
	}
	d[m]=0;
	sort(d,d+m+1);
	l = -1;
	r=m;
	while(r-l>1) {
		mid=(r+l)>>1;
		if(judge(d[mid])) {
			r=mid;
		} else {
			l=mid;
		}
	}
	printf("%d\n",d[r]);
	return 0;
}
