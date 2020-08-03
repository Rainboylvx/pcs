#include <cstdio>
#include <string>
#include <iostream>

#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)

using namespace std;
int n;
int line = 2;
string s[5000] = {"/\\","/__\\",""};

string _blank(int cnt){
    int i;string s;
    For(i,1,cnt){
        s += " ";
    }
    return s;
}

void _copy(){
    int size = s[line-1].size();
    int i,cnt = 0;
    for(i=size-2;i>=0;i -= 2){
        s[line++] = s[cnt] + _blank(i) + s[cnt];
        cnt++;
    }
}

int main(){
    scanf("%d",&n);
    int i;
    for(i = 1 ;i< n;i ++)
        _copy();
    For(i,0,line-1){
        cout << _blank(line-i-1);
        cout << s[i] << endl;
    }
    return 0;
}


