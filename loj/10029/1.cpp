/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 16日 星期一 19:52:21 CST
* problem:  loj-10029
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int a,b; //开始,目标状态


void init(){
    int i,j,t;
    char str[10];
    For(i,1,4){
        scanf("%s",str+1);
        For(j,1,4){
            a = (a<<1) | (str[j]-'0');
        }
    }
    For(i,1,4){
        scanf("%s",str+1);
        For(j,1,4){
            b = (b<<1) | (str[j]-'0');
        }
    }
}

/* 交换 a 中的p1 位 和p2 位*/
int bit_swap(int a,int p1,int p2){
    bool t1 = a & (1<<p1); // p1 这个位置是1还是0
    bool t2 = a & (1<<p2); // p2
    if( t1 ) 
        a |= (1<<p2);
    else
        a &= ~(1<<p2);
    if( t2 ) 
        a |= (1<<p1);
    else
        a &= ~(1<<p1);
    return a & 0b1111111111111111;
}
int opts[24][2] = { {11,15}, {10,14}, {9,13}, {8,12}, {7,11}, {6,10}, {5,9}, {4,8}, {3,7}, {2,6}, {1,5}, {0,4}, {14,15}, {13,14}, {12,13}, {11,10}, {10,9}, {9,8}, {7,6}, {6,5}, {5,4}, {3,2}, {2,1}, {1,0} };

/* ======= 全局变量 END =======*/
int _swap(int x,int opt){
    return bit_swap(x, opts[opt][0], opts[opt][1]);
}

struct node { int v,s; };
queue<node> q;
bool vis[0b1111111100000001];


int bfs(){
    if(a == b ) return 0;
    vis[a] = 1;
    q.push({a,0});
    while(!q.empty()){
        node h = q.front();q.pop();

        int i;
        For(i,0,23){
            int t = _swap(h.v,i);
            //{
                //cout << bitset<16> (h.v) << endl;
                //cout << bitset<16> (t) << endl;
            //}
            if(t == b ) return h.s+1;
            if(!vis[t]){
                vis[t] = 1;
                q.push({t,h.s+1});
            }
        }

    }
    return -1;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ans = bfs();
    printf("%d\n",ans);
    //int t = bit_swap(a, 1, 0);
    //cout << bitset<16> (t) <<endl;
    //printf("%d\n",t==b);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
