#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


vector<string> opt_seq;
vector<string> num_seq;

double num[10];
char t1[5];

//+++abcd
//++ab+cd
//+a+b+cd

char str_calc[][100] = {
    "+++1234",
    "++12+34",
    "+1+2+34",
    "+1++234"
};

char opt[]="0+-*/";

void gen_opt_seq(int dep){
    if( dep == 4){
        opt_seq.push_back(string(t1+1,t1+4));
        return ;
    }
    int i;
    for(i=1;i<=4;i++){
        t1[dep] = opt[i];
        gen_opt_seq(dep+1);
    }
}

void gen_num_seq(){
}



int main(){
    gen_opt_seq(1);
    for( auto i :opt_seq)
        cout << i << endl;
    return 0;
}

