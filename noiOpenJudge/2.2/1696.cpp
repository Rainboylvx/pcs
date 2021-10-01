#include <cstdio>
#include <cstdlib>
#include <cstring>

#define maxn 105

int idx = 1;
char a[maxn][maxn];

bool isOpt(char t){
    if( t == '*' || t == '-' || t == '+' || t == '/' )
        return true;
    return false;
}

double getResult(char opt,double a,double b){
    if( opt == '+')
        return a+b;
    if( opt == '*')
        return a*b;
    if( opt == '-')
        return a-b;
    return a /b;
}


int head=1;
double calc(){
    char t = a[head][0];
    head++;
    if( isOpt(t)){
        double t1,t2;

        t1 = calc();
        t2 = calc();
        return getResult(t,t1,t2);
    }

    return atof(&a[head-1][0]);
    
}

int main(){
    //EOF end of file  
    while( scanf("%s",&a[idx][0])!=EOF ){ // end of file
        idx++;
    }//1 2 3 4 5
    //int i;
    double ans = calc();
    printf("%f\n",ans);
    return 0;
}
