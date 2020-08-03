#include <cstdio>
using namespace std;

int n,sum;
//以下所有数组的大小都比所需值稍大，是为了防止越界
int visited[25]={0}; //防止重复选数，这是 dfs 枚举排列的要点
int ans[25]; //放置答案
int pc[25];//构造所有i C n-1

int dfs(int i,int num,int v); //写函数原型是（我的）好习惯！

int main(void){
    scanf("%d%d",&n,&sum);
    //下面构造杨辉三角(即组合数表)
    pc[0]=pc[n-1]=1; //杨辉三角性质,两边都是1
    if (n>1)
        for (int i=1;i*2<n;i++)
            pc[i]=pc[n-1-i]=(n-i)*pc[i-1]/i; //利用杨辉三角对称性和组合数公式计算
    //下面枚举计算
    if (dfs(0,0,0)) //0 仅起占位符作用
        for (int i=1;i<=n;i++)
            printf("%d ",ans[i]); //输出答案
    return 0;
}

int dfs(int i,int num,int v){
//参数说明：i 表示已经枚举了前 i 个数(数的序号从 1 开始),num 表示第 i 个数是 num，v 表示前 i 个数的“和”为 v
//返回值说明:返回 0 表示不行(不可能)，返回 1 表示找到了可行解。利用返回值就可以在找到第一个解后直接返回了
    if (v>sum) //“剪枝”，及时排除不可能情况，加速枚举
        return 0; //不可能
    if (i==n){ //已经枚举了前 n 个（全部）,判断一下是否是可行解
        if (v==sum){
            ans[i]=num; //放置解
            return 1;
        }
        else
            return 0;
    }
    visited[num]=1; //标记一下“第 i 个数的值已经使用过了”
    //下面寻找第 i+1 个数
    for (int j=1;j<=n;j++){
        if (!visited[j] && dfs(i+1,j,v+pc[i]*j)){ //v+pc[i]*j表示前(i+1)个数的“和”
            //注意，如果数的序号从 1 开始，那么第 i 个数的系数实际上是 (i-1) C (n-1)
            //执行到这里表示已经找到了可行的解
            ans[i]=num;
            return 1;
        }
    }
    visited[num]=0; //如果没有找到，一定记得复位，为进一步的寻找做准备
    return 0; //执行到这里一定是没有找到解
}
