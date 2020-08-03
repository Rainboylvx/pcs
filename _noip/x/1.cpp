/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 26日 星期日 21:53:18 CST
* problem: luogu-1966
*----------------*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxn 1000005

struct _p{
    int idx;
    ll val;
    bool operator<(const _p &a){
        return val < a.val;
    }
};

int n;
vector<_p> a;
vector<_p> b1;
vector<_p> b2;
int bx[maxn];

int sor[maxn];

int c[maxn] = {0};


void init(){
    scanf("%d",&n);
    int i,t;
    for (i=0;i<n;i++){
        scanf("%d",&t);
        a.push_back({i,t});
    }
    for (i=0;i<n;i++){
        scanf("%d",&t);
        b1.push_back({i,t});
        b2.push_back({i,t});
    }
    sort(a.begin(),a.end());
    sort(b1.begin(),b1.end());

    int size = b1.size();
    for(i=0;i<size;i++){
        int val = b1[i].val;
        bx[val] = i; //val是第几大的数
    }
    for(i=0;i<size;i++){
        sor[i] = a[ bx[b2[i].val] ].idx;
        //cout << sor[i] << " ";
    }
}

int lowbit(int x){
    return x &(-x);
}

void update(int x,int val){
    while( x <= n){
        c[x] += val;
        x += lowbit(x);
    }
}

int query(int x){
    int sum = 0;
    while( x >0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}
/*  */
void deal(){
    int i;
    int ans=0;
    for (i=0;i<n;i++){
        update(sor[i]+1,1);
        ans = (ans +((i+1)-query(sor[i]+1))) %  99999997;
    }
    printf("%d\n",ans);
}

int main(){
    init();
    deal();
    return 0;
}
