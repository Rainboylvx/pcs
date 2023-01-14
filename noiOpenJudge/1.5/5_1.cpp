#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    std::cin >> n;
    int t;
    int m = -1;
    for(int i=1;i<=n;++i){
        std::cin >> t;
        if( m < t )
            m = t;
    }
    std::cout << m << std::endl;
    return 0;
}

