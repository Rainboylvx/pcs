/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 04日 星期五 22:13:27 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int k;
/* 定义全局变量 */
vector<int> v;
priority_queue<int, vector<int>, greater<int> > pq;
list<int> l;
typedef list<int>::iterator LIT;

LIT first_find(LIT it){
    while(1){
        LIT now = it;
        it++;
        if( *now < *it) return now;
    }
}

int main(){
    pq.push(1);
    for(int i=1;i<=30000;++i){
        int a = pq.top()*2+1;
        int b = pq.top()*4+5;
        v.push_back(pq.top());
        pq.pop();
        pq.push(a);
        pq.push(b);
    }
    scanf("%d%d",&k,&m);
    for(int i=0;i<=k-1;++i){
        printf("%d",v[i]);
        string s = to_string(v[i]);
        for(int j=0;j<=s.size()-1;++j){
            l.push_back(s[j]-'0');
        }
    }
    printf("\n");

    l.push_front(10);
    l.push_back(10);

    LIT b = l.begin();
    for(int i=1;i<=m;++i){
        b = first_find(b);
        b = l.erase(b);
        b--;
    }
    l.pop_back();
    l.pop_front();
    if( l.size() == 0){
        cout << 0;
    }
    else {
        for(LIT i = l.begin(); i != l.end();i++){
            cout << *i;
        }
    }
    return 0;
}
