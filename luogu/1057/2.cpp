#include <set>
#include <iostream>
#include <string>
using namespace std;

set<string> s;
int n,m;
char step[100];
int ans = 0;
void dfs(int dep,int pre){
    if(dep == m+1){
        if( pre == 1){
            string tmp;;
            int i;
            for(i=1;i<dep;i++) tmp+=step[i];
            if( s.count(tmp) == 0){
                //cout << tmp << endl;
                ans++;
                s.insert(tmp);
            }
        }

        return;
    }
    
    step[dep] = pre+'0';
    dfs(dep+1,pre+1 > n ? 1 : pre+1);
    dfs(dep+1,pre-1 < 1 ? n : pre-1);
}


int main(){
    scanf("%d %d",&n,&m);
    dfs(1,1);
    printf("%d\n",ans);

    return 0;
}


