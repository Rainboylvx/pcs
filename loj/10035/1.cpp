#include <cstdio>
#include <cstring>

const int kmp_max_len = 1e6+5;
struct KMP{
    int la,lb;
    char a[kmp_max_len],b[kmp_max_len];
    int next[kmp_max_len];
    int cnt =0; //匹配字符串的数量
    bool init(){
        cnt = 0;
        scanf("%s",b+1);
        lb = strlen(b+1);
        if( b[1] == '.' && lb == 1) return 0;
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
    int ans(){
        if(lb % ( lb-next[lb]) !=0) return 1;
        return lb / ( lb-next[lb]) ;
    }
    void kmp(){
        int i,j=0;
        for(i=1;i<=la;++i){
            while(j && b[j+1] != a[i]) j = next[j];
            if( b[j+1] == a[i]) j++;
            if( j == lb){ 
                //printf("%d\n",i-lb+1); 
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
        printf("%d\n",kmp.ans());
    }
    return 0;
}

