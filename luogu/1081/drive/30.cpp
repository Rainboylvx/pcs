/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 14日 星期三 14:57:46 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量


template<typename... Args>
void print(Args&&... args){
    ( (cout << args << " "),...);
    cout << '\n';
}

//#define log(...) print(#__VA_ARGS__,__VA_ARGS__)
#define log(...)


int n,m;
/* 定义全局变量 */

int a[maxn];// 每个点的高度
int next_1[maxn],next_2[maxn];

int sub_abs(int a,int b) {
    int t = a-b;
    return t<0 ? -t :t;
}
void get_next(){

    for(int i=1;i<n;++i){
        int t1 = 0x7f7f7f7f;
        int t2 = 0x7f7f7f7f;
        for(int j=i+1;j<=n;++j){
            int dis1  = sub_abs(a[i], a[j]);
            if( t1 > dis1 
                || (t1==dis1 && a[j] < a[next_1[i]])
                    )
            {
                if( t1 < t2
                || (t1 == t2 && a[next_1[i]] < a[next_2[i]]))
                {
                    t2=t1;
                    next_2[i]= next_1[i];
                }

                next_1[i] = j;
                t1 = dis1;
            }
            else if( t2 > dis1
                || (t2==dis1 && a[j] < a[next_2[i]])
                    )
            {
                next_2[i] = j;
                t2 = dis1;
            }
        }
        log(i,next_1[i],next_2[i]);
    }
}

void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];
}

int lena,lenb;
void dfs(int i,bool afirst,int left){
    if(left <=0) return;
    int next;
    if( afirst )
        next = next_2[i];
    else
        next = next_1[i];
    if( next ==0 )
        return;

    int dis =sub_abs(a[i], a[next]);
    if( left-dis<0)
        return;
    if( afirst )
        lena+=dis;
    else
        lenb+=dis;
    dfs(next,!afirst,left-dis);
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    // step 1
    get_next();
    // step 2 : a,b len_a,len_b
    int x0;
    cin >> x0;
    int ans_1;
    double rate;
    for(int i=1;i<=n;++i){
        lena=lenb=0;
        dfs(i,true,x0);
        log(lena,lenb);
        if( lenb !=0 ){
            double new_rate = lena *1.0 /lenb;
            if( i==1 || new_rate < rate) {
                rate = new_rate;
                ans_1 =i;
            }
            else if ( i!=1 && new_rate == rate){
                if( a[i] > a[ans_1])
                {
                    rate = new_rate;
                    ans_1 =i;
                }
            }
        }
    }
    cout << ans_1 <<'\n';

    cin >> m;
    for(int i=1;i<=m;++i){
        int s,x;
        std::cin >> s >> x;
        lena=lenb=0;
        dfs(s,true,x);
        cout << lena << " " << lenb <<'\n';
    }
    return 0;
}
