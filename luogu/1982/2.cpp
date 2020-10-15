#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e6+7;
const long long INF = 1e16;

int n, p;
int a[Maxn];
long long b[Maxn], m[Maxn];
long long cur, maxsum, ans = -INF;

int main()
{
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    m[1] = maxsum = b[1] = cur = a[1];
    if(cur < 0) cur = 0;
    debug("%d %d\n",1,b[1]);
    for(int i = 2; i <= n; ++i)
    {
        cur += a[i];
        b[i] = maxsum = max(maxsum, cur);
        debug("%d %d\n",i,b[i]);
        if(cur < 0) cur = 0;
    }
    for(int i = 2; i <= n; ++i)
    {
        m[i] = ans = max(ans, m[i-1]+b[i-1]);
    }
    //ans = max(ans, m[1]);
    //printf("%d\n", ans%p);
    return 0;
}
