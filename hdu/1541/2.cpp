#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=100000+10;
int n,c[maxn],ans[maxn];

struct Stars{
    int x,y;
}a[maxn];

bool cmp(Stars a,Stars b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

inline int read(){
    register int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}
void add(int x,int y){
    for(;x<maxn;x+=lowbit(x)) c[x]+=y; 
}
int sum(int x){
    int ans=0;
    for(;x;x-=lowbit(x)) ans+=c[x];
    return ans;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) 
        a[i].x=read(),a[i].y=read();
    sort(a+1,a+n+1,cmp);
    int now;
    for(int i=1;i<=n;i++){
        now=sum(a[i].y+1);
        ans[now]++;
        add(a[i].y+1,1);
    }
    for(int i=0;i<n;i++) 
        printf("%d\n",ans[i]);
    return 0;
}
