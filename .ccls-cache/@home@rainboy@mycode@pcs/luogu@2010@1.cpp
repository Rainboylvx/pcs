#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int s,t;

int mon[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_run(int year){
    if( year % 4 == 0 && year % 100 !=0) return 1;
    if( year % 400 == 0) return 1;
    return 0;
}

struct Time {
    int year,mon,day;
    //year = 2020
    //mon = 3
    //day = 2
};

Time day_add(Time t){
    if( is_run(t.year) ) mon[2]=  29;
    else mon[2] = 28;

    t.day++;
    if( t.day > mon[t.mon] ) {
        t.day = 1;
        t.mon++;
    }
    if( t.mon > 12) t.mon = 1,t.year++;
    return t;
}
//2020 3 02
// 20  02
// 00 00
// 12 21
bool cmp( int a,int b){
    if( a % 10  == b / 10 && a / 10  == b % 10)
        return 1;
    return 0;
}
bool is_hui( Time t){
    int q_year = t.year /100;
    int h_year = t.year %100;
    if( cmp(q_year,t.day) && cmp(h_year,t.mon))
        return 1;
    return 0;
}

int main(){
    cin >> s >> t;
    Time S,T; 
    S.year = s / 10000;
    S.mon = (s % 10000) / 100;
    S.day = s % 100;

    T.year = t / 10000;
    T.mon = (t % 10000) / 100;
    T.day = t % 100;

    int ans=0;

    if( S.day == T.day && S.year == T.year && S.mon ==T.mon ){
        if(is_hui(S))
            cout << 1;
        else 
            cout << 0;
        return 0;
    }
    while( 1 ){
        if( is_hui(S)) ans++;
        S = day_add(S);
        if( S.day == T.day && S.year == T.year && S.mon ==T.mon ) break;
    }
    if( is_hui(T)) ans++;
    cout << ans;

    return 0;
}
