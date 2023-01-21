#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000000 + 5;

typedef long long LL;

LL power(LL a, LL b) {
    LL ans = 1;
    for (; b; b >>= 1, a *= a)
        if (b & 1) ans *= a;
    return ans;
}

LL n, ans, pos[MAXN], sum[MAXN];

LL calc(LL l, LL r) {
    return (r - l + 1 - r / 2 + (l - 1) / 2 - r / 5 + (l - 1) / 5 + r / 10 - (l - 1) /  10);
}

int main() {
    cin >> n;
    int cnt = 0;
    //预处理
    for (LL l = 1, r; l <= n; l = r + 1) {
        pos[++cnt] = r = n / (n / l); 
        sum[cnt] = sum[cnt - 1] + calc(l, r) * (n / l);
    }

    int p2 = log(n) / log(2); LL t1 = power(2, p2); 
    for (int i = p2; i >= 0; --i, t1 /= 2) {
        int p5 = log(n / t1) / log(5); LL t2 = power(5, p5);
        for (int j = p5; j >= 0; --j, t2 /= 5) {
            LL lim = n / t1 / t2;
            int x = lower_bound(pos + 1, pos + cnt + 1, lim) - pos - 1;
            ans += sum[x] + calc(pos[x] + 1, lim) * (n / lim);
        }
    }
    cout << ans << endl;
    return 0;
}
