#include <iostream>
#include <cmath>
using namespace std;

int p;

int a[505]; //记录后面的500位置
int len=1;

int main(){
    std::cin >> p;
    a[1] = 1; //表示 2^0 = 1
    len = 1;
    for(int i =1;i<=p;i++)
    {

        //单精 x 高精度
        int jin = 0;
        for(int j = 1;j<=len;j++) {
            a[j] *= 2;
            a[j] += jin;
            jin = a[j] / 10;
            a[j] %= 10;
        }
        a[len+1] = jin;
        if(a[len+1] != 0)
            len++;
        if( len > 500)
            len = 500;
    }

    a[1] -=1;
    //输出这500位的数字
    // for(int i = len;i>=1;i--)
    //     std::cout << a[i];
    // std::cout<< "\n";
    // return 0;
    double t  = p * log10(2);
    int ans = t;
    if( ans * 1.0 < t)
        ans ++;
    std::cout << ans << "\n";
    for(int i =1;i<=10;i++){
        for(int j = 1;j<=50;j++) { //输出每一行的10个数字
            int pos = 500-((i-1) *50 + j)+1;
            cout << a[pos] ;
        }
        std::cout << "\n";
    }
    return 0;
}


