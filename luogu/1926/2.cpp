#include <bits/stdc++.h>
using namespace std;

int n, k, m, r;

vector<int> _time;

vector<int> w, v;
int f1[200];

void init()
{
    cin >> n >> m >> k >> r;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        _time.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        w.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
}

int main(int argc, char const *argv[])
{
    init();

    for (int i = 0; i < m; i++)
    {
        for (int j = 150; j >= w[i]; j--)
            f1[j] = max(f1[j], f1[j - w[i]] + v[i]);
    }

    int need = -1;
    for (int i = 0; i <= 150; i++)
        if (f1[i] >= k && i <= r)
        {
            // cout << "f1 " << i << " " << f1[i] << "\n";
            // cout << "k " << k;
            need = i;
            break;
        }

    if (need == -1)
    {
        cout << 0;
        return 0;
    }
    // cout << " need " << need << "\n";

    int left = r - need;

    sort(_time.begin(), _time.end());

    int ans = 0;
    for (int i = 0; i < _time.size(); i++)
    {
        if (_time[i] <= left)
        {
            ans++;
            left -= _time[i];
        }
    }
    cout << ans;
    return 0;
}
