#include <bits/stdc++.h>
using namespace std;
#define F(i,s,t) for(int i=s;i<=t;++i)
#define fenc cout << "==========\n"
#define log(a) cout << #a " = " << a << endl

typedef  long long ll;

int _max,n,m,a[100005];
long long l,r=1;
long long mid;
void init(){
    cin>>n>>m;
    F(i,1,n){
        cin>>a[i];
        _max=max(_max,a[i]);
        r+=a[i];
    }
    l=_max;
}

/**
 * 和我说的一定 二分答案错的时间 基本都是check函数错误
 *
 * 如何找错误,最好就是找数据带进去看看
 * 比如
 * 3 1
 * 1
 * 1
 * 1
 * 这个数据,你写的check函数就不符合预期
 */
bool check(long long num){
    long long tempz=0;
    int rest=m;
    F(i,1,n){
        if(tempz+a[i]>num){
            tempz=0; //这里是不是不应该是0 ?
                     // tempz = a[i]
            rest--;
        }
        if(tempz+a[i]<=num)
        {
            tempz+=a[i];
        }
        if(rest<0)
        return 0;
    }
    return 1;
}

//计算最少可以多少组
ll count_group(int num) {
    ll cnt=0;
    ll tot = 0;
    for(int i = 0 ;i<=n;i++){
        if( tot + a[i] > num) { //超过了一组的最大值
            tot = a[i];
            cnt++; //组数加一
        }
        else { // <= n
            tot += a[i];
        }
    }
    // 最后tot里一定有值,这些算一组
    cnt++;
    return cnt;
}

int main(){
    init();
    while(l!=r){
        mid=(l+r)>>1;
        // if(check(mid))
        if(count_group(mid) <= m)
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
