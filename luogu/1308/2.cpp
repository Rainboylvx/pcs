/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 04日 星期二 10:05:56 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
string word,s;

string s2[int(1e6+5)]; //存文章里的每个单词
int a[int(1e6+5)];// 每个单词开始的位置
int h;
int main(){
    getline(cin,word);
    getline(cin,s);
    int i,j;
    for( i =0;i<word.length();i++) word[i] = tolower(word[i]);
    for( i =0;i<s.length();i++) s[i] = tolower(s[i]);
    string t = "";
    for(i=0;i< s.length();i++){
        if( s[i] == ' ') {
            if( t == "") continue;
            s2[++h] = t;
            a[h] = i-t.length();
            t = "";
        }
        else {
            t += s[i];
        }
    }
    if( t != "") {
        s2[++h] = t;
        a[h] = s.length()-t.length();
    }

    int ans=0,pos;
    for(i=1;i<=h;i++){
        if( s2[i] == word){
            if( ans == 0) pos = a[i];
            ans++;
        }
    }
    if( ans !=0)
        cout << ans << " " << pos;
    else
        cout << -1;


    return 0;
}
