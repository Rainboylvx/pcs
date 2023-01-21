#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
priority_queue<int,vector<int>,greater<int> >qu;//开一个小根堆 
int n;
int ans=0;//全局最优解 
signed main()
{
    read(n);
    ans=0;
    for(int i=1,x;i<=n;i++)
    {
        read(x);//当前的股票价格 
        qu.push(x);//贪心策略：买价格最小的股票去买价格最大的股票 
        if(!qu.empty()&&qu.top()<x)//假如当前的股票价格不是最优解 
        {
            ans+=x-qu.top();//将差值计入全局最优解 
            qu.pop();//将已经统计的最小的股票价格丢出去 
            qu.push(x);//反悔策略：将当前的股票价格再放入堆中，即记录中间变量（等式中间无用的Ci） 
        }
    }
    printf("%lld\n",ans);//输出全局最优解 
    return 0;
} 
