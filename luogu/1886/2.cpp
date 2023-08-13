/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 31日 星期一 15:57:16 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int a[maxn];
/* 定义全局变量 */
bool query_max;


//检查 i 位置是否比j位置 优秀
bool is_better(int i,int j) {
    if( query_max )
        return a[i] > a[j];
    return a[i] < a[j];
}


//创建一个单调队列
//里面存的元素的下标
struct mono_queue {
    int a[maxn];
    int head,tail;
    void clear() { head = tail = 0;}
    int  size() { return tail - head;}
    void push(int v) { a[tail++] = v;}
    void pop_front() { ++head;}
    void pop_back() { --tail;}

    bool empty() { return  head == tail;}

    int front() { return a[head];}
    int back() { return a[tail-1];}

    // 删除那些超过了范围的值
    void del(int pos) {
        while( !empty() && front() < pos)
            pop_front();
    }

    //向单调队列存一个新的值,是下标
    void push_new(int pos) {
        //先删除那些没有pos位置优秀的值
        while( !empty() && is_better(back(),pos) == false)
            pop_back();
        push(pos);
    }
};

mono_queue myq; //求最大值的


int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    std::cin >> n;
    std::cin >> m;

    for(int i=1;i<=n;++i){
        std::cin >> a[i];
    }

    query_max = false;
    for(int i=1;i<=m-1;++i){
        myq.push_new(i);
    }

    for(int i =m ;i <=n ;i ++) {
        myq.push_new(i);
        myq.del(i-m+1);
        cout << a[myq.front()] << " ";
    }
    cout << endl;
    myq.clear();
    query_max = true;
    for(int i=1;i<=m-1;++i){
        myq.push_new(i);
    }

    for(int i =m ;i <=n ;i ++) {
        myq.push_new(i);
        myq.del(i-m+1);
        cout << a[myq.front()] << " ";
    }
    
    return 0;
}
