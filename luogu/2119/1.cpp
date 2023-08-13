#include <cstdio>
#include <cstring>


#define maxn 15005
#define maxm 40005

int val[maxm]; // 第m个物品的数值
int num[maxn] = {0};  //数值为i的物品出现的次数

//va[i]  数值为i的 物品作为a 出现的次数
int va[maxn]={0}, vb[maxn]={0}, vc[maxn]={0}, vd[maxn]={0};

int n,m;

void init(){
    scanf("%d%d",&n,&m);
    int i,j,k;
    int t;
    for (i=1;i<=m;i++){
       scanf("%d",&t);
       val[i] = t;
       num[t]++;        //统计
    }
}

int main(){

    init();
    //开始计算/枚举
    int t,a,b,c,d;
    int sum=0;
    for(t=1;t*9<n;t++){ //枚举t 最小的a=1,所以t最大要为t*9+1 <=n
        sum = 0;
        for(d=t*9+2;d<=n;d++){  //最小的a=1,所以d最少要为t*9+2
            
            a = d-9*t-1;
            b = d-7*t-1;
            c = d-t;
            sum += num[a] * num[b]; // if num[a] == 0 表示没有,那么就sum +=0

            vd[d] += num[c] * sum;
            vc[c] += num[d] * sum;
        }

        // 同样的道理 去枚举a, 要倒过来枚举
        sum = 0;
        for(a= n-t*9-1;a>=1;a--){ //a+t*9+1 <=n
            b = a+2*t;
            c = a+8*t+1;
            d = a+9*t+1;
            sum += num[c]*num[d];

            va[a] += num[b] * sum;
            vb[b] += num[a] *sum;
        }

    }

    int i;
    for(i=1;i<=m;i++){
        int &tt = val[i];
        printf("%d %d %d %d\n",va[tt],vb[tt],vc[tt],vd[tt]);
    }
    return 0;
}

