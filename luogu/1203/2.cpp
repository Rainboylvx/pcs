#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=800;

int gi(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}//读入优化 

char bead[N];//记录珍珠 
bool gett[N];//标记珍珠是否被取 
int n;
inline void marked(int x){
    if(x<n) gett[x]=gett[x+n]=1;
    else gett[x]=gett[x-n]=1;
}//标记珍珠函数（记得被复制的一份也要标记） 

/*取珍珠函数，x为断链点的左边一个珍珠的位置，返回从这儿最多能取多少个珍珠*/ 
int gb(int x){
    memset(gett,0,sizeof(gett));    //重置标记 
    int cnt=1;    //记录拿到了多少个珍珠 
    /*首先，从x开始往左边取的代码*/ 
    char sta=bead[x];    //第一个珍珠，标准珍珠 
    marked(x);    //记得标记quq 
    for(int i=x-1;i>=0;i--){
        if(gett[i])break;
        if(bead[i]==sta||bead[i]=='w')cnt++;    //如果比较的这个珍珠颜色相同（包括了w==w的情况），或者要取的珍珠可以被染色 
        else if(sta=='w')sta=bead[i],cnt++;        //如果颜色不同而且标准珍珠可被染色 
        /*如果标准珍珠为w，那么会有两种情况。
        1.连续取的珍珠都是w。那么不用管，继续往下取。
        2.取到某个珍珠不是w。那么按照贪心原则，我们必须给w染色，染成什么颜色呢？肯定染成与这个珍珠相同的颜色。
        否则这个珍珠就取不了了，不符合贪心原则.-.
        染过色之后色彩当然就改不了了，不过这已经是最佳方案了。
        所以综上所述：遇到第一个不与标准珍珠w相等的珍珠，把标准珍珠的颜色换成这个珍珠的颜色。
        代码实现如此。*/ 
        else break;
        marked(i);
    }
    /*接着，从x+1开始往右边取的代码*/ 
    if(!gett[x+1])cnt++;    //请注意因为是环，所以开始往右取的时候第一个标准珍珠有可能已经被标记。此时得特判。 
    sta=bead[x+1]; marked(x+1);
    //如果标准珍珠早就被取，那么下面一段根本不会进行。 
    for(int i=x+2;i<2*n;i++){
        if(gett[i])break;
        if(bead[i]==sta||bead[i]=='w')cnt++;
        else if(sta=='w')sta=bead[i],cnt++;
        else break;
        marked(i);
    }
    return cnt;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>bead[i];
        bead[i+n]=bead[i];    //断环成链 
    }
    int ans=0;
    for(int i=1;i<2*n-1;i++) {
        ans=max(ans,gb(i));    //枚举断链点取珍珠，取最大值 
        if( ans == 74)
        {
            cout << "74 " << i << endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
