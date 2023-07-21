/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 05日 星期三 08:52:30 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

long long n,m;
/* 定义全局变量 */

void init()
{
    cin >> n >> m;
}
long long a[maxn];
long long a_idx = 0;
void clear_a() {
    a_idx = 0;
}

void push_a(long long v) {
    a[++a_idx] = v;
}

//树状数组 binary index tree -> BIT

namespace binary_index_tree {
    long long lowbit(long long a) { return a & -a; } //每个元素的管辖范围
    inline long long fa(long long a) { return  a + lowbit(a);} //求a的父亲的坐标
    inline long long left(long long a) { return a - lowbit(a);} //a管辖范围左边的相邻的点

template<
template<typename,std::size_t> class Child,
typename T=long long,std::size_t N = maxn>
struct bi_tree_base {

    using child = Child<T, N>;

    long long a[N]; //存数据

    T query(long long r) {
    }

    //查询区间[l,r]的信息
    T query(long long l,long long r) {

    }

    //更新pos的位置信息
    void update(long long pos);
};


//求区间和

template<typename T=long long,std::size_t N = maxn>
struct bit_range_sum 
{

    long long a[N]; //存数据

    //清空
    void clear() { memset(a,0,sizeof(a)); }

    //求[1,r]的区间和
    T query(long long r) {
        T sum = 0;
        while( r >=1) {
            sum += a[r];
            r = left(r);
        }
        return sum;
    }

    //查询区间[l,r]的信息
    T query(long long l,long long r) {
        return query(r) - query(l-1);
    }

    //更新pos的位置信息
    void update(long long pos,long long add) {
        while( pos <= N) {
            a[pos] += add;
            pos = fa(pos);
        }
    }
    
};

//逆序对
//可能需要离散化之后
//原理 : 需要知道 比a大的数有几个
// total - query(a) = 总数量 - <=a的数量
template<typename T=long long,std::size_t N = maxn>
struct reverse_order_pair : 
    public bit_range_sum <T,N>
{
    using bit_range_sum<T,N>::update;
    using bit_range_sum<T,N>::query;
    
    long long cnt=0; //记录存进来的数的数量

    long long size() const { return cnt; }

    //push 一个元素进来
    //返回这个数和前面的元素造成的逆序对的数量
    long long push(long long a) {
        update(a,1);
        ++cnt;
        return cnt - query(a);
    }

    void clear() {
        cnt = 0;
        bit_range_sum<T,N>::clear();
    }
};


} // end namespace bit_func


template<typename T=long long,std::size_t N = maxn>
using bit_range_sum  = binary_index_tree::bit_range_sum<T, N>;

template<typename T=long long,std::size_t N = maxn>
using reverse_order_pair= binary_index_tree::reverse_order_pair<T, N>;

template<std::size_t N = maxn>
struct discrete {
    long long a[maxn];
    long long idx{0};
    long long * last_unique_ptr = nullptr; //最后一个位置

    void clear() {
        idx = 0;
        last_unique_ptr = nullptr;
    }

    void push(long long v) { //增加元素
        a[++idx] = v;
    }

    long long unique_size () const {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use unique_size()");
#endif
        return last_unique_ptr - (a+1);
    }

    //对存入的值进行离散化
    void init() {
        std::sort(a+1,a+1+idx);
        last_unique_ptr= std::unique(a+1,a+1+idx);
    }


#if 0
    //对数据arr,从1到n进行离散化
    template<std::size_t size>
    void pre_work(long long arr[size],long long n) {
        pre_work(a+1, a+1+n);
    }

    template<typename Iter>
        requires std::is_same_v<typename std::iterator_traits<Iter>::value_type, long long>
    void pre_work(Iter begin ,Iter end) {
        std::sort(begin,end); //从小到大排序
        for( ; begin != end; ++begin)
            a[++idx] = *begin;
    }
#endif
    //查询x对应的值是
    long long query(long long x) {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use query(x)");
#endif
        
        //找到第一个>=x的位置
        auto pos = std::lower_bound(a+1, last_unique_ptr,x) - a;
        if( a[pos] == x)
            return pos;
        else 
            return 0; //返回0 表示没有找到
    }

    long long operator[](long long x) {
        return query(x);
    }

    long long * begin() {
        return a+1;
    }

    long long * end() {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use end()");
#endif
        return last_unique_ptr;
    }
};


reverse_order_pair<long long, maxn> ro;
discrete dis;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while ( 1 ) {
        std::cin >> n;
        if( n == 0) break;

        long long ans = 0;
        ro.clear();
        dis.clear();
        clear_a();
        for(long long i=1;i<=n;++i){
            long long t;
            std::cin >> t;
            push_a(t);
            dis.push(t);
        }
        dis.init(); // 离散
        for(long long i=1;i<=n;++i){
            long long t = dis.query(a[i]);
            ans += ro.push(t);
        }
        std::cout << ans << "\n";
    }
    int sum = 0;
    for(int i=1;i<=n;++i){
        sum + s[i];
    }
    return 0;
}
