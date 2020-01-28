#include<bits/stdc++.h>
using namespace std;
int number=0;
int a[8][8]={0};
void hape(int i,int q)
{
    int cont=0;
    a[i][q]=1;
    i++;
    if(i==8)
    {
        number++;
        cout<<"No. "<<number<<endl;
        for(int x=0;x<8;x++)
            for(int y=0;y<8;y++)
            {
                cout<<a[y][x]<<" ";
                if(y==7)cout<<endl;
                if(y==7&&x==7)return;
            }
    }
    for(int j=0;j<8;j++)
    {cont=0;
        for(int m=0;m<8;m++)
            for(int n=0;n<8;n++)
            {
                if(a[m][j]||a[i][n]||(a[m][n]&&m-n==i-j)||(a[m][n]&&m+n==i+j))
                    cont++;
            }
        if(cont==0)
        {hape(i,j);
            a[i][j]=0;}
    }
}
int main()
{
    for(int z=0;z<8;z++)
    {hape(0,z);
        fill(a[0],a[0]+8*8,0);}
    return 0;
}
