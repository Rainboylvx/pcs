#include <cstdio>
#include <string>
using namespace std;

long long n,m;

const int maxn = 2005;
int f[maxn][maxn];
int sum[maxn][maxn];
// n 长度,pos 大小
string dfs(int n,long long pos){
    string s;
    int i;
    if( pos == 1){
        for( i =1;i<=n/2;i++) s.push_back('(');
        for( i =n/2+1;i<=n;i++) s.push_back(')');
        return s;
    }
    for(i=n/2;i>=1;i--){
        if( pos > f[n][i]) pos -= f[n][i];
        else {
            string ret = dfs(n-2,pos);
            return string(ret.begin(),ret.begin()+i-1)
                +"()"
                +string(ret.begin()+i-1,ret.end());
        }
    }
    return "";
}

int main(){
    f[2][1] = f[2][0] = 1; //边界
    sum[2][1] = sum[2][0] = 1;
    scanf("%lld%lld",&n,&m);
    if(m == 1){
        int i;
        for( i =1;i<=n/2;i++) printf("(");
        for( i =n/2+1;i<=n;i++) printf(")");
        printf("\n");
        return 0;
    }
    int i,j;
    for( i =4;i<=n;i+=2){
        f[i][i/2] = sum[i][i/2] = 1;
        for( j = i/2-1;j>=1;j--){
            f[i][j] =  sum[i-2][j-1];
            sum[i][j] =  f[i][j] + sum[i][j+1];
        }
        sum[i][0] = sum[i][1];
    }
    //printf("%d\n",sum[4][0]);
    //printf("%d\n",sum[n][0]);
    string ans = dfs(n,m);
    printf("%s\n",ans.c_str());
    //答案输出
    return 0;
}

