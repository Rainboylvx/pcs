#include <bits/stdc++.h>
using namespace std;
// f[j] = f[j] + f[j-w[i]]
// f[0] = 1
// typedef long long long long;

long long n;
long long tot;
long long binary;
void init()
{

    cin >> n;
    tot = (1 + n) * n / 2;
    binary = tot / 2;
}

long long f[1000 + 5] = {1};

int main()
{
    init();
    if (tot % 2 == 1)
    {
        cout << 0;
        return 0;
    }
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = binary; j >= i; j--)
        {
            f[j] += f[j - i];
        }
    }
    cout << f[binary] / 2 << endl;

    return 0;
}