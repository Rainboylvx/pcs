#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> sta;
int n,r;
vector<char> _map;


void get_div_mod(int a,int b,int &div,int &mod){
    if( a >=0){
        div = a / b;
        mod = a % b;
    }
    else {
        if( a % b == 0){
            div = a / b;
            mod = 0;
        }
        else {
            div = a / b;
            if( div < 0)
                div--;
            else if (div >0)
                div++;
            else if( b > 0 )
                div--;
            else if (b < 0)
                div++;
            mod = a - (div*b);
        }
    }
}

int main(){
    int i;

    for(i=0;i<=9;i++)
        _map.push_back('0'+i);
    for(i='A';i<='Z';i++)
        _map.push_back(i);


    scanf("%d%d",&n,&r);
    printf("%d=",n);

    int div,mod;
    do {
        get_div_mod(n,r,div,mod);
        sta.push_back(mod);
        n = div;
    }while( div !=0);
    int size = (int)sta.size();
    for(i=size-1;i>=0;i--)
        printf("%c",_map[sta[i]]);
    printf("(base%d)",r);

    return 0;
}
