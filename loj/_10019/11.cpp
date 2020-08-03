/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 12日 星期四 08:31:51 CST
* problem:  loj-10019
*----------------*/
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
int n,m; // 体积,层数
int ans = 0x3f3f3f3f ; //  记录最小的s

void init(){
    scanf("%d%d",&n,&m);
}
/* ======= 全局变量 END =======*/
int r[30];
int h[30];

//剩余最小可能面积
int min_lft_s(int dep,int r,int h){
    if( dep == m) return 0;
    int i, sum = 0;
    for( i = 1;i<=m-dep;i++){
        sum += 2*(r+i)*(h+i);
    }
    sum += (r+i)*(r+i);
    return sum;
}

int min_lft_v(int dep,int r,int h){
    if( dep == m) return 0;
    int i, sum = 0;
    for( i = 1;i<=m-dep;i++){
        sum += (r+i)*(r+i)*(h+i);
    }
    return sum;
}


// 深度,上一层的r,h ,已经得到的v,s
void dfs(int dep,int pr,int ph,int v,int s){
    if( dep == m+1 ){ // 边界最后一层
        int real_s = s + pr*pr;
        if(v == n &&  real_s< ans) {
            //int i;
            //for(i=1;i<=m;i++){
                //printf("%d ",r[i]);
            //}
            //printf("\n");
            //for(i=1;i<=m;i++){
                //printf("%d ",h[i]);
            //}
            //printf("v:\n");
            //for(i=1;i<=m;i++){
                //printf("%d ",r[i]*r[i]*h[i]);
            //}
            //printf("\n=====\n");
            ans= real_s;
        }
        return ;
    }

    int i,j;
    int rmax = sqrt((n-v)/(ph+1));
    int hmax = (n-v)/((pr+1)*(pr+1));
    for(i = pr+1 ;i <= rmax ;i++){
    //for(i = rmax ;i >= pr+1;i--){
        for( j = ph+1;j<=hmax;j++){
        //for( j = hmax;j>=ph+1;j--){
            if( s + 2*(m-dep)*i*j+i*i > ans) continue;
            if( v + (m-dep)*i*i*j < n){ // 可行性剪枝

                int now_v = v+ i*i*j;
                int now_s = s+2*i*j;
                //if( now_v + min_lft_v(dep, i, j) > n) continue;
                //if( now_s + min_lft_s(dep, i, j) >= ans) continue;

                r[dep] = i;
                h[dep] = j;
                dfs(dep+1, i, j, now_v, now_s);
            }
        }
    }

}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dfs(1,0,0,0,0);
    if( ans == 0x3f3f3f3f)
        printf("0\n");
    else printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
