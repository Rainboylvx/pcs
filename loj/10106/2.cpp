// #pragma GCC target("avx2")
//#pragma GCC optimize("O3", "unroll-loops")
 
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
// template <typename T>
// using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using pii = pair<int, int>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using Prior = priority_queue<T>;
 
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()
#define eb emplace_back
#define pb push_back
 
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RANDOM() random_device __rd; \
                 mt19937 __gen = mt19937(__rd()); \
                 uniform_int_distribution<int> __dis(0, 1); \
                 auto rnd = bind(__dis, __gen);
 
const int INF = 1E18;
const int mod = 1E5 + 3;

int adj[30][30], deg_ou[30], deg_in[30], vis[30];

void dfs(int now) {
    vis[now] = 1;
    for (int i = 0; i < 30; ++i) {
        if (!vis[i] and adj[now][i]) dfs(i);
    }
}

void solve() {
    int n, in = 0, ou = 0;
    string s;
    cin >> n;
    
    while (n--) cin >> s, ++adj[s[0]-'a'][s.back()-'a'];
    
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 30; ++j) {
            deg_ou[i] += adj[i][j];
            deg_in[j] += adj[i][j];
        }
    }
    
    for (int i = 0; i < 30; ++i) {
        if (deg_in[i] == deg_ou[i]) continue;
        if (deg_in[i] == deg_ou[i] - 1 and !ou) {ou = i; continue;}
        if (deg_in[i] == deg_ou[i] + 1 and !in) {in = i; continue;}
        cout << "The door cannot be opened.\n";
        return;
    }
    
    dfs(ou);
    
    for (int i = 0; i < 30; ++i) {
        if (deg_in[i] and !vis[i]) {
            cout << "The door cannot be opened.\n";
            return;
        }
    }
    
    cout << "Ordering is possible.\n";
}

void init() {
    for (int i = 0; i < 30; ++i) memset(adj[i], 0x00, sizeof(adj[i]));
    memset(deg_ou, 0x00, sizeof(deg_ou));
    memset(deg_in, 0x00, sizeof(deg_in));
    memset(vis, 0x00, sizeof(vis));
}

int32_t main() {
    fastIO();
    
    int t;
    cin >> t;
    while (t--) init(), solve();
    
    return 0;
}
