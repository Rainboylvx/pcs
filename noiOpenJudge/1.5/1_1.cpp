#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    std::cin >> n; //2
    int sum = 0;

    int t;
    for(int i=1;i<=n;++i){
        cin >> t; // 18,17
        sum += t;
    }


    double ans = sum * 1.0 / n;
    std::cout <<fixed <<  std::setprecision(2) << ans << std::endl;
    return 0;
}

