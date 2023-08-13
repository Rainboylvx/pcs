/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-21 20:25:25
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
// #include "base.hpp"
#include "data_structure/queue.hpp"
// #include "chips/piece.hpp"
// #include "math/fraction.hpp" // 分数类
// #include "graph/linkList.hpp"
// #include "chips/range.hpp"

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp" 
#endif

//==== 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)

//====== 全局变量 =======

int n,m,root;
// int a[maxn];
int que_idx[maxn]; //每个人对应的队列的编号

queue<int> queque; //队列的队列,按顺序,记录每个队伍的编号
bool in_queue[maxn]; // 队伍i是否在 queque 中

queue<int,1001> que[1001]; //每个队伍

//====== 全局变量 =======


//====== 函数与类 =======


//====== 函数与类 =======


char str[20];

void init() {
    memset(in_queue,0,sizeof(in_queue));
    scanf("%d",&n);
    F(n){
        scanf("%d",&m);
        FF( j , m ){
            int t;
            scanf("%d",&t);
            que_idx[t] = i;
        }
    }
    F(1000){
        que[i].clear();
    }
    queque.clear();

}

int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    int idx =0;
    while(1) {
        init();
        if(n == 0 ) break;
        printf("Scenario #%d\n",++idx);
        while(1){
            scanf("%s",str);
            if(str[0] == 'E')
            {
                int t;
                scanf("%d",&t);
                if( !in_queue[que_idx[t]] ){
                    queque.push(que_idx[t]);
                    in_queue[que_idx[t]] = 1;
                }
                que[que_idx[t]].push(t);
            }
            else if(str[0] == 'D')
            {
                int h = queque.front();
                int t = que[h].front();
                que[h].pop_front();
                if( que[h].empty()) {
                    queque.pop_front();
                    in_queue[h] = 0;
                }
                printf("%d\n",t);
            }
            else if (str[0] == 'S')
                break;
        }
        printf("\n");
    }

    return 0;
}
