#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,q;
int a[500010];
struct node{
    int l;
    int r;
    int sum;
    int minsum;//从l开始的最小前缀和(1,2->1,3->-1)
    int k;
    int change;//操作等价于先走k级祖先然后再走等价0/1串(左->0,右->1) 
    int len;//总操作长 
    int point;//如果走到根节点则最终会走到哪 
    node operator +(const node &x)const{
        node ret;
        ret.l=l;
        ret.r=x.r;
        ret.sum=sum+x.sum;
        if(sum+x.minsum<minsum){
            ret.minsum=sum+x.minsum;
            ret.point=x.point;
        }
        else{
            ret.minsum=minsum;
            ret.point=(((point>>x.k)<<x.len)|x.change);
        }
        if(x.k>len){
            int tok=k+x.k-len;
            ret.k=tok;
            ret.change=x.change;
            ret.len=x.len;
        }
        else{
            int tolen=len-x.k;
            int tochange=(change>>x.k);
            tochange=((tochange<<x.len)|x.change);
            tolen+=x.len;
            ret.len=tolen;
            ret.change=tochange;
            ret.k=k;
        }
        return ret;
    }
}tree[2000010];
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    if(l==r){
        if(a[l]==1){
            tree[now].minsum=tree[now].sum=1;
            tree[now].len=1;
            tree[now].k=0;
            tree[now].change=0;
            tree[now].point=1;
        }
        else if(a[l]==2){
            tree[now].minsum=tree[now].sum=1;
            tree[now].len=1;
            tree[now].k=0;
            tree[now].change=1;
            tree[now].point=1;
        }
        else{
            tree[now].minsum=tree[now].sum=-1;
            tree[now].len=0;
            tree[now].k=1;
            tree[now].change=0;
            tree[now].point=1;
        }
        return;
    }
    int mid=(l+r)/2;
    build(now*2,l,mid);
    build(now*2+1,mid+1,r);
    tree[now]=tree[now*2]+tree[now*2+1];
//  cout<<"#"<<l<<" "<<r<<endl;
//  cout<<tree[now].point<<" "<<tree[now].change<<endl;
}
void change(int now,int x){
    int l=tree[now].l;
    int r=tree[now].r;
    if(l==r&&l==x){
        if(a[x]==1){
            tree[now].minsum=tree[now].sum=1;
            tree[now].len=1;
            tree[now].k=0;
            tree[now].change=0;
        }
        else if(a[x]==2){
            tree[now].minsum=tree[now].sum=1;
            tree[now].len=1;
            tree[now].k=0;
            tree[now].change=1;
        }
        else{
            tree[now].minsum=tree[now].sum=-1;
            tree[now].len=0;
            tree[now].k=1;
            tree[now].change=0;
        }
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid){
        change(now*2,x);
    }
    else{
        change(now*2+1,x);
    }
    tree[now]=tree[now*2]+tree[now*2+1];
}
node query(int now,int x,int y){
    int l=tree[now].l;
    int r=tree[now].r;
    if(l==x&&r==y){
        return tree[now];
    }
    int mid=(l+r)/2;
    if(y<=mid){
        return query(now*2,x,y);
    }
    else if(x>mid){
        return query(now*2+1,x,y);
    }
    else{
        return query(now*2,x,mid)+query(now*2+1,mid+1,y);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,m); //建立线段树
    while(q--){
        int opt;
        scanf("%d",&opt);
        if(opt==1){
            int s,l,r;
            scanf("%d%d%d",&s,&l,&r);
            node now=query(1,l,r);
            int deep=0;
            for(int i=0;i<=30;i++){
                if((s>>i)&1)deep=i;
            }
            if(now.minsum<=-deep){
                printf("%d\n",now.point);
            }
            else{
                printf("%d\n",((s>>now.k)<<now.len)|now.change);
            }
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
            change(1,x);
        }
    }
    return 0;
}
