//一个枚举的代码,基于next_permutation,的n个数中选m个数
/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-28 15:10:24
*----------------*/
#define maxn 1000005
#define maxe 2000005
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//////// 常用宏
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
/* 定义全局变量 */

int s[maxn]; //常用的一个数组
int a[maxn]; //常用的一个数组

int end_choose[maxn];// 只选择i点得到的值

void init()
{
    cin >> n;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cout << i << "\t";
    }
    cout << endl;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> s[i];
        cout << s[i] << "\t";
    }
    cout << endl;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> a[i];
        cout << a[i] << "\t";
    }
    cout << endl;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        end_choose[i] = 2*s[i]+a[i];
        cout << end_choose[i] << "\t";
    }
    cout << endl;


}

void combination_baseOn_next_permutation(int n ,int m)
{

    std::vector<int> v;
    for(int i =1;i<=n-m;i ++ )
        v.push_back(0);
    for(int i =1;i<=m;i++)
        v.push_back(1);

    int _max=0;
    int pos;
    do {
        int sum =0;
        int last;
        for(int i = 0 ;i< v.size() ;i++ ){
            if( v[i] == 1 ) {
                //第i/i+1 个被选了
                int c = i+1;
                sum += a[c];
                cout <<  i+1 << " "; //输出选的那个人
                last = c;
            }
        }
        sum += 2*s[last]; //加上距离 
        cout << " | sum = " << sum;
        if( _max <= sum) {
            _max = sum;
            pos = last; //确定最后一个选的人
        }
        cout << "\n";

    }while(std::next_permutation(v.begin(),v.end()));

    cout << "max = " << _max << "  | ";
    cout << " max end pos = " << pos << "\n";
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    for(int i = 1;i <= n ;++i ) // 选i个人
    {
        cout << "-------------- choose len : " << i  << endl;
        combination_baseOn_next_permutation(n,i);
    }
    
    return 0;
}
