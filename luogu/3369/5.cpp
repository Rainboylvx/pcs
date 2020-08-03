#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 1000000
int f[MAXN],cnt[MAXN],value[MAXN],sons[MAXN][2],sub_size[MAXN],whole_size,root;                 
inline int qread(){
    int res=0,k=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')k=-1;
        c=getchar();
    }
    while(isdigit(c)){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return res*k;
}
inline void S_Clear(int x){
    sons[x][0]=sons[x][1]=f[x]=sub_size[x]=cnt[x]=value[x]=0; 
}
inline bool get_which(int x){
    return sons[f[x]][1]==x;
}
inline void update(int x){
    if (x){  
        sub_size[x]=cnt[x];  
        if (sons[x][0]) sub_size[x]+=sub_size[sons[x][0]];  
        if (sons[x][1]) sub_size[x]+=sub_size[sons[x][1]];  
    }  
    return ;
}
inline void rotate(int x){
    int father=f[x],g_father=f[father],which_son=get_which(x);
    sons[father][which_son]=sons[x][which_son^1];
    f[sons[father][which_son]]=father;
    sons[x][which_son^1]=father;
    f[father]=x;
    f[x]=g_father;
    if(g_father){
        sons[g_father][sons[g_father][1]==father]=x;
    }
    update(father);
    update(x);
}
inline void splay(int x){
    for (int fa;fa=f[x];rotate(x))  
      if (f[fa])  
        rotate((get_which(x)==get_which(fa))?fa:x);  
    root=x;  
}
inline void insert(int x){
    if(!root){
        whole_size++;
        sons[whole_size][0]=sons[whole_size][1]=f[whole_size]=0;
        root=whole_size;
        sub_size[whole_size]=cnt[whole_size]++;
        value[whole_size]=x;
        return ;
    } 
    int now=root,fa=0;
    while(1){
        if(x==value[now]){
            cnt[now]++;
            update(now);
            update(fa);
            splay(now);
            break;
        }
        fa=now;
        now=sons[now][value[now]<x];
        if(!now){
            whole_size++;
            sons[whole_size][0]=sons[whole_size][1]=0;
            f[whole_size]=fa;
            sub_size[whole_size]=cnt[whole_size]=1;
            sons[fa][value[fa]<x]=whole_size;
            value[whole_size]=x;
            update(fa);
            splay(whole_size);
            break; 
        }
    }

}
inline int find_num(int x){ 
    int now=root;
    while(1){
        if(sons[now][0]&&x<=sub_size[sons[now][0]])
        now=sons[now][0];
        else {
            int temp=(sons[now][0]?sub_size[sons[now][0]]:0)+cnt[now];
            if(x<=temp)return value[now];
            x-=temp;
            now=sons[now][1];
        }
    }
}

inline int find_rank(int x){
      int now=root,ans=0;  
    while(1){  
        if (x<value[now])  
          now=sons[now][0];  
        else{  
            ans+=(sons[now][0]?sub_size[sons[now][0]]:0);  
            if (x==value[now]){  
                splay(now); return ans+1;  
            }  
            ans+=cnt[now];  
            now=sons[now][1];  
        }  
    }  
}
inline int find_pre(){
    int now=sons[root][0];
    while(sons[now][1])now=sons[now][1];
    return now;
}
inline int find_suffix(){
    int now=sons[root][1];
    while(sons[now][0])now=sons[now][0];
    return now;
}
inline void my_delete(int x){
    int hhh=find_rank(x);
    if (cnt[root]>1){
    cnt[root]--; 
    update(root); 
    return;
    }  
    if (!sons[root][0]&&!sons[root][1]) {
    S_Clear(root);
    root=0;
    return;
    }  
    if (!sons[root][0]){  
        int old_root=root; 
        root=sons[root][1];
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    }  

    else if (!sons[root][1]){  
        int old_root=root; 
        root=sons[root][0]; 
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    } 
    int left_max=find_pre(),old_root=root;  
    splay(left_max);  
    sons[root][1]=sons[old_root][1];  
    f[sons[old_root][1]]=root;  
    S_Clear(old_root);  
    update(root);  
}

int main(){

    clock_t program_start_clock = clock(); //开始记时
    int m,num,be_dealt;
    cin>>m;
    for(int i=1;i<=m;i++){
       num=qread();
       be_dealt=qread();
        switch(num)
        {
            case 1:insert(be_dealt);break;
            case 2:my_delete(be_dealt);break;
            case 3:printf("%d\n",find_rank(be_dealt));break;
            case 4:printf("%d\n",find_num(be_dealt));break;
            case 5:insert(be_dealt);printf("%d\n",value[find_pre()]);my_delete(be_dealt);break;
            case 6:insert(be_dealt);printf("%d\n",value[find_suffix()]);my_delete(be_dealt);break;
        }
    }
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
