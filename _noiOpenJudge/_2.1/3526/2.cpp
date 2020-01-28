#include<bits/stdc++.h>
using namespace std;
int hz(int n,int c)
{
    for (int i=2;i<=min(n,c);++i) if (n%i==0&&c%i==0) return 0;
    return 1;
}
int a[1001],b,c,sum=0;
int main()
{
    cin>>b;
    for (int i=1;i<=b;++i) cin>>a[i];
    sort(a+1,a+b+1);
    for (int i=1;i<=b;++i)
        for(int j=i+1;j<=b;++j)
        {
            if (a[j]>a[i]&&hz(a[i],a[j])) {
                printf("%d %d\n",a[i],a[j]);
                sum++;
            }
        }
    cout<<sum;
}
