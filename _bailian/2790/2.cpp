#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int n,x2,y2;
int flag;
bool check(int x,int y){
	if(flag||a[x][y]=='#'||x<0||y<0||x>=n||y>=n)return false;
	else return true;
}
void dfs(int x,int y){
	if(check(x,y)){
		a[x][y]='#';
		if(x==x2&&y==y2){
			flag=1;
			return;
		}
		dfs(x,y-1);
		dfs(x,y+1);
		dfs(x-1,y);
		dfs(x+1,y);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		flag=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;++i)
			cin>>a[i];
		int x1,y1;
		cin>>x1>>y1>>x2>>y2;
		dfs(x1,y1);
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

