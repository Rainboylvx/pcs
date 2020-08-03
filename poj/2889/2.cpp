#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
typedef long long ll;
const int maxn=130;
int real_map[maxn][maxn];
int ans=0;
int flag=0; 
int some[maxn][maxn];
int all[maxn][maxn];
int none[maxn][maxn];
void BronKerbosch(int idx,int all_idx,int some_idx,int none_idx)
{
    if (flag)return;
    if (!some_idx&&!none_idx)
    {
        ans++;
        if (ans>1000)flag=1;
        return;
    }
    if (!some_idx)return ;
    int pivot=some[idx][0];
    for(int i=0;i<some_idx;i++)
    {
        int v=some[idx][i];
        if (real_map[pivot][v]) continue;
        for(int j=0;j<all_idx;j++) all[idx+1][j]=all[idx][j];
        all[idx+1][all_idx]=v;
        int tidx1=0,tidx2=0;
        for(int j=0;j<some_idx;j++)if (real_map[v][some[idx][j]]) some[idx+1][tidx1++]=some[idx][j];
        for(int j=0;j<none_idx;j++)if (real_map[v][none[idx][j]]) none[idx+1][tidx2++]=none[idx][j];
 
        BronKerbosch(idx+1,all_idx+1,tidx1,tidx2);
        if (flag)return;
        none[idx][none_idx++]=v;
        some[idx][i]=0;
     }
}
void init()
{
    flag=ans=0;
    memset(real_map,0,sizeof real_map);
} 
int  main()
{ 
//    freopen("a.in","r",stdin);
//   freopen("a.out2","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        int a,b;
         for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            real_map[a][b]=real_map[b][a]=1;
        }
        for(int i=0; i<n; i++)
            some[0][i]=i+1;
 
        BronKerbosch(0,0,n,0);
 
        if (flag) printf("Too many maximal sets of friends.\n");
        else
            printf("%d\n",ans);
    } 
    return 0;
} 
