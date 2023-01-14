// 在t3.cpp的基础上增加树的遍历时进行运算
#include <bits/stdc++.h>
// #include "graphviz.hpp"
using namespace std;

string _expression;
bool ans; //结果
int cnt1,cnt2; // 短路”各出现了多少次

int operator_priority(char opt)
{
    if (opt == '|')
        return 1;
    if (opt == '&')
        return 2;
    return -1;
}

struct __token
{
    int idx = -1;
    char current_token()
    { // 当前的token
        return _expression[idx];
    }
    char next_token()
    {
        return _expression[idx + 1];
    }
    bool has_next_token()
    {
        return idx + 1 < _expression.length();
    }
    void next() { idx++; }
};

__token mytoken;

// node 节点
struct node
{
    char c; // opt ,number
    int left = -1, right = -1;
};
node tree_nodes[1000000 + 50];
int idx = 0;
int get_tree_node() { return idx++; }

//得到一个新的单个数值的tree
int get_new_tree(char c,int left = -1,int right = -1) {
    int tree = get_tree_node();
    tree_nodes[tree].c = c;
    tree_nodes[tree].left = left;
    tree_nodes[tree].right = right;
    return tree;
}

bool is_opt(char c) { return c == '|' || c == '&'; }
bool is_num(char c) { return c == '0' || c == '1'; }

int work(int pre_tree, char pre_opt)
{
    mytoken.next();
    char token = mytoken.current_token();
    bool hash_next_token = mytoken.has_next_token();

    //如果是0 / 1
    int tree = -1;
    if (is_num(token))
    {
        //定义一个新的tree
        tree =get_new_tree(token);
    }
    else if (is_opt(token))
    {
        //这个树的左孩子是 上一个表达式
        tree  = get_new_tree(token,pre_tree);
        tree_nodes[tree].right = work(-1,token);
    }
    else if( token == '(') { // ( 括号
        tree = work(-1,token);
    }
    else if( token == ')'){
        // 什么也不做
        tree = pre_tree;
    }

    //没有下一个token时
    if( !hash_next_token)  return tree;


    int next_token = mytoken.next_token();

    //表明这是一个括号内的表达式
    if( pre_opt == '(' && next_token == ')') {
        // return work(tree, pre_opt);
        mytoken.next(); //过滤掉 )
        return tree;
    }
    //下一个运算符没有比上一个运算符 高, 左结合
    if (operator_priority(next_token) <= operator_priority(pre_opt))
        return tree;
    //和下一个运算符号结合
    return work(tree,pre_opt);
}

//创建一个树

//先序遍历树
bool first_traver(int id)
{
    auto &node = tree_nodes[id];


    if (is_num(node.c))
        // std::cout << node.c << "\n";
    {
        return node.c == '0' ? 0 : 1;
    }
    else
    {
        bool ret = first_traver(node.left); //遍历左子树
        if( ret == 0 && node.c == '&'){
            cnt1++;
            return 0;
        }

        if( ret ==1 && node.c == '|'){
            cnt2++;
            return 1;
        }

        bool ret2 = first_traver(node.right);

        if( node.c == '|')
            return ret || ret2;
        else
            return ret && ret2;
    }

}

int main()
{
    cin >> _expression;
    // cout << _expression << endl; 
    int root = -1;
    while( mytoken.has_next_token() ) {
        root = work(root, 0);
    }
    // first_traver(root);
    // std::cout << dot_tree.to_dot()
    //           << "\n";
    // dot_tree.output();
    cout << first_traver(root) << "\n";
    cout << cnt1 << " " << cnt2;

    return 0;
}
