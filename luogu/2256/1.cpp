// map,trie,字符串hash
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
int n,m,k;
string s,s2; 

int fa[20005];

int find(int u){
    if( fa[u] == u) return u;
    return fa[u] = find(fa[u]);
}

void merge2(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if( fu != fv ) fa[fv] = fu;
}
int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i){
        cin >> s;
        mp[s] = i;
        fa[i] = i;
    }
    for(i=1;i<=m;++i){
        cin >> s >> s2;
        merge2( mp[s],mp[s2]);
    }
    scanf("%d",&k);
    for(i=1;i<=k;++i){
        cin >> s >> s2;
        if( find(mp[s]) == find(mp[s2]))
            printf("Yes.\n");
        else
            printf("No.\n");
    }

    return 0;
}




