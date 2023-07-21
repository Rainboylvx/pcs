/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-18 20:47:18
*----------------*/
#define __maxn__ 3e5
#define __maxe__ 6e5
#include <bits/stdc++.h>
#include <cassert>
#ifndef __HEADER_BASE_HPP__
#define __HEADER_BASE_HPP__
#include <cstddef> // for std::size_t
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <string_view>
#include <functional>
#include <memory_resource>
#ifdef __cpp_lib_ranges
#include <ranges>
#endif
#ifdef __cpp_concepts
#include <concepts>
#endif
using std::literals::string_view_literals::operator""sv;
#define __M_concat_II(a,b) a##b
#define __M_concat_I(a,b) __M_concat_II(#a,b)
#define __M_concat_sv(a) __M_concat_I(a,sv)
constexpr int _sexp_to_number(std::string_view _sv){
    int num = 0,e = 0,i=0;
    while( i < _sv.length() && _sv[i] !='e')
        num = num*10 + _sv[i] - '0',++i;
    ++i;
    while( i < _sv.length() )
        e = e*10 + _sv[i]-'0',++i;
    while(e--) num = num*10;
    return num+5;
}
#ifdef __maxn__
const int maxn = _sexp_to_number(__M_concat_sv(__maxn__));
#elif not defined (maxn)
const int maxn = 1000007;
#endif
#ifdef __maxe__
const int maxe = _sexp_to_number(__M_concat_sv(__maxe__));
#elif not defined (maxe)
const int maxe = 1000007;
#endif
#ifndef FOR
#define FOR(i, range) \
    for (auto i : range)
#else
    static_assert(0,"Macro FOR already defined!");
