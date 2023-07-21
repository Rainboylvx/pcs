#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f

int L;
int s,t,m;
int a[105];

/*  一个长度为11的,循环使用的数组*/
int f[12];

void get_value(int x){
    int i,tmp=inf;
    for(i=s;i<=t;i++){
        int pre= x - i;
        if( pre <= 0)
            pre += 11;
        tmp = min( f[pre],tmp);
    }
    f[x] = tmp;
}

/* 所有的值都一样,且不是inf */
bool check(){
    int i;
    for (i=2;i<=11;i++){
        if( f[i] == inf || f[i] != f[i-1])
            return false;
    }
    return true;
}


void init(){
    memset(f,0x3f,sizeof(f));
    scanf("%d%d%d%d",&L,&s,&t,&m);
    int i;
    for (i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+m);
}

void dp(){
    f[0] = 0;
    int idx= 1; //石子的下标
    int i,j;
    /* 手动计算前11个位置 */
    for (i=1;i<=11;i++){
        for(j=s;j<=t;j++){
            int pre = i-j;
            if( pre < 0)
                f[i] = inf;
            else
                f[i] = min(f[i],f[pre]);
        }

        if( a[idx] == i){ //当前这个点是不是有石子
            if( f[i] != inf)
                f[i]++;
            idx++;
        }
    }

    int now = 0;
    for(i=12;i<=L+10;i++){
        now++;
        if( now>11) now = 1;
        get_value(now);

        if( a[idx] == i){ //当前这个点是不是有石子
            if( f[now] != inf)
                f[now]++;
            idx++;
        }


        if ( check()){ //满足条件
            now = 0;
            i = a[idx]-1; //因为 i++

            //是不是所有的石子都选完了
            if(idx == m+1)
                break;
        }

    }
}

int main(){
    init();

    /* 特殊判断 */
    if(s == t){
        int ans = 0;

        int i;
        for (i=1;i<=m;i++){
            if( a[i] % s == 0)
                ans++;
        }
        printf("%d\n",ans);

        return 0;
    }


    dp();
    int i;
    int ans = inf;
    for (i=1;i<=11;i++){
        ans = min(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}

