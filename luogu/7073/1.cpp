/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 07月 11日 星期一 10:36:31 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,q;
/* 定义全局变量 */

string s;

struct node {
    int a;
    char b;
    bool num;
};
std::vector<node> v;
bool a[100005];

bool sta[100];
int head = 0;
void push(bool x){ sta[head++] = x;}
bool pop(){
    bool x = sta[head-1];
    --head;
    return  x;
}

bool calc() {
    for(int i = 0;i < v.size();i++){
        if(v[i].num){
            push(a[v[i].a]);
        }
        else if( v[i].b == '&'){
            bool t1 = pop();
            bool t2 = pop();
            push(t2 && t1);
        }
        else if( v[i].b == '|'){
            bool t1 = pop();
            bool t2 = pop();
            push(t2 || t1);
        }
        else if( v[i].b == '!'){
            bool t1 = pop();
            push(! t1);
        }
    }
    return pop();
}


int main(int argc,char * argv[]){
    getline(cin, s);
    s.push_back(' ');
    int num = 0;
    for(int i = 0;i < s.length();i++){
        if(s[i] == 'x') {
            num = 0;
            continue;
        }
        else if(s[i] >='0' && s[i] <='9') {
            num = num*10 + s[i]-'0';
        }
        else if(s[i] == ' ') {
            if(s[i-1] >='0' && s[i-1] <='9')
                v.push_back({num,' ',true});
            else
                v.push_back({0,s[i-1],false});
        }
    }

    //for (const auto& e : v) {
        //if( e.num )
            //std::cout << e.a << std::endl;
        //else
            //std::cout << e.b << std::endl;
    //}

    cin >> n;
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        a[i] = t;
    }
    std::cin >> q;
    for(int i=1;i<=q;++i){
        int t;
        cin >> t;
        bool org = a[t];
        a[t] = !a[t];
        std::cout << calc() << std::endl;
        a[t] = org;
    }


    return 0;
}


