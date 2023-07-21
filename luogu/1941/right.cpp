/*
ID：Mandy
language：c++
problem：luogu1941 bird
*/
#include<bits/stdc++.h>

#define M 1002
#define N 10002
#define Max(x,y) (x)>(y)?(x):(y)
#define Min(x,y) (x)<(y)?(x):(y)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,l,r) for(int i=r;i>=l;--i)

using namespace std;

int n,m,k,path[3][M],drop[3][M];//滚动数组存背包 
//path记录小鸟当前上升的路线最少次数，drop是当前下降的最少点击次数 
struct Conduit     
{
	int pos,ovr,bot;
}cdt[M];//管道  pos-位置，ovr-管道缝隙的上边沿高度，bot-管道缝隙的下边沿高度 
struct Rule 
{
	int inc,dec;
}rule[N];//飞翔规则 inc-上升高度，dec-下降高度 

inline int read()
{
	int x=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x;
}

inline void put(int x)
{
	if(x==0) {putchar('0'); return;}
	int num=0; char c[15];
	while(x){c[++num]=(x%10)^48; x/=10;}
	while(num) putchar(c[num--]);
}
//输入输出优化 
void docu()
{
	freopen("bird.in","r",stdin);
//	freopen("bird.out","w",stdout);
}

bool cmp(Conduit a,Conduit b)
{
	return a.pos<b.pos;
}

void readdata()
{
	n=read();
	m=read();
	k=read();
	up(i,1,n)
	{
		rule[i].inc=read();
		rule[i].dec=read();
	}
	up(i,1,k)
	{
		cdt[i].pos=read();
		cdt[i].bot=read();
		cdt[i].ovr=read();
	}
	sort(cdt+1,cdt+k+1,cmp);
	//注意输入数据并没有按管道从前往后的顺序 ，所以需要排序 
}

void work()
{
	int minans=1<<30;
	int num=1,now,pre;//num是指当前还未经过的管道的编号 
	int preu=1;
	int prev=m;//preu-上次能飞到的最低位置，prev-上次能飞到的最高位置
	int u=1,v=m;//u-能飞到的最低位置，v- 能飞到的最高位置
	up(i,1,n)
	{
		now=i&1;//now指当前在背包中的位置 
		pre=1-now;//指上一个单位时间在背包中的位置 
		bool judge=0;
		preu=u;
		prev=v;
		u=1,v=m;
		if(cdt[num].pos==i)//如果当前位置有管道 
		{
			u=cdt[num].bot+1;
			v=cdt[num].ovr-1;//管道占了的位置不能飞了 ，u是下限，v是上限 
			num++;
		}
		if(v==m)//如果可以到达顶层 
		{
			if(m==prev) path[now][m]=path[pre][m]+1;//如果上一个单位时间也可以到达顶层
		    else path[now][m]=0x3f3f3f3f;
		}
		
		up(j,1,m)
	    {
			if(j!=m) path[now][j]=0x3f3f3f3f;
			drop[now][j]=0x3f3f3f3f;//初始化 
	    	
			//上升 因为完全背包要覆盖叠加，所以从1到m都要算 
			int ht=j-rule[i].inc;//ht是指能到达j高度的上一单位时间的高度 
			if(j>v||j<u)//如果这次不能到达j高度 这里的值用于叠加 
			{   
			    if(ht>=preu)
			    {
				    if(ht<=prev) path[now][j]=Min(path[now][ht]+1,Min(path[pre][ht]+1,drop[pre][ht]+1));
					else path[now][j]=Min(path[now][ht]+1,path[now][j]);
			    }
			}
			else
			{
				if(ht>=preu&&ht<=prev) path[now][j]=Min(Min(path[now][j],drop[pre][ht]+1),path[pre][ht]+1);
	    	    if(ht>=1) path[now][j]=Min(path[now][j],path[now][ht]+1);//注意一维与二维的条件要相符 
			}
			
			ht=j+rule[i].dec;//下落 下落不能叠加或上升，故特判 
	    	if(ht<=prev&&ht>=preu&&j<=v&&j>=u) drop[now][j]=Min(path[pre][ht],drop[pre][ht]);
			
			if(v==m)//顶层特判 
			{
				
			    int q=(m-j)/rule[i].inc;
	    	    if(q*rule[i].inc!=m-j||j==m) q++;
			
				if(j<=prev&&j>=preu) path[now][m]=Min(path[now][m],Min(drop[pre][j]+q,path[pre][j]+q));
			    path[now][m]=Min(path[now][m],path[now][j]+q);
			}
			
			if(path[now][j]<0x3f3f3f3f||drop[now][j]<0x3f3f3f3f) judge=1;//如果可以通过 
		}
		if(judge==0)//如果不能通过 
		{
			putchar('0');
			putchar('\n');
			put(num-2);//num记录当前未到达的管道的编号，如果当前到达的管道不能通过，通过的管道应有num-2个 
			return;
		}
	}
	putchar('1');
	putchar('\n');
	up(i,u,v) minans=Min(minans,Min(path[now][i],drop[now][i]));//注意drop不要忘了 
	put(minans);
}

int main()
{
//  docu();
	readdata();//读入数据 
	work();
	return 0;
}
