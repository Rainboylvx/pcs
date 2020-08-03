/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 26日 星期日 12:58:27 CST
* problem:  uva-446
*----------------*/
#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int n;
struct _s {
    int a,b,c;

    bool operator<(const _s &s2){
        if(a < s2.a)
            return 1;
        else if( a == s2.a)
            return b < s2.b;
        return 0;
    }
};

int f[3000];

vector<_s> s;

void init(){
    memset(f,0,sizeof(f));
    s.clear();
    int i,j;
    int a,b,c;
    for (i=1;i<=n;i++){
        scanf("%d%d%d",&a,&b,&c);
        s.push_back({min(c,b),max(c,b),a});
        s.push_back({min(a,c),max(a,c),b});
        s.push_back({min(a,b),max(a,b),c});
    }
    sort(s.begin(),s.end());
}

void dp(){

         int size = s.size()-1;
         int i,j;
         int _max = -1;
         for(i=size;i>=0;i--){
             f[i] = s[i].c;
             int t = 0;
             int a1 = s[i].a;
             int b1 = s[i].b;
             for (j=size;j>i;j--){
                 int a2 = s[j].a;
                 int b2 = s[j].b;
                 if( a1 < a2 && b1 < b2){
                      t = max(t,f[j]);
                 }
                 else if( a1 < b2 && b1 < a2){
                      t = max(t,f[j]);
                 }
             }
             f[i] += t;
             _max = max(_max,f[i]);
         }
         printf("Case %d: maximum height = %d\n",++cnt,_max);
}

int main(){
    while(1){
        scanf("%d",&n);
        if( n == 0)
            return 0;
        init();
/*
 *        printf("============\n");
 *        for( auto i : s){
 *            cout << i.a <<"   " << i.b << endl;
 *        }
 *        int size = s.size()-1;
 *        int i,j;
 *        for(i=size;i>=0;i--){
 *            int a1 = s[i].a;
 *            int b1 = s[i].b;
 *            for (j=size;j>i;j--){
 *                int a2 = s[j].a;
 *                int b2 = s[j].b;
 *                if( a2 < a1 && b2 < b1){
 *                    printf("yes\n");
 *                }
 *                else if( a2 < b1 && b2 < a1){
 *                    printf("yes\n");
 *            }
 *        }
 *
 *        printf("============\n");
 */
        dp();
    }
    return 0;
}
