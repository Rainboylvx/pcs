#include <bits/stdc++.h>
using namespace std;

char str[105];
int len;

struct node {
    char str[101];
    int cnt;
    bool operator==(const char s[]){
        if( strcmp(s,str) == 0)
            return 1;
        return 0;
    }
    bool operator<(node &b){
        if( strcmp(str,b.str) < 0)
            return 1;
        return 0;
    }
};
vector<node> v;

int main(){
    node t = {"hello",2};
    v.push_back(t);
    auto x = find(v.begin(),v.end(),t.str);
    cout << ( x==v.end()) << endl;
    cout << (x->str) << endl;
    return 0;
}
