#include <cstdio>

#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)

int n,m;
int tot;
bool p[105];

int main(){
    scanf("%d%d",&n,&m);
    tot  = n;

    int i;
    int cnt = 0;
    while( tot  !=0 ){
        for(i=1;i<=n;i++){
            if( !p[i]){
                cnt++;

                if(cnt == m){
                    printf("%d ",i);
                    tot--;
                    if(!tot ) return 0;
                    p[i]= 1;
                    cnt = 0;
                }
            }
        }
    }

    return 0;
}


