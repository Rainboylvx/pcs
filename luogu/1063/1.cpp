#include <cstdio>

#define N 200
int n;
int a[N],b[N]; //开头,结尾

int f[N][N] = {0};

//第i 到 第j
int mul(int i,int k,int j){
    return a[i]*b[k]*b[j];
}

//2 3 5 10
//2 3 5 10 2 3 5

int main(){
    scanf("%d",&n);
    int i,j,k;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n] =a[i];
    }


    int t = n;
    n = 2*n-1;

    for (i=1;i<n;i++) b[i] = a[i+1];
    b[n] = a[t];

    for(i=2;i<=t;i++) //长度
        for(j=1;j<=n-i+1;j++){
            for(k=j;k<j+i-1;k++){
                int m  = f[j][k]+f[k+1][j+i-1]+mul(j,k,j+i-1);
                if( f[j][j+i-1] < m)
                     f[j][j+i-1] = m;
            }
        }
    int max = -1;
    for (i=1;i<=t;i++){
        if( max <  f[i][i+t-1])
            max =  f[i][i+t-1];
    }
    printf("%d\n",max);
    return 0;
}


