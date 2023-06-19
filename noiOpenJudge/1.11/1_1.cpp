#include <iostream>
using namespace std;
int n, m;

typedef long long ll;

ll a[10000 + 5];

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
    }
}

bool check(ll a, ll b)
{
    return a >= b;
}

ll _abs(ll a, ll b)
{
    ll t = a - b;
    if (t > 0)
        return t;
    return -t;
}

ll get_best_fit(ll key, ll a, ll b)
{
    if (_abs(key, a) <= _abs(key, b))
        return a;
    return b;
}

int first_ge(int l, int r, ll key)
{
    int m;
    while (l < r)
    {
        m = (l + r) >> 1;
        if (check(a[m], key))
            r = m;
        else
            l = m + 1;
        // cout << "l " << l << " r " << r << "\n";
    }
    return r;
}

int main(int argc, char const *argv[])
{
    init();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll t;
        cin >> t;
        int pos = first_ge(1, n + 1, t);
        // cout << t << " " << pos << " ";
        if (pos == 1)
            cout << a[pos];
        else if (pos == n + 1)
            cout << a[n];
        else
        {
            cout << get_best_fit(t, a[pos - 1], a[pos]);
        }
        cout << "\n";
    }

    return 0;
}
