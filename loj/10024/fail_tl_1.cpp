
/*
 *直接暴搜+简单搜索
 *
 *
 *当前已经选择的数的和 Sum+ 1 <= n 可性性剪枝/估价函数 开头结尾不能是0,结尾不能是2,4,6,只能是奇数
 *
 *一行 一列 完, 判定和 与 是不是素数
 *五位的素数 都是个位数
 */
/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 13日 星期五 08:38:20 CST
* problem:  loj-10024
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

int mp[10][10];
int m1_sum[10][10]; // 记录行的前缀和
int m2_sum[10][10]; // 记录列的前缀和
vector<int> v;


#define pre_h(i,j) m1_sum[i][j-1]
#define pre_l(i,j) m2_sum[i-1][j]

/* 5个数组成的5位数 */
inline int five_he(int a,int b,int c,int d,int e){
    return a*10000 + b*1000 + c*100 + d*10 + e;
}

inline int lie_sum(int x,int y){
    return mp[1][y]*10000+ mp[2][y]*1000+ mp[3][y]*100+ mp[4][y]*10;
}
inline int hang_sum(int x,int y){
    return mp[x][1]*10000 + mp[x][2]*1000 + mp[x][3]*100 + mp[x][4]*10 ;
}

bool b[100000]; //筛法选素数

void shai(){ int i,j; For(i,2,100000){ if( !b[i] ) For(j,2,100000/i){ b[i*j] = 1; } } }

inline bool isprime(int x){ return !b[x]; }

void init(){
    shai();
    scanf("%d%d",&n,&m);
    mp[1][1] = m;
    m1_sum[1][1] = m2_sum[1][1] = m;
}

int chai_tmp[10];
int chai(int n){
    int cnt = 5,sum=0;
    while(n >0){
        int g = n % 10;
        chai_tmp[cnt--]= g;
        sum += g;
        n /= 10;
    }
    return sum;
}

bool chai_no_0(int n){
    int cnt = 5;
    while(n >0){
        int g = n % 10;
        if(!g) return 0;
        n /= 10;
    }
    return 1;
}

void p_mp(){ int i,j; For(i,1,5){ For(j,1,5){ printf("%d",mp[i][j]); } printf("\n"); } printf("\n"); }

bool all_check(){
    int i,j;
    For(i,1,5){
        int s1=0,s2=0;
        for(j=1;j<=5;++j){
            s1 += mp[i][j];
            s2 = s2 *10 + mp[i][j];
        }
        if( s1 != n || b[s2]) return 0;
    }
    For(j,1,5){
        int s1=0,s2=0;
        For(i,1,5){
            s1 += mp[i][j];
            s2 = s2 *10 + mp[i][j];
        }
        if( s1 != n || b[s2]) return 0;
    }
    int s1 = mp[1][1] + mp[2][2] + mp[3][3] + mp[4][4] + mp[5][5] ;
    int s2 = mp[1][1] *10000+ mp[2][2] *1000+ mp[3][3] *100+ mp[4][4] *10+ mp[5][5] ;
    if( s1 != n || b[s2]) return 0;

    s1 = mp[5][1] + mp[4][2] + mp[3][3] + mp[2][4] + mp[1][5] ;
    s2 = mp[5][1] *10000+ mp[4][2] *1000+ mp[3][3] *100+ mp[2][4] *10+ mp[1][5] ;
    if( s1 != n || b[s2]) return 0;
    return 1;
}

