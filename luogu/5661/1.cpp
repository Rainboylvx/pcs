#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5+5;
int n;
int T[maxn],V[maxn];
int cnt;

int main(){
    cin >> n;
    int i,j;
    int x,y,z;
    int spend = 0;
    for(i=1;i<=n;++i){
        cin >> x >> y >> z;
        if( x == 0){
            cnt++;
            V[cnt] = y;
            T[cnt] = z;
            spend += y;
        }
        else {
            int idx = -1;
            for( j =cnt ;j >= 1 ;j --){
                if( T[j] < z-45) break;
                if( V[j] >= y) {
                    idx =  j;
                }
            }
            if( idx == -1) spend +=y;
            else V[idx] = -1;
        }
    }
    cout << spend;

    return 0;
}
