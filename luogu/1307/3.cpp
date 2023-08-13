// 使用数字
#include <bits/stdc++.h>
using namespace std;

int num;

int arr[20]; // arr -> array 数组
int idx; // idx -> index 索引,下标
int main () {
    cin >> num;
    if( num < 0) {
        cout << "-";
        num = -num;
    }

    // num = 123
    while( num != 0 ) {
        int a = num % 10;  // 3
        arr[++idx] = a; //3 2 1
        num /= 10;
    }
    
    bool zero_flag = 0; // flag 旗帜,标记
    for(int i = idx;i >=1;i--) {
        if( arr[i] !=0 ) zero_flag = 1;
        if( zero_flag )
            cout << arr[i];
    }
    return 0;
}
