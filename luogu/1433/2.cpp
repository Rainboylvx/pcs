#include<iostream>//这个就不用解释了吧 
#include<cmath>//sqrt的头文件 
#include<cstring>//初始化函数 memset的头文件 
#include<cstdio>//用printf输出比较方便（详细看后面） 
double ans=1111111111;//存答案 
double now=0;//存现在的路程 
int n;//同题意 
bool book[20];//用于记录 
double ax[20];//存储奶酪的x轴的坐标 
double ay[20];//存储奶酪的y轴的坐标 
void dfs(int dq,int d);//dq代表 
double jl[20][20];//记忆化搜索的存储 
using namespace std;
int main(){
    memset(book,false,sizeof book);//初始化book 
    memset(jl,0,sizeof jl);//初始化jl 
    cin>>n;
    if(n==0){//对n等于0特判 
        cout<<0.00;
        return 0;//完美结束 
    }
    for(int i=1;i<=n;i+=1){//读入数据 
        cin>>ax[i];
        cin>>ay[i];
    }
    ax[0]=0;//初始化老鼠的坐标 
    ay[0]=0; 
    book[0]=true;//记录一开始的位置已经走过 
    dfs(0,0);//深搜开始 
    printf("%0.2lf",ans);//这就是用printf的好处：%0.2lf表示保留两位小数输出double型变量。 
    return 0;//完美结束 
}
void dfs(int dq,int d){
    if(now>ans)//这是剪枝，如果当前的路程大于答案就跳出 
    return;
    if(dq==n){//如果吃完了所有奶酪，就判断路程有没有小于答案 
        if(now<=ans){
            ans=now;
        }
        return;//跳出 
    }
    for(int i=1;i<=n;i+=1){//枚举所有的奶酪 
        if(book[i]==false){//如果没有被吃掉就从这个点再开始深搜 
            if(jl[d][i]!=0){//用到了记忆化搜索，这个奶酪到下一个奶酪如果之前又走过就把之前的值拿过来用 
                book[i]=true;//标记这个奶酪已经被吃掉 
                now+=jl[d][i];//路程累加 
                dfs(dq+1,i);//从这个点再开始深搜 
                book[i]=false;//归位 
                now-=jl[d][i];//归位
            }
            else if(jl[i][d]!=0){//同上面，只不过方向不一样 
                book[i]=true;
                now+=jl[i][d];
                dfs(dq+1,i);
                book[i]=false;
                now-=jl[i][d];
            }
            else{//如果没有走过就只能乖乖算了 
                book[i]=true;//标记这个奶酪已经被吃掉 
                jl[i][d]=sqrt((ax[i]-ax[d])*(ax[i]-ax[d])+(ay[i]-ay[d])*(ay[i]-ay[d]));//记录下来这个奶酪到下一个奶酪距离的值 
                now+=jl[i][d];//路程累加 
                dfs(dq+1,i);//从这个点再开始深搜 
                book[i]=false;//归位 
                now-=jl[i][d];//归位
            }
        }
    }
    return;//返回 
}
