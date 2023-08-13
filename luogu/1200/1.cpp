#include <bits/stdc++.h>
using namespace std;

char a[100]; //彗星名
char b[100]; // 队伍的名字

int main () {
    cin >> a; //读取彗星的名字
    cin >> b; //读取了队伍的名字

    // 分别得到对应的长度
    int lena = strlen(a);
    int lenb = strlen(b);

    int numa=1,numb = 1; //存mod的值
    for(int i =0;i<lena ;i++) {
        numa *= a[i] - 'A' +1;
        numa %= 47;
    }
    for(int i =0;i<lenb ;i++) {
        numb *= b[i] - 'A' +1;
        numb %=47;
    }
    if( numa % 47 == numb % 47)
        cout << "GO";
    else
        cout << "STAY";

    return 0;
}
