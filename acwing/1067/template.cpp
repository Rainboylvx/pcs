#include <iostream>
#include <cassert>

const int N = 100;

struct dlx_node {
    using p = dlx_node *;
    p up,down,left,right;
    int row,col; //这个点所在的行与列
    int count; // ?
    int ele; // ?

    dlx_node() 
        : up{nullptr}, down{nullptr}, left{nullptr}, right{nullptr},
        col{-1}, row{-1}, ele{-1}, count{0}
    { }

    void set_row_col(int x,int y) {
        row = x,col = y;
    }
};

int n,m; //n和 m列
dlx_node table[N][N];

void init() {
    for(int i=1;i<=n;++i){
        auto & now_head = table[i][0];
        auto & next_head = table[i+1][0];
        now_head.down = &next_head;//第i行的首元素指向下一行
        next_head.up = &now_head;

        now_head.set_row_col(i, 0);
        next_head.set_row_col(i, 0);
    }

    for(int i=1;i<=m;++i){
        auto & col = table[0][i];
        auto &next_col = table[0][i+1];

        col.right= &next_col;
        next_col.left = &col;

        col.set_row_col(0, i);
        next_col.set_row_col(0, i+1);
    }
}

//添加一个元素
void addNode(int num,int x,int y) {

}


//恢复
void resume(dlx_node * p) {

}

void remove(dlx_node * pToRemove)
{
    if (pToRemove->right != NULL) { pToRemove->right->left = pToRemove->left; }
    pToRemove->left->right = pToRemove->right;

    struct dlx_node* pdown = pToRemove->down;
    while (pdown != NULL) {
        int row = pdown->row;
        assert(row != -1);
        struct dlx_node* nextRemove = &table[row][0];
        while (nextRemove != NULL) {
            if(nextRemove->col != 0)
                table[0][nextRemove->col].count--;
            assert(table[0][nextRemove->col].count >= 0);
            if (nextRemove->col == pToRemove->col) {
                nextRemove = nextRemove->right;
                continue;
            }
            if (nextRemove->down != NULL) nextRemove->down->up = nextRemove->up;
            nextRemove->up->down = nextRemove->down;
            nextRemove = nextRemove->right;
        }
        pdown = pdown->down;
    }
}



int main(){
    
    return 0;
}
