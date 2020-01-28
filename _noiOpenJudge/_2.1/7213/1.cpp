#include <bits/stdc++.h>
using namespace std;

int d,n;
int m[1200][1200];
int m_ans[1200][1200];

bool in_map(int x,int y){
    if( x >=0 && x <=1024 && y >=0 && y <=1024)
        return 1;
    return 0;
}

int check(int x,int y){
    int sx = x -d;
    int sy = y -d;
    int ex = x+d;
    int ey = y+d;
    int i,j;
    int sum=0;
    for(i=sx;i<=ex;i++){
        for(j=sy;j<=ey;j++){
            if( in_map(i, j))
                sum+=m[i][j];
        }
    }
    return sum;
}

void init(){
    scanf("%d%d",&d,&n);
    int i;
    for(i=1;i<=n;i++){
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        m[t1][t2] = t3;
    }
}

int main(){
    init();
    int ans = 0;
    int i,j;
    for(i=0;i<=1024;i++){
        for(j=0;j<=1024;j++){
            int t = check(i, j) ;
            ans = max( ans,t);
            m_ans[i][j] = t;
        }
    }
    int cnt=0;
    for(i=0;i<=1024;i++){
        for(j=0;j<=1024;j++){
            if( m_ans[i][j] == ans)
                cnt++;
        }
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}
