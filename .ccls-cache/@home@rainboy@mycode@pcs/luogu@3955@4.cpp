/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 01日 星期六 10:22:43 CST */
#include <bits/stdc++.h>
using namespace std;

struct a{
    static const int npos = 123;
    int opt(){
        return 1;
    }
};



int main(){
    cout << a::npos << endl;
    cout << a::opt() << endl;

    return 0;
}
