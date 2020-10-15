/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 09月 05日 星期六 20:21:26 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif


const int maxn = 1e6+5;
__int128 n,p;
__int128 a[maxn];
__int128 f[maxn];

void print(__int128 x)  
{  
    if(!x)  
    {  
        puts("0");  
        return ;  
    }  
    string ret="";  
    while(x)  
    {  
        ret+=x%10+'0';  
        x/=10;  
    }  
    reverse(ret.begin(),ret.end());  
    cout<<ret<<endl;  
} 


int  main(){
    scanf("%lld%lld",&n,&p);
    __int128 i,j;
    for(i=1;i<=n;++i) scanf("%lld",&a[i]);
    f[1] = a[1];
    for(i=2;i<=n;++i){
        if( f[i-1] > 0 ) f[i] = f[i-1]+a[i];
        else f[i] = a[i];
        debug("%d %d\n",i,f[i]);
    }
    debug("\n");
    __int128 ans = f[1];
    __int128 _max = f[1] + f[1];
    debug("%d %d\n",1,f[1]);
    for(i=2;i<=n;++i){
        __int128 t = _max;
        debug("%d %d\n",i,t);
        ans = max(ans,t);
        _max = max(_max,t+f[i]);
    }
    if( ans < 0) printf("-");

    //printf("%lld\n",abs(ans) % p);
    print(abs(ans) % p);


    return 0;
}
