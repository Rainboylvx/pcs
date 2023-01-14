// 增加 ()的处处理
// 读取到 ( 那么就是一个整体的表达式
// ( 的运行符号优先级是 -1
// 读取到 ) 表示要返回了,一个表达式要读取完了
//
// t3 在t2的基础上优化
#include <bits/stdc++.h>
#include "graphviz.hpp"
using namespace std;

string _expression;

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

    int idx = mytoken.idx;

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
        //得到了一个完整的表达式,tree
    }
    else if( token == ')'){
        // 什么也不做
        tree = pre_tree;
        return tree;
    }

    //没有下一个token时
    if( !hash_next_token)  return tree;

    //下一个运算符没有比上一个运算符 高, 左结合
    char next_token = mytoken.next_token();


    //表明这个表达式是括号内的内容
    if( pre_opt == '(' && next_token == ')') {
        // return work(tree, pre_opt);
        mytoken.next(); //过滤掉 )
        return tree;
    }
    if (operator_priority(next_token) <= operator_priority(pre_opt))
        return tree;
    //和下一个运算符号结合
    return work(tree,pre_opt);
}

//创建一个树
DOT::graphviz<> dot_tree;

//输出树,先序
void first_traver(int id)
{
    using namespace DOT;
    auto &node = tree_nodes[id];

    auto &dotNode = dot_tree.addNode(id);

    if (is_opt(node.c))
    {
        dotNode.set<dot_attrs::label>(node.c);
        std::cout << node.c << "\n";
    }
    else
    {
        std::cout << node.c << "\n";
        dotNode.set<dot_attrs::label>(node.c);
        // dotNode.set<dot_attrs::label>("123");
    }
    if (node.right != -1)
    {
        dot_tree.addEdge(dotNode, (std::size_t)node.left);
        first_traver(node.right);
    }
    if (node.left != -1)
    {
        dot_tree.addEdge(dotNode, node.right);
        first_traver(node.left);
    }
}

int main()
{
    cin >> _expression;
    cout << _expression << endl; 
    int root = -1;
    while( mytoken.has_next_token() ) {
        root = work(root, 0);
    }
    first_traver(root);
    std::cout << dot_tree.to_dot()
              << "\n";
    dot_tree.output();

    return 0;
}
