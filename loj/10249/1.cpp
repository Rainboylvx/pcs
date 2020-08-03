#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

int n,m;
int nn;
int a[2005];
int b[2005];
bool S[1005];

void init(){
    scanf("%d",&n);
    nn = n<< 1;
    int i,j;
    For(i,1,nn){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int t;
    For(i,1,m){
        scanf("%d",&t);
        S[t] = 1;
    }
    sort(a+1,a+1+nn);
}
int cs[1005];
int ct[1005];
int head,tail;
int check_arr[1005];
bool check(){
    int i;
    int sum = 0;
    For(i,1,head){
        check_arr[i] = cs[i]-cs[i-1];
        sum += check_arr[i];
    }
    For(i,tail,n){
        check_arr[i] = ct[i]-ct[i+1];
        sum += check_arr[i];
    }
    
    if( sum != a[nn])
        return 0;
    int pre = cs[head];
    int cnt = n;
    For(i,head+1,n){
        b[++cnt] = pre+check_arr[i];
        pre+=check_arr[i];
    }
    pre = ct[tail];
    for( i =tail-1;i>=1;i--){
        b[++cnt] = pre+check_arr[i];
        pre+=check_arr[i];
    }
    sort(b+n+1,b+cnt+1);
    For(i,n+1,cnt){
        if( b[i] != a[i])
            return 0;
    }
    return 1;
}
bool dfs(int dep){
    if( head+1 == tail) { //边界
        if(check()){
            int i;
            For(i,1,n){
                printf("%d ",check_arr[i]);
            }
            printf("\n");
            return 1;
        }
        return 0;
    }

    int t = a[dep]-cs[head];
    if( t <= 500 && S[t]){
        cs[++head] = a[dep];
        if( dfs(dep+1) )
            return 1;
        head--;
    }
    t = a[dep] - ct[tail];
    if( t<= 500 && S[t]){
        ct[--tail] = a[dep];
        if( dfs(dep+1))
            return 1;
        tail++;
    }
    return 0;
}


int main(){
    init();
    head = 0 ,tail = n+1;
    dfs(1);

    return 0;
}
