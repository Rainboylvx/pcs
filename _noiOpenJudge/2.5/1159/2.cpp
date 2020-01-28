#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int door[10][10][1000],key[100][100],num[10],num2[10];
int u[5]={0,1,0,-1,0};
int v[5]={0,0,1,0,-1};
int n,m,sx,sy,ex,ey;
int x[10000],y[10000],tot[6];
bool map[100][100],used[100][100],flag,bo;
void bfs()
{
    int tt=0,ww=1;
    x[1]=sx;
    y[1]=sy;
    while(tt<ww)
    {
        tt++;
        for(int i=1;i<=4;i++)//四个方向 
        {
            int xx=x[tt]+u[i];
            int yy=y[tt]+v[i];
            if(xx==ex&&yy==ey)
            {
                bo=1;//搜到终点 
                return ;
            }
            if(xx>0&&xx<=n&&yy>0&&yy<=m&&map[xx][yy]&&!used[xx][yy])//如果能走 
            {
                ww++;
                x[ww]=xx;
                y[ww]=yy;
                used[xx][yy]=1;
                if(key[xx][yy]!=0)//搜到钥匙 
                {
                    num2[key[xx][yy]]++;
                    key[xx][yy]=0;
                    flag=1;
                }
            }
        }
    }
}
int main()
{
    while(true)
    {
        bo=0;
        memset(num,0,sizeof(num));
        memset(num2,0,sizeof(num2));
        memset(tot,0,sizeof(tot));
        memset(key,0,sizeof(key));
        memset(door,0,sizeof(door));//多组数据，每次都要初始化 
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;//退出循环 
        for(int i=1;i<=n;i++)//恶心的存图，其实完全可以直接用字符操作OTZ 
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='S')
                {
                    map[i][j]=1;
                    sx=i;
                    sy=j;
                }
                else if(c=='G')
                {
                    map[i][j]=1;
                    ex=i;
                    ey=j;
                }
                else if(c=='.') map[i][j]=1;
                else if(c=='X') map[i][j]=0;
                else if(c=='A')
                {
                    map[i][j]=0;
                    tot[1]++;
                    door[1][1][tot[1]]=i;//这里tot数组保存的是第一种门的数量 
                    door[1][2][tot[1]]=j;//这两个是存的第一种门的坐标 
                }
                else if(c=='B')
                {
                    map[i][j]=0;
                    tot[2]++;
                    door[2][1][tot[2]]=i;
                    door[2][2][tot[2]]=j;//同上
                }
                else if(c=='C')
                {
                    map[i][j]=0;
                    tot[3]++;
                    door[3][1][tot[3]]=i;
                    door[3][2][tot[3]]=j;//同上
                }
                else if(c=='D')
                {
                    map[i][j]=0;
                    tot[4]++;
                    door[4][1][tot[4]]=i;
                    door[4][2][tot[4]]=j;//同上
                }
                else if(c=='E')
                {
                    map[i][j]=0;
                    tot[5]++;
                    door[5][1][tot[5]]=i;
                    door[5][2][tot[5]]=j;//同上
                }
                else if(c=='a')
                {
                    map[i][j]=1;
                    key[i][j]=1;//第一种钥匙坐标 
                    num[1]++;//第一种钥匙数量 
                }
                else if(c=='b')
                {
                    map[i][j]=1;
                    key[i][j]=2;
                    num[2]++;//同上
                }
                else if(c=='c')
                {
                    map[i][j]=1;
                    key[i][j]=3;
                    num[3]++;//同上
                }
                else if(c=='d')
                {
                    map[i][j]=1;
                    key[i][j]=4;
                    num[4]++;//同上
                }
                else if(c=='e')
                {
                    map[i][j]=1;
                    key[i][j]=5;
                    num[5]++;//同上
                }
            }
        /*for(int i=1;i<=5;i++)
            printf("%d ",num[i]);
        printf("\n");*/
        memset(used,0,sizeof(used));
        bfs();
        if(bo)
        {
            printf("YES\n");
            continue;//搜到终点直接输出YES 
        }
        while(flag)
        {
            flag=0;//判断一下是否有新的钥匙加入 
            for(int i=1;i<=5;i++)
            {
            //  printf("%d %d>\n",num[i],num2[i]);
                if(num[i]==num2[i]&&num[i]!=0)
                {
                    for(int j=1;j<=tot[i];j++)
                        map[door[i][1][j]][door[i][2][j]]=1;//把能打开的门都打开 
                    num2[i]=0;
                }
            }
            memset(used,0,sizeof(used));//初始化 
            bfs();//bfs直到搜到终点或没有新的钥匙就退出循环
        //  printf("\n");
            if(bo)
            {
                printf("YES\n");
                break;
            }
        }
        if(!bo) printf("NO\n");
    }
    return 0;
}
