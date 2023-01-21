/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 01日 星期六 09:48:25 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,q;
string book[1005];

bool cmp( string a,string b){
    if( a.length() < b.length())
        return true;
    else if( a.length() == b.length())
        return a <b;
    return false;
}

int main(){
    cin >> n >> q;
    int i,j;
    for(i=1;i<=n;++i)
        cin >> book[i];
    sort(book+1,book+n+1,cmp);
    //book+1 == &book[1]
    //[l ,r)

    int len;
    string t;
    for(i=1;i<=q;++i){
        cin >> len;
        cin >> t;
        int idx = -1;
        for(j=1;j<=n;j++)
            if( book[j].length() >= len){
                string st(book[j],book[j].length()-len);
                //cout << st << " " << t << endl;
                if( st == t){
                    cout << book[j] << endl;
                    idx = j;
                    break;
                }
            }
        if( idx == -1)
            cout << idx << endl;
    }

    return 0;
}
