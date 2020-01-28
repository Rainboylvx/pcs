#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define each(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define reach(i, n) for (int(i) = n - 1; (i) >= 0; (i)--)
#define range(i, st, en) for (int(i) = (st); (i) <= (en); (i)++)
#define rrange(i, st, en) for (int(i) = (en); (i) >= (st); (i)--)
#define fill(ary, num) memset((ary), (num), sizeof(ary))

using namespace std;

const int maxn = 105;

int n, m, ans;
int g[maxn][maxn], dp[maxn];
int vex[maxn], avex[maxn];

bool isClique(const int& sz, const int& end)
{
    range(i, 1, sz) if (!g[vex[i]][end]) return false;
    return true;
}

void dfs(int dep, int cur)
{
    if (dep + n - cur + 1 <= ans || dep + dp[cur] <= ans)
        return;
    range(i, cur, n) if (isClique(dep, i))
    {
        vex[dep + 1] = i;
        dfs(dep + 1, i + 1);
    }
    if (ans < dep) {
        ans = dep;
        memcpy(avex, vex, sizeof vex);
    }
}

int main()
{
    int T, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        range(i, 1, n) range(j, 1, n) g[i][j] = 1;
        while (m--) {
            scanf("%d %d", &u, &v);
            g[u][v] = g[v][u] = 0;
        }
        fill(dp, 0), dp[n] = 1, ans = 0;
        rrange(i, 1, n - 1)
        {
            vex[1] = i;
            dfs(1, i + 1);
            dp[i] = ans;
        }
        printf("%d\n", dp[1]);
        range(i, 1, ans) printf("%d%c", avex[i], " \n"[i == ans]);
    }
    return 0;
}
