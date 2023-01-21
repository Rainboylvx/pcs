#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10;
const int Mod = 998244353;

bool f, vis[N][N];
int n, m, k;
char Map[N][N];
int answer[N * N], tot;
int finalans;
int summm;

inline bool check (int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m || Map[x][y] == 'X' || f || vis[x][y]) return false; // 很明显的 dfs 判断越界、遍历等情况
	else return true;
}

inline void dfs (int x, int y) {
	if (!check (x, y)) return;
	int cnt = 0;
	if (Map[x + 1][y] == 'O') ++ cnt;
	if (Map[x - 1][y] == 'O') ++ cnt;
	if (Map[x][y + 1] == 'O') ++ cnt;
	if (Map[x][y - 1] == 'O') ++ cnt; // 神奇的 if 判断这个位置与旁边的位置的连接数量
	if (cnt == 1) ++ summm; // 如果只与一个位置相连，计数器加一
	if (cnt > 2) { // 如果不满足规律，直接输出 0
		f = true;
		return;
	}
	vis[x][y] = true; // 表示已经遍历过了
	++ finalans;
	dfs (x - 1, y); dfs (x, y - 1);
	dfs (x + 1, y); dfs (x, y + 1); // dfs 的套路
	return;
}

inline int query (int b, int p) { // 快速幂板子
	int sum = 1;
	while (p) {
		if (p & 1) sum = sum * b % Mod;
		b = b * b % Mod;
		p >>= 1;
	}
	return sum;
}

signed main () {
	cin >> n >> m >> k;
	for (register int i = 1; i <= n; ++ i) {
		for (register int j = 1; j <= m; ++ j) cin >> Map[i][j]; // 输入考场布局
	}
	for (register int i = 1; i <= n; ++ i) {
		for (register int j = 1; j <= m; ++ j) {
			if (Map[i][j] == 'O') { // 如果这是一个位置
				summm = 0;
				finalans = 0;
				dfs (i, j);
				if (summm ^ 2 && finalans > 1) f = true; // 如果不满足结论
				if (f) {
					puts ("0");
					return 0;
				}
				if (!finalans) continue; // 如果答案为 0
				answer[++ tot] = finalans; // 存储每一个块的数量
			}
		}
	}
	int summ = 1;
	for (register int i = 1; i <= tot; ++ i) {
		summ *= (query (k - 1, answer[i] - 1) * k % Mod); // 快速幂+乘法原理
		summ %= Mod; // 不用考虑 k=1 的情况，反正快速幂最开始的 sum 为 1
	}
	cout << (summ + Mod) % Mod << endl; // 尛 Mod 输出，
	return 0;
}
