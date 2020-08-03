#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5+5;
int n;

struct node {
    int t,v; // if v == -1 表示被用过
}a[maxn]; //存youhui卷
int cnt;


int find(int v,int t){
    int i,idx;
    int max_t = 0x7f7f7f7f; //我记录的找到的票的最小时间
    for( i =1;i<=cnt;i++){
        if( a[i].v == -1) continue;
        if( t-a[i].t <= 45 && v <= a[i].v){
            if( max_t > a[i].t){
                max_t = a[i].t;
                idx = i;
            }
        }
    }
    if( max_t == 0x7f7f7f7f) return -1;
    return idx;
}

int main(){
    cin >> n;
    int i,j;
    int x,y,z;
    int spend = 0;
    for(i=1;i<=n;++i){
        cin >> x >> y >> z;
        if( x == 0){
            cnt++;
            a[cnt].t = z;
            a[cnt].v = y;
            spend += y;
        }
        else {
            int idx = find(y,z);
            if( idx == -1)
                spend+=y;
            else {
                a[idx].v = -1;
            }
        }
    }
    cout << spend;

    return 0;
}
