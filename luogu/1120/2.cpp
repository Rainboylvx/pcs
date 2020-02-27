#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0; bool f=1; char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=0;
    for(; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    if(f) return x;
    return 0-x;
}
int n,m,a[66],_next[66],cnt,sum,len;
bool used[66],ok; //used数组即优化5的vis数组，记录每根木棍是否用过；ok记录是否已找到答案。 
bool cmp(int a,int b){return a>b;}
void dfs(int k,int last,int rest){ //k为正在拼的木棍的编号，last为正在拼的木棍的前一节编号，rest为该木棍还未拼的长度
    int i;
    if(!rest){ //未拼的长度为0，说明这根原始长棍拼完了，准备拼下一个 
        if(k==m){ok=1; return;} //优化6，全部拼完并符合要求，找到答案，直接返回 

        for(i=1;i<=cnt;i++) //找一个还没用的最长的木棍打头即可。反正要想全都拼接成功，每根木棍都得用上 
            if(!used[i]) break;
        used[i]=1; 
        dfs(k+1,i,len-a[i]);
        used[i]=0;
        if(ok) return; //优化6，找到答案就退出 
    }
    //优化4，二分找第一个 木棍长度不大于未拼长度rest 的位置 
    int l=last+1, r=cnt, mid;
    while(l<r){
        mid=(l+r)>>1;
        if(a[mid]<=rest) r=mid;
        else l=mid+1;
    }
    for(i=l;i<=cnt;i++){
        if(!used[i]){ //优化5，判断木棍是否用过 
            used[i]=1;
            dfs(k,i,rest-a[i]);
            used[i]=0;
            if(ok) return; //优化6，找到答案就退出 

            if(rest==a[i] || rest==len) return; //优化7 
            i=_next[i]; //优化3 
            if(i==cnt) return;
        }
    }
    //到了这里，说明这时候拼不成当前这根原始木棍了，传回失败信息并修改之前拼的木棍 
}
int main(){
    n=read();
    int d;
    for(int i=1;i<=n;i++){
        d=read();
        if(d>50) continue;
        a[++cnt]=d;
        sum+=d;
    }
    sort(a+1,a+cnt+1,cmp); //优化1，木棍按长度从大到小排序 
    //优化3，预处理_next数组 
    _next[cnt]=cnt;
    for(int i=cnt-1;i>0;i--){
        if(a[i]==a[i+1]) _next[i]=_next[i+1];
        else _next[i]=i;
    }
    for(len=a[1];len<=sum/2;len++){ //枚举原始长度 
        if(sum%len!=0) continue; //如果不能拼出整数根 就跳过 
        m=sum/len; //优化6中的那个计算 
        ok=0;
        used[1]=1;
        dfs(1,1,len-a[1]);
        used[1]=0;
        if(ok){printf("%d\n",len); return 0;} //优化6，输出答案，退 
    }
    printf("%d\n",sum); return 0;
}
