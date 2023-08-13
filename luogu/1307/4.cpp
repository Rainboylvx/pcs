// 使用字符串
#include <bits/stdc++.h>
using namespace std;


char num[20];
int len;

int main () {
    cin >> num;
    len = strlen(num);
    int start;
    if( num[0] == '-'){
        cout << "-";
        start = 1;
    }
    else {
        start = 0;
    }
    bool zero_flag = 0;
    for(int i = start;i < len;i++){
        if( num[i] != '0') zero_flag = 1;
        if( zero_flag)
            cout << num[i];
    }
    return 0;
}
