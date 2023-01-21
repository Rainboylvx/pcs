#include <bits/stdc++.h>
using namespace std;


int main(){
    string a = "01234";
    cout << a << endl;
    string b("01234");
    cout << b << endl;
    //
    string c(a);
    cout << c << endl;

    string d(a,1);
    cout << d << endl;

    string e(a,1,100);
    cout << e << endl;


    return 0;
}
