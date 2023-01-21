#include<bits/stdc++.h>
using namespace std;
int const N=150;
int const M=500050;
int t, n, m;
int a[N][N];
int f[M];

int main()
{
	cin >> n >> t >> m;
	for (int i = 1;i <= n;i ++)
		for ( int j = 1;j <= t;j ++)
			cin >> a[j][i];
	for (int k = 1; k <= t;k ++)
	{
		memset(f, 0, sizeof(f));
		for (int i = 1;i <= n;i ++)
			for (int j = a[k][i];j <= m ;j ++)
				f[j] = max(f[j], f[j - a[k][i]] + a[k + 1][i] - a[k][i]);
		m = max(f[m] + m, m);
	}	
	cout << m;
	return 0;
}
