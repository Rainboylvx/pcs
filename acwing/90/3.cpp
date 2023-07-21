#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int main()
{
    ll a,b,p,res;
    cin>>a>>b>>p;
    res=0;
    while(a)
    {
        if(a&1) {
            res=(res+b)%p;
            cout << res << " " << b << endl;
        }
        a>>=1;
        b=2*b%p;
    }
    cout<<res<<endl;
    return 0;
}
