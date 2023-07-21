# include<iostream>
# include<cstring>
# include<algorithm>
using namespace std;
struct p{
    int t,h,l;
}c[101];
int d,g;
int ti[101];
int f[101];
bool cmp(p a,p b)
{
    return a.t<b.t;
}
int main()
{
    cin>>d>>g;
    for(int i=1;i<=g;i++)
      cin>>c[i].t>>c[i].l>>c[i].h;
    sort(c+1,c+1+g,cmp);
    f[0]=10;
    for(int i=1;i<=g;i++)
      for(int j=d;j>=0;j--)
        if(f[j]>=c[i].t)
        {
            if(j+c[i].h>=d)
            {
                cout<<c[i].t;
                return 0;
            }
            f[j+c[i].h]=max(f[j+c[i].h],f[j]);
            f[j]+=c[i].l;
        }
    cout<<f[0];
    return 0;
}
