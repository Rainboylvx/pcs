#include<set>
#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;int n,m,x0,x,s,ga[100001],gb[100001],j,l,r,pos[100001],f[21][100001][2],ans;
long long da[21][100001][2],db[21][100001][2],la,lb;
double minn=1e17;
bool o;
struct node{int i,l,r;long long h;}p[100001];
inline bool cmp(node x,node y){return x.h<y.h;}
inline bool zuo()//判断是否左边的更优
{
    if(!l) return 0;
    if(!r) return 1;
    return p[j].h-p[l].h<=p[r].h-p[j].h;
}
inline int nearly(int a,int b)//比较a,b谁离j更近，返回更近的那个的原序号
{
    if(!a) return p[b].i;
    if(!b) return p[a].i;
    if(p[j].h-p[a].h<=p[b].h-p[j].h) return p[a].i;
    return p[b].i;
}
inline long long dist(int a,int b)//a和b对应的距离
{
    return abs(p[pos[a]].h-p[pos[b]].h);//因为是排了序的，所以要用pos
}
inline void solve(long long x,int st)//拼凑
{
    la=lb=0;o=0;
    for(register int i=20;i>=0;i--)
    if(f[i][st][o]&&la+lb+da[i][st][o]+db[i][st][o]<=x)//若还没走完且距离满足
    {
        la+=da[i][st][o];lb+=db[i][st][o];if(i==0) o^=1;st=f[i][st][o];//将其拼上
    }
    return;
}
inline long long read()
{
    char c;int d=1;long long f=0;
    while(c=getchar(),!isdigit(c))if(c==45)d=-1;f=(f<<3)+(f<<1)+c-48;
    while(c=getchar(),isdigit(c)) f=(f<<3)+(f<<1)+c-48;
    return d*f;
}
inline void write(long long x){if(x>9)write(x/10);putchar(x%10+48);return;}//以上为读写优化
signed main()
{
    freopen("1.txt","r",stdin);
    n=read();
    for(register int i=1;i<=n;i++) p[i].h=read(),p[i].i=i;//输入
    sort(p+1,p+1+n,cmp);//排序
    for(register int i=1;i<=n;i++) p[i].l=i-1,p[i].r=i+1,pos[p[i].i]=i;//链表日常
    p[1].l=0;p[n].r=0;//初始化
    for(register int i=1;i<=n;i++)//这里是求ga和gb
    {
        j=pos[i];l=p[j].l;r=p[j].r;
        if(zuo()) ga[i]=nearly(p[l].l,r),gb[i]=p[l].i;
        else ga[i]=nearly(l,p[r].r),gb[i]=p[r].i;
        if(l) p[l].r=r;
        if(r) p[r].l=l;//记得删除
    }
    for(register int i=1;i<=n;i++)//初始化第一天
    {
        if(ga[i]) f[0][i][0]=ga[i],da[0][i][0]=dist(i,ga[i]);
        if(gb[i]) f[0][i][1]=gb[i],db[0][i][1]=dist(i,gb[i]);
        da[0][i][1]=db[0][i][0]=0;
    }
    for(register int i=1;i<=20;i++)//以下为动态转移
     for(register int j=1;j<=n;j++)
      for(register int k=0;k<2;k++)
    {
        if(i==1) o=k^1;else o=k;
        if(f[i-1][j][k]) f[i][j][k]=f[i-1][f[i-1][j][k]][o];
        if(f[i][j][k])
        da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][o],
        db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][o];
    }
    x0=read();m=read();
    for(register int i=1;i<=n;i++)
    { 
        solve(x0,i);
        if(lb&&1.0*la/lb<minn)
        {
            minn=1.0*la/lb;
            ans=i;
        }
    }
    write(ans);putchar(10);
    while(m--)
    {
        j=read();x=read();
        solve(x,j);
        write(la);putchar(32);write(lb);putchar(10);
    }
}
