/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 30 Apr 2020 01:54:29 PM CST
* problem:  online_judge-_id 
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

/* ======= 全局变量 END =======*/
int a[100];
bool check(){
    stack<int> st;
    int i;
    for( i = 1;i<=n;i++){
        if( a[i] == 1)
            st.push(1);
        else if( !st.empty())
            st.pop();
        else return 0;
    }
    return 1;
}
int cnt=0;
void init(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n/2;++i){
        a[i] = 1;
    }
    for(i=n/2+1;i<=n;++i){
        a[i] = 2;
    }
    do {
        if( check()){
            cnt++;
            for(i=1;i<=n;++i)
                printf("%c",a[i] == 1 ?'(' : ')');
            printf("\n");
        }
    }while( next_permutation(a+1, a+1+n));
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    printf("%d\n",cnt);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
