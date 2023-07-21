#include <iostream>
#include "utils/graphviz.hpp"
int n;
using namespace DOT;

graphviz mygh;

void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int t;
            std::cin >> t;
            if( i == j) continue;

            dot_node & n1 = mygh.addNode(i-1);
            dot_node & n2 = mygh.addNode(j-1);
            dot_edge &e = mygh.addEdge(n1, n2);
            e.set<DOT::dot_attrs::label>(t);
        }
    }
}

int main(){
    init();
    std::cout << mygh.to_dot() << "\n";
    return 0;
}
