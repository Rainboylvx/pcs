#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
const int MAXN=100010;
using namespace std;
long long hi[MAXN];
long long disa[MAXN],disb[MAXN];
long long disab[36][MAXN],disaa[36][MAXN],disbb[36][MAXN];
int stab[36][MAXN];int sta[MAXN],stb[MAXN];
int n,q;
struct da{
    long long he;
    int id;
}date[MAXN];

set<long long> s;
set<long long>::iterator it,it2;
 
bool comp(da x,da y){
    return x.he<y.he;
}

void cl(){
    memset(disaa,0,sizeof(disaa));
    memset(disbb,0,sizeof(disbb));
    memset(disab,0,sizeof(disab));
    memset(stab,0,sizeof(stab));
    memset(sta,0,sizeof(sta));
    memset(stb,0,sizeof(stb));
    memset(disa,0,sizeof(disa));
    memset(disb,0,sizeof(disb));
}
 
int main(){
    cl();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) cin>>hi[i];
    for(int i=1;i<=n;i++) date[i].id=i,date[i].he=hi[i];
    sort(date+1,date+n+1,comp);
    for(int i=n;i>=1;i--){
        long long minn=100000000000000000,minn2=100000000000000000,he1=100000000000000000,he2=100000000000000000;
        s.insert(hi[i]);
        it=s.find(hi[i]);
        if(it!=s.begin()){
            it--;
            long long diss=abs(hi[i]-*it),gao=*it;
            if(diss<minn||(diss==minn&&gao<he1)) swap(gao,he1),swap(minn,diss);
            if((diss>minn&&diss<minn2)||(diss==minn&&gao>he1)) he2=gao,minn2=diss;
        }
        if(it!=s.begin()){
            it--;
            long long diss=abs(hi[i]-*it),gao=*it;
            if(diss<minn||(diss==minn&&gao<he1)) swap(gao,he1),swap(minn,diss);
            if((diss>minn&&diss<minn2)||(diss==minn&&gao>he1)) he2=gao,minn2=diss;
        }
        it=s.find(hi[i]);it2=s.end();
        it++;
        if(it!=it2){
            long long diss=abs(hi[i]-*it),gao=*it;
            if(diss<minn||(diss==minn&&gao<he1)) swap(gao,he1),swap(minn,diss);
            if((diss>minn&&diss<minn2)||(diss==minn&&gao>he1)) he2=gao,minn2=diss;
        }
        if(it!=it2){
            it++;
            if(it!=it2){
                long long diss=abs(hi[i]-*it),gao=*it;
                if(diss<minn||(diss==minn&&gao<he1)) swap(gao,he1),swap(minn,diss);
                if((diss>minn&&diss<minn2)||(diss==minn&&gao>he1)) he2=gao,minn2=diss;
            }
        }
        if(minn==100000000000000000) disb[i]=0;
        else disb[i]=minn;
        if(minn2==100000000000000000) disa[i]=0;
        else disa[i]=minn2;
        int ans=0,l=1,r=n,mid;
        while(l<=r){mid=(l+r)/2;if(date[mid].he>=he1) ans=date[mid].id,r=mid-1;else l=mid+1;}
        if(ans==0) stb[i]=0;
        else stb[i]=ans;
        ans=0,l=1,r=n;
        while(l<=r){mid=(l+r)/2;if(date[mid].he>=he2) ans=date[mid].id,r=mid-1;else l=mid+1;}
        if(ans==0) sta[i]=0;
        else sta[i]=ans;
    }
    int i;
    for(i=1;i<=n;i++){
        printf("%lld \n",disa[i]);
    }
    for(i=1;i<=n;i++){
        printf("%lld \n",disb[i]);
    }
    for(int i=1;i<=n;i++){
        if(!disa[i]||!disb[sta[i]]) continue;
        disab[0][i]=disa[i]+disb[sta[i]];
        disaa[0][i]=disa[i],disbb[0][i]=disb[sta[i]];
        stab[0][i]=stb[sta[i]];
    }
    for(int j=1;j<=35;j++){
        for(int i=1;i<=n;i++){
            if(!disab[j-1][i]||!disab[j-1][stab[j-1][i]]) continue;
            disab[j][i]=disab[j-1][i]+disab[j-1][stab[j-1][i]];
            disaa[j][i]=disaa[j-1][i]+disaa[j-1][stab[j-1][i]];
            disbb[j][i]=disbb[j-1][i]+disbb[j-1][stab[j-1][i]];
            stab[j][i]=stab[j-1][stab[j-1][i]];
        }
    }
    int x0,ans=0;
    double minn=1<<30;scanf("%d",&x0);
    for(int i=1;i<=n;i++){
        int tota=0,totb=0,tot=0,now=i;
        for(int j=35;j>=0;j--){
            if(stab[j][now]&&tot+disab[j][now]<=x0) 
            tot+=disab[j][now],tota+=disaa[j][now],totb+=disbb[j][now],now=stab[j][now]; 
        }
        if(sta[now]&&tot+disa[now]<=x0) tot+=disa[now],tota+=disa[now],now=sta[now];
        double zhi=double(tota)/double(totb);
        if(minn>zhi) minn=zhi,ans=i;
    }
    printf("%d\n",ans);
    //scanf("%d",&q);
    //for(int i=1;i<=q;i++){
        //int star,x;
        //scanf("%d%d",&star,&x);
        //int tota=0,totb=0,tot=0,now=star;
        //for(int j=35;j>=0;j--){
            //if(stab[j][now]&&tot+disab[j][now]<=x) 
            //tot+=disab[j][now],tota+=disaa[j][now],totb+=disbb[j][now],now=stab[j][now]; 
        //}
        //if(sta[now]&&tot+disa[now]<=x) tot+=disa[now],tota+=disa[now],now=sta[now];
        //printf("%d %d\n",tota,totb);
    //}
    return 0;
}
