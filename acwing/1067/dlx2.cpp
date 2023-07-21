// DLX_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int N = 510;


/*
   3 3
   0 1 0
   0 0 1
   1 0 0

   1 2 3

   4 4
   0 0 0 1
   1 0 0 0
   1 1 0 1
   0 1 0 0

   No Solution!
   */


struct DLX_NODE {
    struct DLX_NODE* up;
    struct DLX_NODE* down;
    struct DLX_NODE* left;
    struct DLX_NODE* right;
    int row; int col;
    int count;
    int ele;

    DLX_NODE() {
        up = NULL; down = NULL; left = NULL; right = NULL;
        col = -1; row = -1; ele = -1; count = 0;
    }
};

struct DLX_NODE table[N][N];

int n, m;

void init()
{
    for (int i = 0; i < n; i++) {
        table[i][0].down = &table[i + 1][0];
        table[i + 1][0].up = &table[i][0];
        table[i][0].row = i; table[i][0].col = 0;
        table[i + 1][0].row = i + 1; table[i + 1][0].col = 0;
    }

    for (int i = 0; i < m; i++) {
        table[0][i].right = &table[0][i + 1];
        table[0][i + 1].left = &table[0][i];
        table[0][i].row = 0; table[0][i].col = i;
        table[0][i+1].row = 0; table[0][i+1].col = i+1;
    }


}

void printDLX()
{
    struct DLX_NODE* p = &table[0][0];
    cout << "=================================================>\n";
    p = p->right;
    while (p != NULL) {
        struct DLX_NODE* pp = p;
        if (pp->count != 0) {
            cout << "colBase.count = " << pp->count << endl;
        }
        while (pp != NULL) {
            if (pp->ele == 1)
                cout << "pp->col = " << pp->col << ". pp->row = " << pp->row << ".pp->ele = " << pp->ele << endl;
            pp = pp->down;
        }
        p = p->right;
    }
    cout << endl << endl;
    p = &table[0][0];
    p = p->down;
    while (p != NULL) {
        struct DLX_NODE* pp = p;
        while (pp != NULL) {
            if (pp->ele == 1)
                cout << "pp->col = " << pp->col << ". pp>row = " << pp->row << ".pp->ele = " << pp->ele << endl;
            pp = pp->right;
        }
        p = p->down;
    }
    cout << endl ;
}



void FindColInsert(int row,int col)
{
    struct DLX_NODE* p = &table[0][col];
    while (p != NULL) {
        struct DLX_NODE* next = p->down;
        //找到链表结尾或者 next比当前元素行数更大 P的下面即是插入的位置
        if (next == NULL)  break;
        else if (next->row > row) break;
        else if (next->row == row) {
            //行列都相同则说明重复插入了
            assert(0);
        }
        p = next;
    }
    assert(p != NULL);
    //插入
    struct DLX_NODE* node = &table[row][col];
    node->down = p->down;
    if (p->down != NULL) p->down->up = node;

    node->up = p;
    p->down = node;

    table[0][col].count++;
}


void FindRowInsert(int row, int col)
{
    struct DLX_NODE* p = &table[row][0];
    while (p != NULL) {
        struct DLX_NODE* next = p->right;
        //找到链表结尾或者 next比当前元素列数更大 P的右面即是插入的位置
        if (next == NULL)  break;
        else if (next->col > col) break;
        else if (next->col == col) {
            //行列都相同则说明重复插入了
            assert(0);
        }
        p = next;
    }
    assert(p != NULL);
    //插入
    struct DLX_NODE* node = &table[row][col];
    node->right = p->right;
    if (p->right != NULL) p->right->left = node;

    node->left = p;
    p->right = node;
}

void addNode(int num, int x, int y)
{
    table[x][y].row = x;
    table[x][y].col = y;
    table[x][y].ele = num;

    //插入列中
    FindColInsert(x,y);

    //插入行中
    FindRowInsert(x,y);
}

void resume(struct DLX_NODE* pToResume)
{
    struct DLX_NODE* pdown = pToResume->down;
    while (pdown != NULL) {
        int row = pdown->row;
        assert(row != -1);
        struct DLX_NODE* nextResume = &table[row][0];
        while (nextResume != NULL) {
            if (nextResume->col > 0)
                table[0][nextResume->col].count++;
            nextResume->up->down = nextResume;
            if (nextResume->down != NULL) nextResume->down->up = nextResume;
            nextResume = nextResume->right;
        }
        pdown = pdown->down;
    }


    if (pToResume->right != NULL) pToResume->right->left = pToResume;
    pToResume->left->right = pToResume;


}

void remove(struct DLX_NODE* pToRemove)
{
    if (pToRemove->right != NULL) { pToRemove->right->left = pToRemove->left; } // <-[]->

    pToRemove->left->right = pToRemove->right;// <-[]->

    struct DLX_NODE* pdown = pToRemove->down;
    while (pdown != NULL) {
        int row = pdown->row; // 这一行,行数
        assert(row != -1);
        struct DLX_NODE* nextRemove = &table[row][0]; // 取得这一行的头
        while (nextRemove != NULL) {
            if(nextRemove->col != 0)
                table[0][nextRemove->col].count--;// 列头 count--
            assert(table[0][nextRemove->col].count >= 0);
            if (nextRemove->col == pToRemove->col) { // 是同一列
                nextRemove = nextRemove->right; // 下一列
                continue;// 跳过下面
            }
            if (nextRemove->down != NULL) nextRemove->down->up = nextRemove->up;
            nextRemove->up->down = nextRemove->down;// 这个点 <-上下->
            nextRemove = nextRemove->right;
        }
        pdown = pdown->down; // 再下一行
    }
}

vector<int> ans;
bool dfs()
{
    int noEle = 1;  int minCount = 99999; struct DLX_NODE* selectP = NULL;
    struct DLX_NODE* p = table[0][0].right; // 二维的表头
    if (p == NULL) 
        return true; // 空表
    while (p != NULL) { // 找到这一列1的数量最少的
        if (p->count != -1 && p->count < minCount) {
            minCount = p->count;
            selectP = p; // 这一列的开头的指针
        }
        p = p->right;
    }


    remove(selectP); //删除这一列
    {
        p = selectP->down; // 向下找
        while (p != NULL) {
            ans.push_back(p->row); //存 选一行
            struct DLX_NODE* tmp = table[p->row][0].right; // tmp 是这一行的开头
            while (tmp != NULL) { // 这一行不空
                if(tmp->col != selectP->col) // 这个列,都
                    remove(&table[0][tmp->col]); //还有删除
                tmp = tmp->right;
            }
            if (dfs()) return true; // 删除空了就成功了

            tmp = table[p->row][0].right; // 恢复现场
            while (tmp != NULL) {
                if (tmp->col != selectP->col)
                    resume(&table[0][tmp->col]); // 还有恢复
                tmp = tmp->right;
            }
            ans.pop_back();// 退出栈内的答案,
            p = p->down; // 选下一行
        }
    }

    resume(selectP);//恢复这一列

    return false;
}



int main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            if (x) {
                addNode(x, i, j);
            }
        }
    }
    printDLX();
    if (dfs())
    {
        for(auto& e:ans)  
            printf("%d ", e);
        puts("");
    }
    else puts("No Solution!");



    return 0;
}

