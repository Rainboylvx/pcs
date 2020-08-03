/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 18日 星期一 22:41:52 CST
* problem: loj-10116
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
/* ======== 树状数组 BIT 
 * 1.单点增减，区间和
 *    1.1 逆序对
 * 2.区间增减，单点值
 * 3.区间增减，区间和
 * 4.单点修改，末尾压入，区间最值
 * */
namespace bit {
    typedef long long ll;
    ll c[maxn],SIZE=maxn;
    ll c2[maxn]; // c2[i] = i*c[i]
    inline void bit_init(){}

    /* 区间和 */
    inline ll lowbit(ll x) { return x & -x;}
    void update(ll pos,ll add){ while(pos<=SIZE) c[pos]+=add,pos+=lowbit(pos);}
    /* 差分,区间增减,单点查询*/
    void update_range(ll l,ll r,ll add){ update(l,add);update(r+1,-add); }
    ll query(int pos){ll sum=0;while(pos>0) sum+=c[pos],pos-=lowbit(pos); return sum;}

    /* 差分,区间增减,区间查询*/
    //核心公式：sum_a[i] = (i+1)×sum_c[i] - sum_{i×c[i]}
    void update_c_c2(ll pos,ll add){ //同时更新c，c2
        ll t = pos; while( pos <= SIZE){ c[pos] += add; c2[pos] += t*add; pos+=lowbit(pos);}
    }
    void update_range_c_c2(ll l,ll r ,ll add){ update_c_c2(l, add);update_c_c2(r+1, -add); }
    ll query2(ll pos){ ll sum = 0; while( pos > 0) sum += c2[pos], pos -=lowbit(pos); return sum; }
    ll query_range_sum(ll l,ll r){ return (r+1)*query(r) - query2(r) - l*query(l-1) + query2(l-1); }

    // ===== 4.单点修改，末尾压入，区间最值
    ll a[maxn]; // 原数组
    void update_by_child(ll pos,ll v){ // alias push
        c[pos] = a[pos] = v;
        ll i,lb = lowbit(pos);
        for(i=1 ; i < lb ; i <<= 1) c[pos] = std::max(c[pos],c[pos-i]);
    }

    void update_ex(ll pos,ll v){
        update_by_child(pos,v); int tmp = c[pos];
        for( pos += lowbit(pos); pos <=SIZE; pos+=lowbit(pos)){
            if( c[pos] < tmp) c[pos] = tmp;
            else break; //没有更新父亲
        }
    }
    ll query_ex(ll l ,ll r){
        ll ex = -1;
        while( l <= r){
            ll left = r - lowbit(r) +1; //范围内的最左点
            if( left >= l) ex = std::max(ex,c[r]) , r = left-1;
            else ex = std::max(ex,a[r]),r--;
        }
        return ex;
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d",&n,&m);
    char s[10];
    using namespace bit;
    int x,y,i;
    For(i,1,m){
        scanf("%s",s);
        if( s[0] == 'A'){
            scanf("%d",&x);
            printf("%lld\n",query(x));
        }
        else if(s[0] == 'B'){
            scanf("%d%d",&x,&y);
            update(x,y);
        }
        else {
            scanf("%d%d",&x,&y);
            update(x, -y); 
        }
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
