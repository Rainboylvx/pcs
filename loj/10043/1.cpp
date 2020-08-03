#include <cstdio>
#include <cstring>

const int kmp_max_len = 1e5;
int pre_end = -1;
struct KMP{
    int la,lb;
    char a[kmp_max_len],b[kmp_max_len];
    int next[kmp_max_len];
    int cnt =0; //匹配字符串的数量
    bool init(){
        cnt = 0;
        scanf("%s",a+1);
        scanf("%s",b+1);
        la = strlen(a+1);
        lb = strlen(b+1);
        if( a[1] == '#' && la == 1) return 0;
        pre_end = -1;
        return 1;
    }

    void deal_next(){
        int i,j=0;
        next[1] = 0;
        for(i=2;i<=lb;++i){
            while(j && b[j+1] != b[i])  j = next[j];
            if( b[j+1] == b[i]) j++;
            next[i] = j;
        }
    }
    void kmp(){
        int i,j=0;
        for(i=1;i<=la;++i){
            while(j && b[j+1] != a[i]) j = next[j];
            if( b[j+1] == a[i]) j++;
            if( j == lb){ 
                //printf("%d\n",i-lb+1); 
                int st = i-lb+1;
                if(pre_end < st){
                    pre_end = i;
                    cnt++;
                }
                j=next[j];
            }
        }
    }
};

KMP kmp;


int main(){
    while(1){
        if( !kmp.init()) break;
        kmp.deal_next();
        kmp.kmp();
        printf("%d\n",kmp.cnt);
    }
    return 0;
}

