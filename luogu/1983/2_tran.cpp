/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-27 15:44:07
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e7
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
    return num;
}
constexpr int add_five(int number) {
    return number + 5;
}
long long operator ""_Number(const char * str,std::size_t N){
    return _sexp_to_number(std::string_view(str,N));
}
struct __INF {
    template<typename T>
    constexpr operator T() const {
        return std::numeric_limits<T>::max();
    }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
struct __NINF {
    template<typename T>
    constexpr operator T() const {
        return std::numeric_limits<T>::lowest();
    }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
constexpr auto NINF = __NINF();
constexpr auto INF  = __INF();
struct __inf {
    constexpr operator unsigned long long() const { return 0x3f3f3f3f3f3f3f3f; }
    constexpr operator long long() const  { return 0x3f3f3f3f3f3f3f3f; }
    constexpr operator unsigned int() const { return 0x3f3f3f3f; }
    constexpr operator int() const { return 0x3f3f3f3f; }
    constexpr operator char() const { return 0x3f; }
    constexpr operator unsigned char() const { return 0x3f; }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
constexpr auto inf = __inf();
#ifdef __maxn__
const int maxn = add_five(_sexp_to_number(__M_concat_sv(__maxn__)));
#elif not defined (maxn)
const int maxn = 1000007;
#endif
#ifdef __maxe__
const int maxe = add_five(_sexp_to_number(__M_concat_sv(__maxe__)));
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
    template<typename T,typename ...Args,
    std::enable_if_t<
        std::conjunction_v<std::is_integral<T>,std::is_integral<Args>...>
    ,int> = 0
    >
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
    template<typename T,std::enable_if_t< std::is_integral_v<std::remove_cvref_t<T>> ,int> = 0 >
    void print_one(T n) {
        if constexpr( std::is_same_v<T,char>) { //是一个字符类型
            putc(n);
        }
        else {
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
    }
    void print_one(const std::string & str) {
        for(char c: str)
            print_one(c);
    }
    template<char sep=' ',typename... T>
    void print_one(const std::tuple<T...> & tup) {
        [&]<std::size_t... I>(std::index_sequence<I...>){
            print<sep>(std::get<I>(tup)...);
        }(std::make_index_sequence<sizeof...(T)> {});
    }
    template<std::size_t N>
    void print(const char (&str)[N]){
        for(int i = 0;i<N && str[i]!='\0'; ++i )
        {
            print_one(str[i]);
        }
    }
    template<std::size_t N>
    void println(const char (&str)[N]){
        print(str);
        ln();
    }
    template<char sep = ' ',typename Iter>
        requires requires(Iter it) {
            {*it};   // it can be dereferenced.
            {++it};  // it can be incremented.
        }
    void print(Iter begin,Iter end) {
        for( auto i = begin ; i != end ;++i){
            print_one(*i);
            putc(sep);
        }
    }
    template<char sep = ' ',typename Iter>
        requires requires(Iter it) {
            {*it};   // it can be dereferenced.
            {++it};  // it can be incremented.
        }
    void println(Iter begin,Iter end) {
        for( auto i = begin ; i != end ;++i){
            print_one(*i);
            putc(sep);
        }
        ln();
    }
    template<char sep = ' ',typename T,typename ...Args
    >
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
inline
int predecessor(int  i,const int & m) {
    return i-m+1;
}
struct AdjacentNumberFinder {
    int m;
    AdjacentNumberFinder(int o)
        :m(o)
    {}
    inline
    int forward(int i) const{
        return i-m;
    }
    inline
    int backword(int i) const{
        return i+m;
    }
    friend
    int operator < (int i,const AdjacentNumberFinder & adj) {
        return adj.forward(i);
    }
    friend
    int operator > (int i,const AdjacentNumberFinder & adj) {
        return adj.backword(i);
    }
};
template<typename... T>
auto maximum(T&&... args) {
    return std::max({std::forward<T>(args)...});
}
template<typename T1,typename T2>
void upd_max(T1 & t,const T2& t2){
    if(t < t2)
        t = t2;
}
template<typename T1,typename T2>
void upd_min(T1 & t,const T2& t2){
    if(t > t2)
        t = t2;
}
template<typename T1,typename T2,typename... T3>
void upd_max(T1 & t,const T2& t2, const T3 &... t3) {
    if(t < t2)
        t = t2;
    upd_max(t,t3...);
}
template<typename T>
inline bool is_in_range(T&& a,T && l, T&& r) {
    return a >= l && a <= r;
}
template<typename Iter,
    typename = std::void_t<decltype(*std::declval<Iter>(),++std::declval<Iter&>())> >
inline auto max_pos(Iter l,Iter r) {
    Iter pos = l;
    for( ; l != r; ++ l) {
        if( *pos < *l) pos = l;
    }
    return pos;
}
template<typename Iter,
    typename = std::void_t<decltype(*std::declval<Iter>(),++std::declval<Iter&>())> >
inline auto max_val(Iter l,Iter r) {
    return *max_pos(l,r);
}
template<typename T>
requires std::is_same_v<T, int> || std::is_same_v<T, long long>
T sgn(T a,T b) {
    return (a^b) < 0 ? -1 : 1;
}
template<typename T = long long>
struct Fraction {
    T a,b; // 分子分母
    static
    constexpr
    T sgn(T a,T b) {
        return (a^b) < 0  ? -1 : 1;
    }
    static
        constexpr
        T _abs(T a) { return a < 0 ? -a : a;}
    constexpr
    Fraction(T a,T b)
        : a(sgn(a,b)*_abs(a)), //a来存公共符号
        b(_abs(b))
    {}
    constexpr
    Fraction() : Fraction(1l,1l) {}
    void update(T _a, T _b) {
        a = _a;
        b = _b;
    }
    T & n() { return a; } //分子的引用
    T & d() { return b;} // 分母的引用
    bool operator==(const Fraction & oth) const
    {
        return a * oth.b ==  b * oth.a;
    }
    bool operator!=(const Fraction & oth) const
    {
        return !(*this == oth);
    }
    bool operator<(const Fraction & oth) const
    {
        return a * oth.b < oth.a * b;
    }
    bool operator>(const Fraction & oth) {
        return a * oth.b > oth.a * b;
    }
    Fraction operator*(const Fraction oth) const;
    Fraction operator-(const Fraction oth) const;
    Fraction operator+(const Fraction oth) const;
};
const auto Fraction_inf = Fraction<long long>(1l,0l);
const auto Fraction_neg_inf = Fraction<long long>(-1l,0l);
Fraction() -> Fraction<long long>;
using fraction = Fraction<long long>;
template<typename T=int,std::size_t N=maxn>
struct dynamic_array {
    T a[maxn];
    int idx;
    using value_type = T;
    using iterator = T *;
    dynamic_array() :idx{0} {}
    inline void clear() { idx = 0; }
    void push(const T& v) {
        a[++idx] = v;
    }
    inline
    T & back() {
        return a[idx];
    }
    inline
    T & top() {
        return back();
    }
    inline
    void pop_back() {
        --idx;
    }
    std::size_t size() const { return idx;}
    T * begin() {
        return &a[1];
    }
    T * end() {
        return &a[idx+1];
    }
    const T * begin() const {
        return &a[1];
    }
    const T * end() const {
        return &a[idx+1];
    }
    T & operator[](std::size_t id) {
        return a[id];
    }
    template<typename F>
    dynamic_array & map(F&& f) {
        for(int i = 1;i <= idx ;i++) {
            if constexpr (std::is_invocable_v<F,T> || std::is_invocable_v<F,T&>){
                f(a[i]);
            }
            else if constexpr(std::is_invocable_v<F,int,T>,std::is_invocable_v<F,int,T&>) {
                f(i,a[i]);
            }
#ifdef DEBUG
            else {
                throw std::invalid_argument("in dynamic_array map,map(Function),Function not invocable!");
            }
#endif
        }
        return *this;
    }
};
#ifdef  __FAST_OUT_
template<typename T>
fast_out & operator>>(fast_in & in,dynamic_array<T> & da) {
    auto end = da.end();
    in >> *end;
    ++da.idx;
    return out;
}
template<typename T>
fast_out & operator<<(fast_out & out ,dynamic_array<T> & da) {
    out.println(da.begin(), da.end());
    return out;
}
#endif
#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp" 
#else
#define log(...)
#endif
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)
int n,m,root;
dynamic_array<int> a;
dynamic_array<int> b;
int in_dgree[maxn];
int d[maxn];
int gh[1005][1005];
inline void init() {
    in(n,m);
    F(m){
        int t;
        in.read(t);
        a.clear();
        FF( j , t ){
            in >> a;
        }
        b.clear();
        F3(j,2,a.size()) {
            int start = a[j-1];
            int end = a[j];
            for(int k = start+1;k < end; k++) {
                b.push(k);
            }
        }
        FF( j , a.size() ){
            FF( k , b.size() ){
                if( gh[b[k]][a[j]] == 0 )
                {
                    gh[b[k]][a[j]] = 1; //表明 b[k] 到 a[j] 有连线
                    in_dgree[a[j]]++;
                }
            }
        }
    }
}
int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    a.clear();
    F(n){
        if(in_dgree[i] == 0)
        {
            d[i] = 1;
            a.push(i); //加入第一层入度为0的点
        }
    }
    int cnt = n;
    int ans = 0;
    while( n ) {
        int u = a.top();
        ans = std::max(ans,d[u]);
        a.pop_back();
        n--;
        for(int v = 1 ; v<=cnt; v++)
        {
            if( gh[u][v] == 0) continue;
            if(d[v] <= d[u])
                d[v] = d[u]+1;
            in_dgree[v]--;
            if( in_dgree[v] == 0) {
                a.push(v);
            }
        }
    }
    out << ans;
    return 0;
}
