#include <bits/stdc++.h>
using namespace std;


int main(){
    int a,b;
    cin >> a >> b;
    auto lambda_func = [=]()->int{ 
        return a+b;
    };
    
    cout << lambda_func();
    return 0;
}
