#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<queue>
#define N 100010
using namespace std;

int n,trie[N][30],fail[N],jl[N],sk[N],tot=0,cnt=0,ed[N];
char s[N],t[N],ans[N];

void insert(char* a){
	int p=0,len=strlen(a);
	for(int i=0;i<len;i++){
		int ch=a[i]-'a';
		if(!trie[p][ch]) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	ed[p]=len;
	return;
}

void get_fail(){
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0][i]) fail[trie[0][i]]=0,q.push(trie[0][i]);
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(trie[now][i]){
				fail[trie[now][i]]=trie[fail[now]][i];
				q.push(trie[now][i]);
			}
			else trie[now][i]=trie[fail[now]][i];
		}
	}
	return;
}

void AC_work(){
	int p=0,len=strlen(s);
	for(int i=0;i<len;i++){
		p=trie[p][s[i]-'a'];
		jl[i]=p;
		sk[++cnt]=i;
		if(ed[p]){cnt-=ed[p];p=jl[sk[cnt]];}
	}
	return;
}

int main(){
	memset(ed,0,sizeof(ed));
	scanf("%s",s);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%s",t);insert(t);}
	get_fail();
	AC_work();
	for(int i=1;i<=cnt;i++) printf("%c",s[sk[i]]);
	printf("\n");
	return 0;
}
