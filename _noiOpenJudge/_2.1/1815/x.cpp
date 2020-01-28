#include <bits/stdc++.h>
using namespace std;
int n=3;
int canvas[10];
int tmp[10];
int max_height;


int bin_count(int x){
    int cnt = 0;
    x &= max_height;
    for( ; x; x = (x-1) &x){
        cnt++;
    }
    return cnt;
}


int main(){
    canvas[1] = 0b101;
    canvas[2] = 0b011;
    canvas[3] = 0b001;
    max_height = (1<<n)-1;

    int i;
    for( i = 0;i<=max_height;i++){
        int cnt=0;
        memcpy(tmp,canvas,sizeof(tmp));
        int x = i;
        int line_1 = tmp[1];
        int line_2 = tmp[2];
        tmp[1] = ((((x<<1)^line_1 ) ^x) ^(x>>1) ) & max_height;
        tmp[2] = (line_2 ^x) & max_height;
        cnt += bin_count(i);

        /* 第二行 */
        int opt = 0;

        int j;
        for(j=0;j<n;j++){
            opt <<= 1;
            if( ( (1<<j) & tmp[1]) == 0 ){
                opt |= 1;
            }
        }
        opt &= max_height;
        cnt += bin_count(opt);

        x = opt;
        tmp[2] = ((((x<<1)^tmp[1]) ^x) ^(x>>1) ) & max_height;
        tmp[3] = (tmp[2]^ opt) & max_height;

        opt = 0;
        for(j=0;j<n;j++){
            opt <<= 1;
            if( ( (1<<j) & tmp[2]) == 0 ){
                opt |= 1;
            }
        }
        opt &= max_height;

        x = opt;
        tmp[3] = ((((x<<1)^tmp[2]) ^x) ^(x>>1) ) & max_height;

        cnt += bin_count(opt);
        if( tmp[3] == max_height){
            printf("%d %d\n",cnt,i);
        }


    }
    return 0;
}
