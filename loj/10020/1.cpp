/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 09月 12日 星期六 11:07:50 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;
int a[100];
bool vis[100];
int sum = 0,_max=0;


void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        _max = max(a[i],_max);
        sum += a[i];
    }
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
}

stack<int> sta;
bool dfs(int dep,int len){
    vis[dep] = 1;
    len -= a[dep];
    sta.push(a[dep]);
    if( len == 0) return 1;
    for(int i =dep+1;i <=n;i++){
        if( a[i] > len) continue;
        if( vis[i] ) continue; //已经选过不选
        if( dfs(i,len)) return 1;
    }
    sta.pop();
    vis[dep] = 0;
    return 0;
}


bool work(int len){
    memset(vis,0,sizeof(vis));
    int t = sum;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if( dfs(i,len) ) {
            t -=len;
            if ( t== 0) return 1;

            int cnt=0;
            while(!sta.empty()){
                cout << sta.top() << " ";
                sta.pop();
                cnt++;
            }
            cout <<":" <<cnt << endl;

            continue;
        };
        return 0;
    }
    return 0;
}

int main(){
    init();
    int i;

    for(i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    cout<< endl;
    for(i=86;i<=86;i++){
        if( work(i)){
            printf("%d\n",i);
            return 0;
        }
        cout << "================ " << endl;
    }

    return 0;
}
