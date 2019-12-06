/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 25日 星期六 16:50:37 CST
* problem: uva-437
*----------------*/
#include <bits/stdc++.h>
using namespace std;

int n;
struct _d {
    int l[3];
}m[50];
int f[500];

struct _so {
    int idx;
    int k;
    bool operator<(_so &s){
        int a1 = m[idx].l[(k+1)%3];
        int b1 = m[idx].l[(k+2)%3];

        int a2 = m[s.idx].l[(s.k+1)%3 ];
        int b2 = m[s.idx].l[(s.k+2)%3 ];

        if( a1 < a2 && b1 < b2)
            return 1;
        else if (a1 < b2 && b1 < b2)
            return 1;
        return 0;

    }
};
vector<_so> so;

void init(){
    so.clear();
    int i;
    for (i=1;i<=n;i++){
        scanf("%d%d%d",&m[i].l[0],&m[i].l[1],&m[i].l[2]);
        so.push_back({i,0});
        so.push_back({i,1});
        so.push_back({i,2});
    }
    /* 排序 */
    sort(so.begin(),so.end());
}

int get_val(int idx,int k){
    return m[idx].l[k%3];
}

int _max = -1;
void dp(){
    memset(f,0,sizeof(f));
    _max=-1;
    int i,j;
    int size = so.size();
    for(i = size-1;i>=0;i--){

        int t = 0;

        f[i] = get_val(so[i].idx,so[i].k);

        int a1 = get_val(so[i].idx,so[i].k+1);
        int b1 = get_val(so[i].idx,so[i].k+2);

        for(j=size-1;j>i;j--){
            
            int a2 = get_val(so[j].idx,so[j].k+1);
            int b2 = get_val(so[j].idx,so[j].k+2);
            if( a1 < a2 && b1 < b2){
                t = max(t,f[j]);
            }
            else if( a1 < b2 && b1 < a2){
                t = max(t,f[j]);
            }
        }

        f[i] +=t;
        _max = max(_max,f[i]);
    }
}



int main(){
    int cnt = 0;
    while(1){
        scanf("%d",&n);
        if( n == 0) 
            break;
        init();
        dp();
        for(auto i : so){
            printf("%d %d height= %d\n",get_val(i.idx,i.k+1),get_val(i.idx,i.k+2),get_val(i.idx,i.k));
        }
        int size = so.size() -1;
        int i,j;
        for(i=size;i>0;i--){

            int a1 = get_val(so[i].idx,so[i].k+1);
            int b1 = get_val(so[i].idx,so[i].k+2);
            for(j=size;j>i;j--){

                int a2 = get_val(so[j].idx,so[j].k+1);
                int b2 = get_val(so[j].idx,so[j].k+2);
                if( a2 < a1 && b2 < b1){
                    printf("yes %d %d\n",i,j);
                    printf("=>%d %d\n",a1,b1);
                    printf("=>%d %d\n",a2,b2);
                }
                else if( a2 < b1 && b2 < a1)
                    printf("yes\n");

            }
        }
        printf("Case %d: maximum height = %d\n",++cnt,_max);
    }
    return 0;
}
