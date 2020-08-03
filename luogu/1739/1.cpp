#include <cstdio>
#include <stack>

#include <cstring>
using namespace std;

char str[1000];
stack<char> s;
int main(){
    scanf("%s",str+1);
    int i;
    int len = strlen(str+1);
    bool match = 1;
    for(i=1;i<=len;i++){
        char c = str[i];
        if( c == '(')
            s.push(c);
        else if ( c == ')'){
            if( s.empty() ){
                printf("NO");
                return 0;
            }
            s.pop();
        }
        else if ( c == '@')
            break;
    }

    if( s.empty()) {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}