#endif
#ifndef  __FAST_OUT_
#define  __FAST_OUT_
constexpr int io_buff_size = 1<<21;
struct fast_io_base {
    char buff[io_buff_size];
    char * ps,*pt; // start ,end 指针
    fast_io_base()
        :ps(buff),pt(buff)
    {}
    bool empty() const { return ps == pt;}
};
struct fast_in :public fast_io_base  {
    void fill_buffer() {
        ps = pt = buff;
        pt += fread(buff, sizeof(char), sizeof(buff), stdin);
    }
    char getc () {
        if( empty() ) fill_buffer();
        if( empty() ) return EOF;
        return *ps++;
    }
    void read() {}
    template<typename T,typename ...Args>
#ifdef __cpp_concepts
    requires 
    std::conjunction_v<std::is_integral<T>,std::is_integral<Args>...>
#endif
    void read(T & n,Args&... args) {
        n = 0;
        bool neg_flag = 0;
        char ch = getc();
        while(ch < '0' || '9' < ch ) {
            if( ch == '-') neg_flag = 1;
            ch = getc();
        }
        while( '0' <= ch && ch <='9') {
            n = n*10 + ch -'0';
            ch=getc();
        }
        n = neg_flag ? -n : n;
        read(args...);
    }
    template<typename T>
#ifdef __cpp_concepts
    requires std::integral<T>
#endif
    fast_in & operator>>(T & n) {
        read(n);
        return *this;
    }
    template<typename... T>
    void operator()(T&... args){
        read(args...);
    }
};
struct fast_out : public fast_io_base {
    using fast_io_base::buff;
    using fast_io_base::pt;
    using fast_io_base::ps;
    int num[65];
    fast_out()
        :fast_io_base()
    {
        pt = buff+sizeof(buff);
    }
    ~fast_out() {
        flush();
    }
    inline void flush() {
        if( ps == buff) return;
        fwrite(buff, 1, ps-buff, stdout);
        ps = buff;
    }
    inline void putc(char c) {
        *ps++ = c;
        if(empty()) { //empty() 在这里表示可写空间
            flush();
        }
    }
    template<char sep=' '>
    inline void print() {}
    template<char sep=' '>
    inline void println() {}
    template<typename T>
        requires std::is_integral_v<std::remove_cvref_t<T>>
    void print_one(T n) {
        int idx = 0;
        if( n < 0)
            putc('-'),n = -n;
        do {
            num[++idx]  = n % 10 + '0';
        }while(n /= 10);
        do {
            putc(num[idx]);
        }while(--idx);
    }
    template<typename T>
        requires std::is_same_v<T,char>
    void print_one(T n) {
        putc(n);
    }
    template<char sep=' ',typename... T>
    void print_one(const std::tuple<T...> & tup) {
        [&]<std::size_t... I>(std::index_sequence<I...>){
            print<sep>(std::get<I>(tup)...);
        }(std::make_index_sequence<sizeof...(T)> {});
    }
    template<typename Iter>
        requires requires(Iter it) {
            {*it};   // it can be dereferenced.
            {++it};  // it can be incremented.
        }
    void print(Iter begin,Iter end) {
        for( auto i = begin ; i != end ;++i){
            print_one(*i);
            putc(' ');
        }
    }
    template<typename Range>
        requires requires (Range r) {
            r.begin();
            r.end();
        }
    void print(Range&& r) {
        print<' '>(r.begin(),r.end());
    }
    template<typename Range>
        requires requires (Range r) {
            r.begin();
            r.end();
        }
    void println(Range&& r) {
        println(r.begin(),r.end());
    }
    template<char sep = ' ',typename Iter>
        requires requires(Iter it) {
            {*it};   // it can be dereferenced.
            {++it};  // it can be incremented.
        }
    void println(Iter begin,Iter end) {
        for( auto i = begin ; i != end ;++i){
            print_one<sep>(*i);
            ln();
        }
    }
    template<char sep = ' ',typename T,typename ...Args>
    void print(T&& n,Args&&... args) {
        print_one(std::forward<T>(n));
            putc(sep);
        print<sep>(std::forward<Args>(args)...);
    }
    template<char sep = ' ',typename T,typename ...Args>
    void println(T&& n,Args&&... args) {
        print_one(std::forward<T>(n));
        if constexpr (sizeof...(args)!= 0)
            putc(sep);
        else
            ln(); //换行
        println<sep>(std::forward<Args>(args)...);
    }
    template<typename ...Args>
    fast_out & operator()(Args&&... args)
    {
        print(std::forward<Args>(args)...);
        return *this;
    }
    inline fast_out & ln() {
        putc('\n');
        return *this;
    }
    inline fast_out & sp() { //输出一个空格
        putc(' ');
        return *this;
    }
};
fast_out & operator<<(fast_out & out,const int & a) {
    out.print(a);
    return out;
}
template<typename T>
fast_out & operator<<(fast_out & out,T & a) {
    out.print(a);
    return out;
}
fast_in in;
fast_out out;
#endif
template<typename _leftContainer,typename _Callable,typename... _CallableArgs >
struct YankActionAdaptor;
template<typename _Callable,typename... _CallableArgs >
struct YankDataContainer {
    using tuple_type = std::tuple<_CallableArgs...>;
    _Callable _M_callable;
    std::tuple<_CallableArgs...> m_tup;
    YankDataContainer(_Callable cal,_CallableArgs&&... cargs)
        : _M_callable(cal),
        m_tup(std::forward<_CallableArgs>(cargs)...)
    {}
    YankDataContainer(_Callable cal,std::tuple<_CallableArgs...>&& tup)
        : _M_callable(cal),
        m_tup(std::move(tup))
    {}
    template<typename leftContainer>
    auto accept_leftContainer(leftContainer & lc) {
        return YankActionAdaptor
            <leftContainer&,_Callable,_CallableArgs...>
            (lc,std::move(*this));
    }
};
template<typename _leftContainer,typename _Callable,typename... _CallableArgs >
struct YankActionAdaptor {
    _leftContainer  _M_leftContainer;
    YankDataContainer<_Callable,_CallableArgs...> _M_calldata;
    using DataType = YankDataContainer<_Callable,_CallableArgs...>;
    YankActionAdaptor(_leftContainer&& lc,DataType&& _callable)
        :_M_leftContainer(std::forward<_leftContainer>(lc)),
        _M_calldata(std::move(_callable))
    {}
    template< typename _RightContainer >
    auto operator>>(_RightContainer & rc ) {
        return [&]<std::size_t... I>(std::index_sequence<I...>){
            return std::invoke(
                    _M_calldata._M_callable,
                    std::get<I>(_M_calldata.m_tup)...,
                    _M_leftContainer,
                    rc);
        }(std::make_index_sequence<std::tuple_size_v<typename DataType::tuple_type> >{});
    }
};
template<typename _leftContainer,typename _Callable,typename... _CallableArgs >
YankActionAdaptor(_leftContainer&&,YankDataContainer<_Callable,_CallableArgs...>)
    ->YankActionAdaptor<_leftContainer, _Callable, _CallableArgs...>;
