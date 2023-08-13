#include <iostream>
#include <string>

#ifndef DEBUG
#define log(...)
#else
#include "utils/log.hpp"
#endif

using namespace std;
const int maxn = 1e5+5;
int n,k;
char a[maxn];


string s;
const int inf = 0x5f5f5f5f;
int h_state;
int g_state;

int main() {
    int T;
    cin >> T;

    while(T--) {
        cin >> n >> k;
        cin >> s;
        int pre_h_pos = inf;
        int pre_g_pos = inf;
        h_state = g_state = 0;
        int cnt = 0;
        for(int i = 0;i < n ;++i ) // i: 0->n-1
        {
            char c = s[i];

            //进入这个点,
            //立刻记录最小的,前面的G,H的位置
            if( c == 'G' && g_state == 0)
                pre_g_pos = std::min(pre_g_pos,i);
            if( c == 'H' && h_state == 0)
                pre_h_pos = std::min(pre_h_pos,i);

            //如果需要去种草,不得不种草
            if( i - pre_g_pos == k) { // 现在应该种G
                a[i] = 'G';
                // 一但种下草,从当前点到后面k个位置,的G cow,都不需要G草
                g_state = k+1;
                pre_g_pos = inf;
                cnt++;
            }
            else if( i - pre_h_pos == k) { // 现在应该种H
                a[i] = 'H';
                h_state = k+1;
                pre_h_pos = inf;
                cnt++;
            }
            else { //当前是这个不种草
                a[i] = '.';
            }

            //不需要种
            if( g_state != 0)
            {
                g_state--;
            }
            if( h_state != 0 )
            {
                h_state--;
            }
        }
        //最后可能有没有达到极限的G
        if( pre_g_pos != inf)
        {
            cnt++;
            for(int i =n-1;i>=0;i--)
                if(a[i] == '.'){
                    a[i] = 'G';
                    break;
                }
        }
        //最后可能有没有达到极限的H
        if( pre_h_pos != inf)
        {
            cnt++;
            for(int i =n-1;i>=0;i--)
                if(a[i] == '.'){
                    a[i] = 'H';
                    break;
                }
        }
        cout << cnt << '\n';
        for(int i = 0;i < n ;++i ) // i: 1->n
        {
            cout << a[i];
        }
        cout << '\n';
        log(pre_h_pos);
        log(pre_g_pos);
        // cout << a << '\n';

    }

    return 0;
}
