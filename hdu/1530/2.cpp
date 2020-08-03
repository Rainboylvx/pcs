#include<stdio.h>

#define N 60

int map[N][N];
int dp[N] ,now[N];
int n ,Ans;

void DFS(int x ,int sum)
{
    if(sum > Ans) Ans = sum;

    int able = 0;
    int tnow[N];
    for(int i = x + 1 ;i <= n ;i ++)
    {
        tnow[i] = now[i];
        if(now[i]) able ++;
    }
    if(able + sum <= Ans) return;

    for(int i = x + 1 ;i <= n ;i ++)
    {
        if(!tnow[i]) continue; // 不相连
        if(dp[i] + sum <= Ans) continue;
        for(int j = i + 1 ;j <= n ;j ++)
            now[j] = tnow[j] & map[i][j];
        DFS(i ,sum + 1);
    }
}

int Max_Tuan()
{
    Ans = dp[n] = 1; //下界
    for(int i = n - 1 ;i >= 1 ;i --)
    {
        for(int j = 1 ;j <= n ;j ++)
            now[j] = map[i][j];
        DFS(i ,1);
        dp[i] = Ans; // ?
    }
    return Ans;
}

int main ()
{
    int i ,j;
    while(~scanf("%d" ,&n) && n)
    {
        for(i = 1 ;i <= n ;i ++) 
            for(j = 1 ;j <= n ;j ++)
                scanf("%d" ,&map[i][j]); //读取图
        printf("%d\n" ,Max_Tuan());
    }
    return 0;
}
