/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 18日 星期日 07:53:38 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

void init()
{
    cin >> n >> m;
}

//测试拆环成链

struct edge {
    int u,v,w;
};

//编号从1开始
struct links {
    edge a[maxn];
    int idx = 0;
    
    //第一条边加两次,方便每一次都取v点
    void push(const edge & e) {
        if( idx == 0) {
            a[0].v = e.u;
            a[0].w = 0;
        }
        a[++idx] = e;
    }

    //得到第i个点的编号
    int get(int i) {
        return a[resp(i)].v;
    }

    //得到第i个点对应的长度值
    int getw(int i) {
        return a[resp(i)].w;
    }
    int resp(int i) const {
        if( i > idx+1)
            i-=idx;
        return i-1;
    }
    int size() const {
        return idx*2;
    }
} _link;
// 成链之后
// 2->3 之间的距离
// pre(3) - pre(2)
// 也就是1-3的距离和 1-2的距离和

//前缀和,编号从1开始
struct pre_sum {
    int a[maxn];
    int idx=0;

    void push(int v) {
        ++idx;
        a[idx] = v + a[idx-1];
    }

    //[i,j] 的区间和
    int range(int i,int j) {
        return a[j] - a[i-1];
    }

    int size() {
        return idx;
    }

} pre;

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // edge e{1,2,1};


    _link.push({1,2,1});
    _link.push({2,3,2});
    _link.push({3,1,3});

    for(int i = 1;i<= _link.size();i++) {
        printf("i= %d,u = %d,w = %d\n",i,_link.get(i),_link.getw(i));
        pre.push(_link.getw(i));
    }
    // cout << " sum(5,2): " << pre.range(2+1, 3) << endl;
    for(int i=1;i<=_link.size();++i){
        for(int j=1;j<=i;++j){
            printf("sum(%d,%d) = %d\n",j,i,pre.range(j+1,i));
        }
    }
    return 0;
}
