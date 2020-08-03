#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

struct wp {
    int v,w;
};
int f[40000]; //dp yong

bool exist[100];
wp z[100];// zhu
wp zz[200] = {0}; // fu
int zp[100][3]; // zhi shi
int cnt=0,cnt2=0;
void init(){
    scanf("%d%d",&n,&m);
    int i,j;
    int v,p,q;
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&v,&p,&q);
        if(q == 0){
            exist[i] = 1;
            z[i] = {v,p*v};
        }
        else {
            ++cnt2;
            int t = ++zp[q][0];
            zp[q][t] = cnt2;
            zz[cnt2] = {v,p*v};
        }
    }
}
/* ======= 全局变量 END =======*/

int max_5( int a1, int a2, int a3, int a4, int a5 ){
    int m = a1;
    if( m < a2) m = a2;
    if( m < a3) m = a3;
    if( m < a4) m = a4;
    if( m < a5) m = a5;
    return m;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for(i=1;i<=m;++i){
        if(!exist[i]) continue;
        for(j=n;j>= z[i].v;--j){

            int t1 = f[j]; // 1
            int t2=0,t3=0,t4=0,t5=0;
            int sum_z = z[i].v;
            t2 = f[j-sum_z] + z[i].w; // 2

            int sumx = 0;
            if( zp[i][0] >=1){
                sumx = z[i].v + zz[ zp[i][1] ].v; //3
                if( j >= sumx)
                    t3 = f[j-sumx] + z[i].w + zz[ zp[i][1] ].w;
            }

            if( zp[i][0] >=2){
                sumx = z[i].v + zz[ zp[i][2] ].v; // 4
                if( j >= sumx)
                    t4 = f[j-sumx] + z[i].w + zz[ zp[i][2] ].w;
            }

            if( zp[i][0] >=2){
                sumx = z[i].v + zz[ zp[i][1] ].v+ zz[ zp[i][2] ].v; //5
                if( j >= sumx)
                    t5 = f[j-sumx] + z[i].w + zz[ zp[i][1] ].w+ zz[ zp[i][2] ].w;
            }

            f[j] = max_5(t1,t2,t3,t4,t5);

        }
    }
    printf("%d\n",f[n]);


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
