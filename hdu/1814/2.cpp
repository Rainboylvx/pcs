/*
POI2001 和平委员会
by yyb
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define Oth(x) (x%2==0?x-1:x+1)

const int MAX=8005;

vector<int> e[MAX*2]; 
short int Col[MAX*2]; //color
int Ans[MAX];
int n,m,cnt,u,v;

int read()//读入优化
{
     int x=0;
     short int t=1;
     char ch=getchar();
     while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
     if(ch=='-'){t=-1;ch=getchar();}
     while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
     return x*t;
}

bool Paint(int x)//染色法 
{
      if(Col[x]!=0)//已经染过颜色了 
        return Col[x]%2;//若x染色为1则不矛盾，若x染色为2,则与原来染色矛盾 
      Col[x]=1;Col[Oth(x)]=2;//当前x染颜色1，另一个染为颜色2 
      Ans[++cnt]=x;//记录一组染色 
      for(int i=0;i<e[x].size();++i)
      {
            if(!Paint(e[x][i]))//向所有联通的点搜索
                return false;//如果染色出现了矛盾，则返回 
      }
      return true;//当前x染色成功 
}

bool Work()
{
      memset(Col,0,sizeof(Col));//清空染色的数组
      for(int i=1;i<=n*2;i+=2)//枚举所有的人 
      {
            if(Col[i])//已经染过色
               continue;//不用搜索
            cnt=0;//当前染色的组数 
            if(!Paint(i))//将i染色失败 
            {
                 for(int j=1;j<=cnt;++j)//本次染的颜色全部清空 
                      Col[Ans[j]]=Col[Oth(Ans[j])]=0;
                 if(!Paint(Oth(i)))//将i的另一个对应点染色 
                   return false;//如果也失败则无解 
            }
            else //染色成功
             continue;//继续染色 
      }
      return true;
}

int main()
{ 
     n=read();m=read();  
     for(int i=1;i<=m;++i)//读入并建立边 
     {
           u=read();
           v=read();
           // oth
           e[u].push_back(Oth(v));
           e[v].push_back(Oth(u));
     }
     if(Work())//尝试染色成功 
     {
            for(int i=1;i<=n*2;++i)
              if(Col[i]==1)
                cout<<i<<endl;
     }
     else//染色失败，无解 
       cout<<"NIE"<<endl;
     return 0; 
}
