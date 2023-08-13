#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;
int sub[maxn]; // sub array
void init(){
    cin >> n;
    memset(sub,0,sizeof(sub));
}

void sub_range_add(int l,int r,int add) {
    sub[l] += add;
    sub[r+1] -= add;
}
int main(){
    while(1) 
    {
        init();
        if( n == 0) break;
        for(int i = 1;i <= n ;++i ) // i: 1->n
        {
            int a,b;
            cin >> a >> b;
            sub_range_add(a,b,1);
        }
        int sum = 0;
        for(int i = 1;i <= n ;++i ) // i: 1->n
        {
            sum += sub[i];
            cout << sum << " ";
        }
        cout << "\n";
    }

    return 0;
}

