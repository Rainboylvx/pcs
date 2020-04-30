#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("copycat.in","r",stdin);
	freopen("copycat.out","w",stdout);
	int T;
	cin >> T;
	string a;
	if ( T > 9) T--;
	for(int i = 1 ; i <= T ; i ++)
	{
		cin >> a ;
		cout << a << endl ;
	}
	return 0;
}