template<typename _Callable>
struct YankAdaptor {
    _Callable _M_callable;
    YankAdaptor(const _Callable & _callable)
        :_M_callable(_callable)
    { }
    YankAdaptor(_Callable && _callable)
        : _M_callable( std::move( _callable))
    {}
    template<typename... Args>
    requires (sizeof... (Args) >=1 )
    constexpr auto
    operator()(Args&& ... args) const {
        return YankDataContainer<_Callable,
               std::remove_cv_t<Args>...
               >(_M_callable,std::forward<Args>(args)...);
    }
};
template<typename T>
struct is_YankDataContainer: public std::false_type {};
template<typename T2,typename... Args>
struct is_YankDataContainer<YankDataContainer<T2,Args... >> : public std::true_type {};
template<typename T>
struct is_YankActionAdaptor: public std::false_type {};
template<typename LC,typename _Callable,typename... _CallableArgs>
struct is_YankActionAdaptor
<YankActionAdaptor<LC,_Callable,_CallableArgs...>>
: public std::true_type {};
template<typename ContainerLeft,typename T2>
requires is_YankDataContainer<T2>::value
auto operator>>(ContainerLeft & lc,T2&& _yankData)
{
    return YankActionAdaptor(lc,std::move(_yankData));
}
template <typename T>
concept OneDimensionalArray = std::rank_v<T> == 1 && std::extent_v<T> > 0;
template <typename T>
concept TwoDimensionalArray = std::rank_v<T> == 2 && std::extent_v<T> > 0;
template <typename lc,typename rc>
concept CanYankLikeArray = requires(lc & l,rc & r)
{
    {l >> r};
};
template<typename T2>
requires is_YankDataContainer<T2>::value
auto operator>>(fast_in & lc,T2&& _yankData)
{
    return YankActionAdaptor(lc,std::move(_yankData));
}
template<typename LC,typename RC>
void default_yank_action(int i,LC & lc ,RC & rc)
{
    lc >> rc;
}
template<typename LC,typename RC>
requires OneDimensionalArray<RC>
void default_yank_action(int i,LC & lc ,RC & rc)
{
    lc >> rc[i];
}
template<typename LC,typename RC>
requires OneDimensionalArray<LC> && std::is_same_v<RC, fast_out>
void default_yank_action(int i,LC & lc ,RC & rc)
{
    rc << lc[i]; //输出这个元素
}
struct YankArray {
    int cnt;
    YankArray(int n) // 初始化循环次数
        :cnt(n)
    {}
    template<typename Lambda>
    auto operator()(Lambda&& act) const {
        return YankDataContainer(
                [count=cnt,f=std::move(act)]
                    (auto &lc,auto &rc)
                {
                    for(int i =1;i<=count;++i) {
                        if constexpr ( OneDimensionalArray<decltype(rc)>)
                            f(lc,rc[i]);
                    }
                }
        );
    }
};
template<typename LC>
auto operator>>(LC & lc ,const YankArray & ya)
{
    auto _yankData = YankDataContainer([count=ya.cnt](auto & lc,auto & rc){
                for(int i=1;i<=count;++i)
                    default_yank_action(i,lc,rc);
            });
    return _yankData.accept_leftContainer(lc);
}
#endif
struct edge {
    int v,w,next;
    operator int() { return v; }
};
struct edge_no_w {
    int v,next;
    operator int() { return v; }
};
template<typename T>
struct is_edge : public std::false_type{};
template<>
struct is_edge<edge> : public std::true_type{};
template<typename T>
struct is_edge_no_w : public std::false_type{};
template<>
struct is_edge_no_w<edge_no_w> : public std::true_type{};
fast_out & operator<<(fast_out & out ,const edge & e) {
    out.println(e.v,e.w);
    return out;
}
fast_out & operator<<(fast_out & out ,const edge_no_w & e) {
    out.println(e.v);
    return out;
}
void make_edge(edge & e,int v,int w,int next) {
    e.v = v,e.w = w,e.next = next;
}
void make_edge(edge_no_w & e,int v,int w,int next) {
    e.v = v,e.next = next;
}
struct direct_graph {}; //有向图
struct undirect_graph {}; // 无向图
template<typename GraphType,typename Edge = edge,std::size_t V_CNT=maxn,std::size_t E_CNT=maxe>
class linkList {
private:
    using type = GraphType;
    Edge e[E_CNT];
    int h[V_CNT],edge_cnt=0;
public:
    linkList(){	//构造函数
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    template<typename U>
    void for_each(int u,U func){
        for(int i = h[u] ; i !=-1;i = e[i].next)
            func(e[i].u,e[i].v,e[i].w); //u v w
    }
    inline void emplace_back(int u,int v,int w = 0) {
        make_edge(e[edge_cnt], v, w, h[u]);
        h[u] = edge_cnt++;
    }
    inline void add(int u,int v,int w=0){
        emplace_back(u,v,w);
        if constexpr (std::is_same<GraphType, undirect_graph>::value)
            emplace_back(v,u,w);
    }
    int last_edge_idx() const {return edge_cnt-1;}
    int get_edge_cnt() const { return edge_cnt;}
    int head(int u) const{ return h[u]; }
    Edge& operator[](int i){ return e[i]; }
    struct edgePoint {
        linkList * self; //指向linkList的指针
        int idx;
        edgePoint(linkList * l,int edge_idx) : self{l},idx{edge_idx} 
        {}
        bool operator!=(int a){ return idx != a;};
        edgePoint& operator++() {
            if( idx != -1) idx = self->e[idx].next;
            return *this;
        }
        Edge& operator*(){
            return self->e[idx];
        }
    };
    struct EdgeIterator {
        linkList * self; //指向linkList的指针
        int u; //哪个点周围的点
        edgePoint begin() { return {self,self->h[u]}; }
        int end(){ return -1;}
    };
    EdgeIterator edges_start_for(int u){
        return {this,u};
    }
};
template<typename T>
struct linklist_traits {};
template<typename GraphType,typename Edge,std::size_t V_CNT, std::size_t E_CNT>
struct linklist_traits<linkList<GraphType,Edge,V_CNT,E_CNT>> {
    using type = GraphType;
    static constexpr bool is_direct = std::is_same_v<GraphType, direct_graph>;
    static constexpr bool is_undirect = std::is_same_v<GraphType, undirect_graph>;
};
template<typename GraphType,typename Edge,std::size_t V_CNT, std::size_t E_CNT>
void operator>>(fast_in & in,linkList<GraphType,Edge, V_CNT, E_CNT> & e) {
    int u,v,w=0;
    if constexpr (is_edge<Edge>::value) //有向图
    {
        in.read(u,v,w);
        e.add(u,v,w);
    }
    else if constexpr (is_edge_no_w<Edge>::value)
    {
        in.read(u,v);
        e.add(u,v);
    }
}
using graph = linkList<undirect_graph,edge,maxn,maxe>;
using graph_nw = linkList<undirect_graph,edge_no_w,maxn,maxe>;
using dirgraph = linkList<direct_graph,edge,maxn,maxe>;
using dirgraph_nw = linkList<direct_graph,edge_no_w,maxn,maxe>;
namespace std {
    template <> struct tuple_size<edge> : std::integral_constant<size_t, 2> { };
    template <> struct tuple_element<0,edge> { using type = int; };
    template <> struct tuple_element<1,edge> { using type = int; };
    template <std::size_t I>
    auto get(edge const& x) {
        if      constexpr(I == 0) return x.v;
        else if constexpr(I == 1) return x.w;
    }
    template <> struct tuple_size<edge_no_w> : std::integral_constant<size_t, 1> { };
    template <> struct tuple_element<0,edge_no_w> { using type = int; };
    template <std::size_t I>
    auto get(edge_no_w const& x) {
       static_assert(I==0,"I must eq 0!");
    }
    template <>
    auto get<0>(edge_no_w const& x) {
       return x.v;
    }
}
constexpr int get_lg_2(int num) {
    int k =0;
    while( (1<<(k+1)) <= num) k++;
    return k;
}
enum class LCA_TYPE {
    calc_len,
    no_calc_len
};
constexpr auto CALC_LEN  = LCA_TYPE::calc_len;
constexpr auto NO_CALC_LEN  = LCA_TYPE::no_calc_len;
template<LCA_TYPE CALC = NO_CALC_LEN,std::size_t N = maxn>
struct lca_craw {
#ifdef DEBUG
    bool init_flag = false;
#endif
    const int lg;
    int dep[maxn]; //每个点的深度
    int f[maxn][get_lg_2(N)+1];
    int f_len[maxn][get_lg_2(N)+1]; //点i到2^j祖先的距离
    lca_craw() : lg(get_lg_2(N)) {}
    template<typename GraphType,typename Edge,std::size_t V_CNT,std::size_t E_CNT>
    void init(linkList<GraphType,Edge,V_CNT,E_CNT> & e ,int root) {
        dfs(e,root,0,1); //这里的fa的参数必须是0
#ifdef DEBUG
    init_flag = true;
#endif
    }
    template<typename GraphType,typename Edge,std::size_t V_CNT,std::size_t E_CNT>
    void dfs(linkList<GraphType,Edge,V_CNT,E_CNT> & e,int u,int fa,int depth) {
        dep[u] = depth;
        f[u][0] = fa;
        for(int j =1;j<=lg;j++) {
            f[u][j] = f[ f[u][j-1] ][j-1];
            if constexpr ( CALC_LEN == LCA_TYPE::calc_len)
                f_len[u][j] = f_len[ f[u][j-1] ][j-1] + f_len[u][j-1];
        }
        for(int i = e.head(u) ; ~i ;i = e[i].next )
        {
            int & v = e[i].v;
            if constexpr ( CALC_LEN == LCA_TYPE::calc_len) {
                if constexpr (is_edge<Edge>::value)
                    f_len[v][0] = e[i].w;
                if constexpr (is_edge_no_w<Edge>::value)
                    f_len[v][0] = 1; //如果没有边长,则认为就长度就是1
            }
            if( v == fa) continue;
            dfs(e,v,u,depth+1);
        }
    }
    int __find_lca(int a,int b) {
        if( dep[a] > dep[b] ) //保证a浅b深
            std::swap(a, b);
        for(int i =lg ;i>=0;--i)
            if( dep[ f[b][i] ] >= dep[a]){
                b = f[b][i];
            }
        if( a == b) return a;
        for(int i =lg ;i>=0;--i)
        {
            if( f[a][i] != f[b][i]) ///不相同就跳
            {
                a = f[a][i];
                b = f[b][i];
            }
        }
        return f[a][0]; //返回停下来时候的父亲，就是lca
    }
    std::size_t __calc_path_len(int a,int b,int lca) {
        std::size_t __len = 0; //算法跑的长度
        auto calc_len = [&](int u) {
            for(int i =lg ;i>=0;--i)
                if( dep[ f[u][i] ] >= dep[lca]){
                    __len += f_len[u][i];
                    u = f[u][i];
                }
        };
        calc_len(a);
        calc_len(b);
        return __len;
    }
    auto find(int a,int b) 
    {
#ifdef DEBUG
    if(!init_flag)
        throw std::invalid_argument("lca_craw must first call lca_craw::init()!");
#endif
        if constexpr ( CALC_LEN == LCA_TYPE::calc_len){
            auto lca = __find_lca(a, b);
            auto len = __calc_path_len(a, b, lca);
            return std::make_tuple(lca,len);
        }
        else 
            return __find_lca(a, b);
    }
};
template<typename T,std::size_t V_CNT = maxn,std::size_t TOT = maxe>
struct adjacencyList {
private:
    inline void __next(int head) {
        nxt[cnt] = h[head];
        h[head] = cnt;
        ++cnt;
    }
public:
    int h[V_CNT]; //表头
    T mem[TOT];   // 内存池
    int nxt[TOT]; // next数组,nxt[i] ,给同表头的下一下数据
    int cnt;      // 内存池计数
    adjacencyList() {
        clear();
    }
    inline void clear() {
        cnt = 0;
        memset(h,-1,sizeof(h));
    }
    inline void push(int head,T && val) {
        mem[cnt] = std::move(val);
        __next(head);
    }
    inline void push(int head,const T & val) {
        mem[cnt] = val;
        __next(head);
    }
    int head(int u) const { return h[u];}
    int size() const { return cnt;}
    T & operator[](unsigned int i) {
        return mem[i];
    }
    int next(int idx) const {
        return nxt[idx];
    }
    struct memIterator {
        adjacencyList * self; //指向adjacencyList的指针
        int idx; //数据下标
        memIterator(adjacencyList * p,int _idx)
            : self(p),idx(_idx)
        {}
        memIterator & operator++() {
            if(idx != -1) idx = self->next(idx);
            return *this;
        }
        bool operator!=(int a) { return idx !=a;}
        bool operator!=(const memIterator & a) { return idx !=a.idx;}
        T & operator*() { return self->mem[idx]; }
    };
    struct mems {
        adjacencyList * self;
        const int u;
        mems(adjacencyList *p,int _u)
            :self(p),u(_u)
        {}
        memIterator begin() const {
            return memIterator(self,self->head(u));
        }
        int end() { return -1;}
    };
    auto start_from_head(int u) {
        return mems(this,u);
    }
};
using namespace std;
typedef long long ll;
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)
#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif
int n,m;
int w[maxn];
int bucket_1[maxn<<1]; // 🪣1 记录 dep[s] ,w[a]
int bucket_2[maxn<<1]; // 🪣2 记录 len(s,t) - dep[t] + n ,w[a]-dep[a] +n
int bucket_3[maxn<<1]; // 🪣3 记录可以同时观察到 s,t的点能观察到的数量
graph_nw tree; //存树
lca_craw<CALC_LEN> lca; //求lca
int ans[maxn]; //记录答案
struct _edge {int s,t,len;};
adjacencyList<_edge> people; // 跑步的人
adjacencyList<int> lca_list; //以为lca头, people上边编号的为数据
void init()
{
    in.read(n,m);
    F(n-1){
        in >> tree;
    }
    in >> YankArray(n) >> w;
    lca.init(tree,1); //初始化,lca
    F(m){
        int s,t;
        in.read(s,t);
        auto [_lca,len] = lca.find(s,t);
        people.push(s,{s,t,int(len)});
        int id = people.size()-1;
        people.push(t,{t,s,int(len)});
        lca_list.push(_lca,id);
        if( w[_lca] == lca.dep[s] - lca.dep[_lca] )
        {
            bucket_3[_lca]++;
        }
    }
}
void dfs_cnt(int u,int fa,int dep) {
    ans[u] -= bucket_1[ w[u] + lca.dep[u] ] + bucket_2[w[u]-lca.dep[u]+n];
    for(auto &v : tree.edges_start_for(u))
    {
        if( v == fa ) continue;
        dfs_cnt(v,u,dep+1);
    }
    for(int i = people.head(u) ; ~i ; i = people.next(i))
        if( (i  & 1) == 0 ) //这条边是正向的,也就是以u为起点的
            bucket_1[dep]++;
        else { // 这条边是反向的,也就是以u为终点
            int len = people[i].len;
            bucket_2[len-dep+n]++;
        }
    ans[u] += bucket_1[ w[u] + lca.dep[u] ] + bucket_2[w[u]-lca.dep[u]+n];
    ans[u] -= bucket_3[u];
    for( auto idx : lca_list.start_from_head(u)) {
        int s = people[idx].s;
        int t = people[idx].t;
        int len = people[idx].len;
        bucket_1[lca.dep[s]]--;
        bucket_2[len-lca.dep[t]+n]--;
    }
}
int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    dfs_cnt(1,0,1);
    ans >> YankArray(n) >> out;
    return 0;
}
