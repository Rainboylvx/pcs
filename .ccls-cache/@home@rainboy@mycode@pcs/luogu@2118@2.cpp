#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	int a,b,L;
	cin>>a>>b>>L;
	int ansi,ansj;
	double t1=a*1.0/b;
	double t3=9999999;
	for(int i=1;i<=L;i++){
		for(int j=1;j<=L;i++){
			if(gcd(i,j)!=1)continue;
			double t2=i*1.0/j;
			if(t2>=t1){
				if(t3>t2-t1){
					t3=t2-t1;
					ansi=i;ansj=j;
				}
			}
		}
	}
	cout<<ansi<<" "<<ansj;
	return 0;
}
