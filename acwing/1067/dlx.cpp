#include <iostream>
const int N  = 501;
int n,m;
int l[N],r[N],u[N],d[N]; // l[i] i点的左边编号
int s[N]; // ? cnt i列有点的数量
int row[N],col[N]; // i 所在行与列
int idx; //编号 

int ans[N],top; //栈

//初始化
void init()
{
    // 设置第一行
    for (int i = 0; i <= m; i ++ ) // m列
    {
        l[i] = i - 1, r[i] = i + 1;// 设置每个点的左右
        u[i] = d[i] = i; // 上和下,循环链表
    }
    l[0] = m, r[m] = 0; // 循环链表
    idx = m + 1; //使用了m+1个点
}


// 添加
// 添加一个点,这个点在x,y位置,
void add(int &hh,int &tt ,int x,int y) {
    row[idx] = x,col[idx] = y,s[y]++; // x,y,cnt
    u[idx] = y ,d[idx] =d[y];

    r[hh] = l[tt] = idx, r[idx] = tt ,l[idx] = hh;
    tt = idx++;
}

int main(){
    
    return 0;
}
