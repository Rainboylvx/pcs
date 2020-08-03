#include<cstdio>
#include<algorithm>
using namespace std;
int e[12],n,k;
struct person{
    int w;//权值 
    int num;//编号 
    int d;//类别 
}p[20010];//储存每个人的信息 
int w_comp(const person &a,const person &b){
    if(a.w!=b.w)return a.w>b.w;//从大到小排序 
    return a.num<b.num;//序号小优先 
}//结构体排序 
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<10;i++)scanf("%d",&e[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].w);
        p[i].num=i+1;
    }//读入+编号 
    sort(p,p+n,w_comp);//第一次排序 
    for(int i=0;i<n;i++){
        p[i].d=i%10;//分类 
        p[i].w+=e[p[i].d];//加上e[i] 
    }
    sort(p,p+n,w_comp);//第二次排序 
    for(int i=0;i<k;i++)printf("%d ",p[i].num);
}
