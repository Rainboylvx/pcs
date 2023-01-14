#include <iostream>
int n,m;
int r,s;

int a[105][105];
int b[105][105];

void init(){
    std::cin >> n >> m;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            std::cin >> a[i][j];
        }
    }
    std::cin >> r >> s;
    for(int i=1;i<=r;++i){
        for(int j=1;j<=s;++j){
            std::cin >> b[i][j];
        }
    }
}

int myabs(int a){
    return a > 0 ? a : -a;
}

//从x,y开始的子矩阵 与 b矩阵计算的结果
int calc(int x,int y){
    int sum=0;
    for(int i =1 ;i<=r ;i++){
        for(int j = 1;j <=s ;j++){
            int _a = a[x+i-1][y+j-1];
            int _b = b[i][j];
            sum += myabs(_a-_b);
        }
    }
    return sum;
}


int main(){
    //step 1
    init();
    //step 2
    //枚举 子矩阵的起点
    // x [1,m-r+1]
    // y [1,n-s+1]
    int mm = 9999999;
    int x,y;
    for(int i =1;i <=m-r+1;i++){
        for(int j=1;j<=n-s+1;++j){
            //std::cout << i <<" "<< j << std::endl;
            int ans = calc(i,j);
            if( mm > ans){
                mm = ans;
                x = i;
                y = j;
            }
        }
    }

    for(int i =1 ;i<=r ;i++){
        for(int j = 1;j <=s ;j++){
            int _a = a[x+i-1][y+j-1];
            std::cout << _a <<" ";
        }
        std::cout  << std::endl;
    }


    return 0;
}
