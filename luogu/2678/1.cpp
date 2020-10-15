#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],l,n,m;
bool check(int dis){//检测答案是否符合题意
    int conut=0,last=0;
    for(int i=1;i<=n;i++){
        if(a[i]-last<dis)conut++;//和前一个的距离小于dis的 就要移走
        else last=a[i];
    }
    if(conut>m)return false;//移动不能超过m次
    else return true;
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int L=0,R=l+1;
    while(L<R){ //二分查找答案   对于每一个答案  检测是否符合题意
        int mid=(L+R)/2;
        if(check(mid)) //找第一个不满足的
            L=mid+1;
        else 
            R=mid;
    }
    printf("%d\n",L-1);
    return 0;
}