void dfs(int x,int y){
    if( x == 6){ //边界
        p_mp();
        return;
    }
    
    if( x == 5 || y == 5){ // 到达边界,不选,算出值
        if( x == 5){
            int t = n - pre_l(x, y);
            if( t < 0|| t>9 || t % 2 == 0) return;
            if( b[lie_sum(x, y)+t ]) return;
            mp[x][y] = t;
            m1_sum[x][y] = pre_h(x, y)+t;
            m2_sum[x][y] = pre_l(x, y)+t;
        }
        if( y == 5){
            int t = n - pre_h(x, y);
            if( t < 0|| t>9 || t % 2 == 0) return;
            if( b[hang_sum(x, y)+t ]) return;
            mp[x][y] = t;
            m1_sum[x][y] = pre_h(x, y)+t;
            m2_sum[x][y] = pre_l(x, y)+t;
        }
        if( x == 5 && y == 5){ //最后一个点
            int sum  = mp[1][1] *10000+ mp[2][2] *1000+ mp[3][3] *100+ mp[4][4] *10+ mp[5][5] ;
            if( b[sum] ) return;
            sum  = mp[1][1] + mp[2][2] + mp[3][3] + mp[4][4] + mp[5][5] ;
            if( sum != n) return;
        }
        dfs( y+1 >5 ? x+1 : x , y+1 > 5 ?1 : y+1);
        mp[x][y] = 0;
        return;
    }

    int start = ( x==1 || y == 1) ? 1 : 0;
    int i;

    For(i,start,9){
        if( pre_l(x,y)+1 > n) return; //剪枝
        if( pre_h(x,y)+1 > n) return;
        if( y == 4){ //边界检查
            int t = n - pre_h(x,y)-i;
            if( t < 0 || t >9 || t % 2 == 0) continue;
            int sum = five_he(mp[x][1], mp[x][2], mp[x][3],i,t);
            if(b[sum]) continue;
        }

        if(x == 4){
            int t = n - pre_l(x,y)-i;
            if( t < 0 || t >9 || t % 2 == 0) continue;
            int sum = five_he(mp[1][y], mp[2][y], mp[3][y],i,t);
            if(b[sum]) continue;
        }

        if( x == 4 && y == 2){
            int t = n - pre_l(5,1);
            if( t <0|| t>9 || t % 2 ==0 ) return;
            int s1 = t+i+mp[3][3] + mp[2][4]+mp[1][5];
            if( s1 != n) continue;
            s1 = t*10000+i*1000+mp[3][3]*100 + mp[2][4]*10+mp[1][5];
            if( b[s1]) continue;
        }
        if( x == 4 && y == 4){
            int t = n - ( mp[1][1]+ mp[2][2]+ mp[3][3]+ i);
            if( t <0|| t>9 || t % 2 ==0 ) return;
            if( t + 4*n - pre_l(5,1)-pre_l(5,2)-pre_l(5,3) - (pre_l(4,4) +i) != n) continue;
            if( t+ mp[1][5]+mp[2][5]+mp[3][5]+ ( n-pre_h(4, 4)-i)!=n ) continue;
            int sum = five_he( mp[1][1], mp[2][2], mp[3][3], i,t);
            if( b[sum]) continue;
        }
        mp[x][y] = i;
        m1_sum[x][y] = pre_h(x, y)+i;
        m2_sum[x][y] = pre_l(x, y)+i;
        dfs( y+1 >5 ? x+1 : x , y+1 > 5 ?1 : y+1);
        mp[x][y] = 0;
    }

}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j,k;
    For(i,m*10000,m*10000+9999){
        if( !b[i] && chai_no_0(i) && chai(i) == n){
            v.push_back(i);
            //printf("%d ",i);
        }
    }

        //printf("\n");
    int len = v.size();
    printf("%d\n",len);
    for (i=0;i<len;i++) {
        chai(v[i]);
        memcpy(mp[1],chai_tmp,sizeof(int)*8);
        For(k,1,5){
            m1_sum[1][k] = m1_sum[1][k-1] + mp[1][k];
            m2_sum[1][k] = mp[1][k];
        }
        //for (j=i+1;j<len;j++) {
            ////printf("%d %d\n",i,j);
            //chai(v[j]);
            //mp[2][1]=chai_tmp[2];
            //mp[3][1]=chai_tmp[3];
            //mp[4][1]=chai_tmp[4];
            //mp[5][1]=chai_tmp[5];
            //For(k,2,5){
                //m1_sum[k][1] = mp[k][1];
                //m2_sum[k][1] = m2_sum[k-1][1]+ mp[k][1];
            //}
            //dfs(2,2);
        //}
        dfs(2,1);
    }

    //dfs(1,2);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
