#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

int main(){
    cin >> n;
    int day = 0; //你已经经过了多少天
    int ans = 0;
    int i,j;
    for( i = 1; ;i++){
        for(j =1;j<=i;j++ ){
            day++;
            ans += i;
            if( day == n){
                cout << ans;
                return 0;
            }
        }
    }

    return 0;
}
