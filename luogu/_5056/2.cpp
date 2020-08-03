#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define mo 590027
using namespace std;

int n,m,mapx[20][20]={0},endx,endy;
ll all_ans=0,dp[2][600000]={0};

int bits[28]={0};

int state[2][600000]={0},tots[2]={0};
int pre=1,cnt=0;

struct hash_table
{
  int pre,to;
}idx[600000]={0};
int ptr[600000]={0},at=0;

//------------FUNCTIONS HERE------------------------

inline void readx(int& x)
{
  x=0; int k=1; register char ch=0;
  while (ch<'0' || ch>'9') { ch=getchar(); if (ch=='-') k=-1; }
  while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar(); }
  x*=k;
}
inline void readit()
{
  readx(n); readx(m);
  char cht=0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
      cht=0; while (cht!='.' && cht!='*') cht=getchar();
      if (cht=='.') { mapx[i][j]=1; endx=i; endy=j; }
    }
}
inline void init_bits() { for (int i=1;i<=25;i++) bits[i]=(i<<1); }

inline void hah(int sta,ll val)
{
  int key=sta%mo;
  for (int prex=ptr[key];prex;prex=idx[prex].pre) if (state[cnt][idx[prex].to]==sta)
  {
    dp[cnt][idx[prex].to]+=val;
    return;
  }
  tots[cnt]++;
  state[cnt][tots[cnt]]=sta;
  dp[cnt][tots[cnt]]=val;
  
  idx[++at].pre=ptr[key];
  idx[at].to=tots[cnt];
  ptr[key]=at;
}

inline void DP()
{
  tots[cnt]=1; dp[cnt][1]=1;
  state[cnt][1]=0;
  
  for (int i=1;i<=n;i++)
  {
    for (int j=1;j<=tots[cnt];j++) state[cnt][j]<<=2;//!!!
    
    for (int j=1;j<=m;j++)
    {
      at=0; memset(ptr,0,sizeof ptr);//clear hash_table
      swap(pre,cnt);//rolling
      tots[cnt]=0;//clear state counter
      
      register int nowsta,is_d,is_r; register ll nowans;
      for (int k=1;k<=tots[pre];k++)
      {
        nowsta=state[pre][k],nowans=dp[pre][k];//get previous state&answer
        is_d=(nowsta>>bits[j])%4,is_r=(nowsta>>bits[j-1])%4;//get current plugs
        
        if (!mapx[i][j])//case 0
        {
          if ((!is_d) && (!is_r)) hah(nowsta,nowans);
        }
          
        else if ((!is_d) && (!is_r))//case 1
        {
          if (mapx[i+1][j] && mapx[i][j+1])
            hah(nowsta+(1<<bits[j-1])+2*(1<<bits[j]),nowans);
        }
            
        else if ((!is_d) && is_r)//case 2
        {
          if (mapx[i+1][j]) hah(nowsta,nowans);//go down
          if (mapx[i][j+1]) hah(nowsta-is_r*(1<<bits[j-1])+is_r*(1<<bits[j]),nowans);//go right
        }
        
        else if (is_d && (!is_r))//case 3
        {
          if (mapx[i][j+1]) hah(nowsta,nowans);//go right
          if (mapx[i+1][j]) hah(nowsta-is_d*(1<<bits[j])+is_d*(1<<bits[j-1]),nowans);//go down
        }
        
        else if (is_d==1 && is_r==1)//case 4
        {
          register int count=1;
          for (int l=j+1;l<=m;l++)
          {
            if ((nowsta>>bits[l])%4==1) count++;
            else if ((nowsta>>bits[l])%4==2) count--;
            if (!count)
            {
              hah(nowsta-(1<<bits[l])-(1<<bits[j])-(1<<bits[j-1]),nowans);
              break;
            }
          }
        }
        
        else if (is_d==2 && is_r==2)//case 5
        {
          register int count=1;
          for (int l=j-2;l>=0;l--)
          {
            if ((nowsta>>bits[l])%4==1) count--;
            else if ((nowsta>>bits[l])%4==2) count++;
            if (!count)
            {
              hah(nowsta-2*(1<<bits[j])-2*(1<<bits[j-1])+(1<<bits[l]),nowans);
              break;
            }
          }
        }
        
        else if (is_d==1 && is_r==2)//case 6
          hah(nowsta-2*(1<<bits[j-1])-(1<<bits[j]),nowans);
        
        else if (is_r==1 && is_d==2)//case 7
          if (i==endx && j==endy) all_ans+=(ll)nowans;
      }
    }
  }
}

int main()
{
  readit(); init_bits();
  DP();
  printf("%lld\n",all_ans);
  return 0;
}
