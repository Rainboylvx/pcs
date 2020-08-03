/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 24日 星期二 00:12:31 CST
* problem: luogu-1012
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
vector<string>   v;

void init(){
    scanf("%d",&n);
    string s;
    int i;
    For(i,1,n){
        cin >> s;
        v.push_back(s);
    }
}

/* ======= 全局变量 END =======*/
bool cmp(string s1,string s2){
    int l1 =s1.length(),l2= s2.length();
    int i,j;
    for(i= 0;i<l1 && i <l2;i++){
        if( s1[i] > s2[i])
            return 1;
        else if( s1[i] < s2[i])
            return 0;
    }
    if( l1 == l2) return 1;
    char last = l1 < l2 ? s1.back() : s2.back();
    if( l1 < l2){
        for( i = l1 ;i < l2 ;i++){
            if(last > s2[i])
                return 1;
            else if( last < s2[i])
                return 0;
        }
    }
    else {
        for( i = l2 ;i < l1 ;i++){
            if(last < s1[i])
                return 1;
            else if( last > s2[i])
                return 0;
        }
    }
    return 1;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    sort(v.begin(),v.end(),cmp);
    for (const auto& e : v) {
        cout << e;
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
