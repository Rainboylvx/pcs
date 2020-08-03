#include <cstdio>

//手动初始化数据
int n=5,c=10;
int w[] = {0,2,2,6,5,4};
int v[] = {0,6,3,5,4,6};

//清空置零,同时前0个物品,边界
int f[11]={0};

void Knapsack01(){
    int i,j;
    for(i=1;i<=n;i++)//前i个物品
        for(j=c;j>=w[i];j--){
            if(f[j] < f[j-w[i]]+v[i])
                f[j] = f[j-w[i]]+v[i];
        }
}
int main(){
    Knapsack01();
    printf("%d",f[10]);//输出答案
    return 0;
}
