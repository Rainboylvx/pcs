#include <bits/stdc++.h>
using namespace std;


bool check(int z,int q,int s,int l){
    if( 
            (z+q == s+l) &&
            (z+l > s+q) &&
            (z+s<q)
            )
        return 1;
    return 0;
}

struct node {
    char c;
    int val;
    bool operator<(node &b){
        return val < b.val;
    }
};
node _list[5];


int main(){
    int i,j,k,l;
    int n = 50;
    for(i=10;i<=n;i+=10){          //zhao
        for(j=1;j<=n;j+=10){      //qian
            for(k=1;k<=n;k+=10){ // sun
                for(l=1;l<=n;l+=10){ //li
                    if( check(i,j,k,l)){
                        _list[1] = {'z',i};
                        _list[2] = {'q',j};
                        _list[3] = {'s',k};
                        _list[4] = {'l',l};
                        sort(_list+1,_list+4+1);
                        int x;
                        for(x=1;x<=4;x++){
                            printf("%c %d\n",_list[x].c,_list[x].val);
                        }
                        


                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
