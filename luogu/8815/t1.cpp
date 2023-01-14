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

bool is_opt(char c) { return c == '|' || c == '&'; }
bool is_num(char c) { return c == '0' || c == '1'; }

int work(int pre_tree, char pre_opt)
{
    mytoken.next();
    char token = mytoken.current_token();
    if (is_num(token))
    {
        int tree = get_tree_node();
        tree_nodes[tree].c = token;
        if (!mytoken.has_next_token())
            return tree;
        char next_token = mytoken.next_token();
        if (operator_priority(next_token) <=
            operator_priority(pre_opt))
            return tree;

        return work(tree, pre_opt);
    }
    else if (is_opt(token))
    {
        int tree = get_tree_node();
        tree_nodes[tree].c = token;
        tree_nodes[tree].left = pre_tree;
        tree_nodes[tree].right = work(pre_tree, token);
        int next_token = mytoken.next_token();
        if (operator_priority(next_token) <=
            operator_priority(pre_opt))
            return tree;
        return work(tree, pre_opt);
    }
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
    int root = work(-1, 0);
    first_traver(root);
    std::cout << dot_tree.to_dot()
              << "\n";
    dot_tree.output();

    return 0;
}
