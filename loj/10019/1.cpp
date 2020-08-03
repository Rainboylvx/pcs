/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 23 Feb 2020 11:32:03 AM CST
* problem: loj-10019
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
int minV[50]; //上面m层的最小体积
int minS[50];

/* ======= 全局变量 END =======*/


int ans = 0x7f7f7f7f;
// dep 深度 
// preH,preR 前一层蛋糕的高度,半径
// N 剩余得体积
// s 加起来得s值
void dfs(int dep,int preH,int preR,int N,int s){
    if( dep == m+1){ //边界
        if( N == 0)
            if( s < ans ) ans = s;
        return;
    }



    int i,j;
    int maxR,maxH;
    int maxV = N - minV[m-dep]; //这一层的最大体积
    int t = m+1-dep;
    maxR = min(preR-1,(int)sqrt(maxV/(m+1-dep))); //剪枝1:上下界剪枝
    maxH = min(preH-1,maxV/(t*t));
    Rof(i,maxR,m+1-dep){  //枚举半径 ,注意倒序
        Rof(j,maxH,m+1-dep){ //枚举高度
            if( i*i*j > maxV) continue;
            int ts = 0;
            ts += 2*i*j; //侧面积
            if( dep == 1)
                ts += i*i;
            int left = N-i*i*j;
            if(left < minV[m-dep] ) continue; // 2
            if( s+ts+minS[m-dep] > ans) continue;
            if( 2*left / i + s+ts >= ans ) continue; //4
            dfs(dep+1,j,i,left,s+ts);
        }
    }
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,m){
        minV[i] = minV[i-1] + i*i*i;
        minS[i] = minS[i-1] + 2*i*i;
    }
    int maxV = n - minV[m-1];
    int maxR = maxV / m;
    int maxH = maxV / (m*m);
    dfs(1, maxH+1, maxR+1, n, 0);
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
