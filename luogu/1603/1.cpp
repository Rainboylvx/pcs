#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

string num1[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
string num2_str[] = { "a", "both", "another", "first", "second", "third" };
int num2_num[] = {1,2,1,1,2,3};

map<string,int> m;

vector<int> v;
vector<string> v2;

void init(){
    int i,j;
    for(i=0;i<20;++i){
        m[num1[i]] = i+1;
    }
    int len = sizeof(num2_num)/sizeof(num2_num[0]);
    for(i=0;i<=len-1;++i){
        m[num2_str[i]] = num2_num[i];
    }
    string s;
    for(i=1;i<=5;++i){
        cin >> s;
        if( m[s]) v.push_back(m[s]);
    }
    cin >> s;
    if( s.back() == '.') s.pop_back();
    if( m[s]) v.push_back(m[s]);
}

string int2str(int a){
    a = (a*a) % 100;
    string s;
    s.push_back((a/10)+'0');
    s.push_back((a%10)+'0');
    return s;
}

int main(){
    init();
    if( v.size() == 0){
        cout << 0;
        return 0;
    }
    for (const auto& e : v) {
        v2.push_back(int2str(e));
    }
    sort(v2.begin(),v2.end());
    string s;
    for (const auto& e : v2) {
        s+=e;
    }
    int i=0,len = s.length();
    while( i  < len){
        if( s[i] !='0') break;
        i++;
    }
    if( i == len) {
        cout << 0; return 0;
    }
    for(;i <len;i++)
        cout << s[i];
    return 0;
}
