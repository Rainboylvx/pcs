#include<iostream>
using namespace std;
int ma[1050][1050]={0};
int main()
{
    int d,n;
    cin>>d>>n;
    int maxn=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=0;j<1025;j++){
            for(int k=0;k<1025;k++){
                int shang=j-d,xia=j+d,zuo=k-d,you=k+d;
                if(a>=shang&&a<=xia&&b>=zuo&&b<=you){
                    ma[j][k]+=c;
                    if(ma[j][k]>maxn) maxn=ma[j][k];
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<1025;i++){
        for(int j=0;j<1025;j++)
            if(ma[i][j]==maxn) cnt++;
    }
    cout<<cnt<<" "<<maxn;
    return 0;
}
