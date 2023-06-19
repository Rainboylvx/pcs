//测试pre_sum 与 单调队列
#include <bits/stdc++.h>
//#include "graph/linkList.hpp"
using namespace std;
const int maxn=100;

#define log(...) std::cout << #__VA_ARGS__ << __VA_ARGS__
#define logn std::cout << '\n'

struct node {
    int u,s; //u表示当前点的编号,
             //s表示前缀和
};

// i前面的第m个位置,包括i
inline int Predecessor(int i,int m) {
    return  i-m+1;
}

//前缀和,编号从1开始
struct pre_sum {
    int a[maxn];
    int idx=0;
    void init() { idx = 0;}

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
    
    int operator[](std::size_t i) const {
        return a[i];
    }

} pre;

template<typename T>
struct _que {
    T a[maxn];
    int head,tail;
    void init() {tail = head = 0;}
    int size() { return head -tail;}
    void push(T t) {
        a[tail++] = t;
    }
    bool empty() {return tail == head;}
    T & front() {return a[head];}
    T & back() {return a[tail-1];}
    void pop_back(){ tail--;}
    void pop_front() { ++head;}
};

//单调队列
struct monotonic_que {
    struct node_with_p : public node{
        int p;
    };
    _que<node_with_p> a;

    //初始化
    void init() { a.init();}

    //删除头部
    void del(int p) {
        if( a.front().p < p)
            a.pop_front();
    }
    void push(int p,int u,int s) {
        while(!a.empty() && a.back().s < s )
            a.pop_back();
        a.push({u,s,p});
    }

    auto & front()  { return a.front(); }

} mque;

int u[100] = {0,1,2,3,1,2,3};
int main(){
    // 1 2 3 4 下标
    // 1 2 1 2 点的编号
    // 0 2 1 2

    //添加了6个点
    pre.push(0);
    pre.push(1);
    pre.push(2);
    pre.push(3);
    pre.push(1);
    pre.push(2);

    int m = 3; //距离

    // p u s
    mque.push(0,0,0);
    //遍历环上的
    for(int i = 1;i<=m*2;i++) {
        int pos = Predecessor(i,m);
        int now_u = u[i]; // 当前点
        
        mque.del(pos); //删除 < pos 的所有值
        int val = mque.front().s;
        int pre_u = mque.front().u; //前一个点的编号
        int pre_p = mque.front().p; //前一个点的编号
        //int dis = pre.range(pre_p+1,i); //两个点之间的距离值
        // ? 当前点的sum值是什么
        int ans = val + 0 + pre[i]; // dp[i] = 0

        log(ans);
        logn;
        mque.push(i,u[i],-pre[i]);

    }

    return 0;
}
