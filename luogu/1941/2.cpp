//背包?
//下降是01背包
// 上长是完全背包
// 我想不明白 为什么是背包 ,因为我不明白,背包的容量是什么
#include<bits/stdc++.h>
#include "utils/debug.hpp"
#define inf 1000000000
inline int min(const int &a,const int &b){return a<b?a:b;}
inline int read(){int x=0;char c=getchar();while(c<'0' || c>'9')c=getchar();while(c>='0' && c<='9')x=(x<<3)+(x<<1)+(c^'0'),c=getchar();return x;}//快读
inline int quzheng(int a,int b){if(a==0)return 1;return (a%b==0)?(a/b):(a/b+1);}//顾名思义，取整
int n,m,k,x[10001],y[10001],f[10001][1001],q[1001],l,r,ans;
bool b[10001][1001],g[10001];//b数组表示(i,j)是否有管子，g数组表示第i列是否有管子
int main()
{
	n=read(),m=read(),k=read();
	for( int i=1;i<=n;i++){x[i]=read(),y[i]=read();for( int j=1;j<=m;j++)f[i][j]=inf;}//初始化为正无穷
	for( int i=1,p,l,h;i<=k;i++){p=read(),l=read(),h=read();for( int j=0;j<=l;j++)b[p][j]=1;for( int j=h;j<=m;j++)b[p][j]=1;g[p]=1;}
	for( int i=1;i<=n;i++)
	{
		if(g[i-1])ans++;//统计已经跳过的管子数
		for( int j=1;j<=m-y[i];j++)if(!b[i][j])f[i][j]=f[i-1][j+y[i]];//状态转移
		if(!b[i][m] && x[i])for( int j=1;j<=m;j++)if(!b[i-1][j])f[i][m]=min(f[i][m],f[i-1][j]+quzheng(m-j,x[i]));//提前处理一下f[i,m]
		for( int j=0;j<x[i];j++)//处理每一组
		{
			l=1,r=0;//清空单调队列
			int maxp=(m-j)/x[i];//最多能点击多少次
			for( int k=0;k<=maxp;k++)
			{
				if(k*x[i]+j==0)continue;//横坐标为0的不能转移
				if(l<=r && !b[i][k*x[i]+j])f[i][k*x[i]+j]=min(f[i][k*x[i]+j],f[i-1][q[l]*x[i]+j]+k-q[l]);//转移
				if(f[i-1][k*x[i]+j]==inf)continue;//如果(i-1,k*x+j)无法到达就跳过
				while(l<=r && f[i-1][q[r]*x[i]+j]+k-q[r]>=f[i-1][k*x[i]+j])--r;//单调队列维护最小值
                q[++r]=k;//推入队尾
			}
		}
		bool bb=0;//检测是否有跳过该管子
		for( int j=1;j<=m;j++)if(f[i][j]!=inf){bb=1;continue;}
		if(!bb){

#ifdef DEBUG
            for(int i = 1 ;i<=n ;i++) {

                std::cout << i << ":\n";
                Tools::Table t;
                //输出第i列的所有的点的值
                for(int j=0;j<=m;++j){
                    t.push(j);
                }
                t.add_row();
                for(int j=0;j<=m;++j){
                    t.push(f[i][j]);
                }
                std::cout << t << '\n';
            }
#endif
            printf("0\n%d",ans);return 0;
        }//没跳过就直接退出
	}

#ifdef DEBUG
            for(int i = 1 ;i<=n ;i++) {

                std::cout << i << ":\n";
                Tools::Table t;
                //输出第i列的所有的点的值
                for(int j=0;j<=m;++j){
                    t.push(j);
                }
                t.add_row();
                for(int j=0;j<=m;++j){
                    t.push(f[i][j]);
                }
                std::cout << t << '\n';
            }
#endif
	printf("1\n");
	ans=inf;
	for( int i=1;i<=m;i++)ans=min(ans,f[n][i]);
	printf("%d",ans);
}
