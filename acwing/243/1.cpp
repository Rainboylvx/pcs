/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 12日 星期一 09:58:40 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
ll sum[maxn];
ll a[maxn];

//分块的模板
struct split_chunk {
    ll * arr = a; //对应的原数组
    int chunk_id[maxn]; //每个点属于的chunk编号
    int per_chunk_length; // 每个chunk的长度
    int chunk_tot; // 共有多少个chunk
    ll add[maxn];

    int l[maxn],r[maxn]; //l[i],第i块的左区间

    //通过数组的长度,来创建相关的信息 
    void init(int n) {
        per_chunk_length = sqrt(n);
        chunk_tot = per_chunk_length;
        for(int i=1;i<=chunk_tot;++i){
            l[i] = (i-1) * per_chunk_length + 1;
            r[i] = i * per_chunk_length;
        }
        //
        if(r[chunk_tot] < n)
        {
            ++chunk_tot;
            l[chunk_tot] = r[chunk_tot-1]+1;
            r[chunk_tot] = n;
        }

        // 得到位置i对应的chunk_id
        for(int i=1;i<=chunk_tot;++i){
            for(int j=l[i];j<=r[i];++j){
                chunk_id[j] = i; //每个位置j对应的chunk_id
                sum[i] += a[j]; //预先处 分块的区间和
            }
        }
    }

    void part_update(int l,int r,ll d) {
        int cid = chunk_id[l];
        for(int i=l;i<=r;++i){
            a[i] += d;
        }
        sum[cid] += d * (r-l+1);
    }
    ll part_query(int x,int y){
        int cid = chunk_id[x];
        ll ans = 0;
        for(int i=x;i<=y;++i){
            ans += a[i];
        }
        ans += add[cid] * (y -x+1);
        return ans;
    }

    //更新连续区间
    void update(int x,int y,ll d) {
        int u = chunk_id[x],v =chunk_id[y];
        if(u == v) {
            part_update(x, y, d);
        }
        else {
            for(int i=u+1;i<=v-1;++i){
                add[i] += d;
            }
            part_update(x, r[u], d);
            part_update(l[v], y, d);
        }

    }

    //查询区间和
    ll query(int x,int y) {
        int u = chunk_id[x],v =chunk_id[y];
        ll ans = 0;
        if(u == v) {
            ans += part_query(x, y);
        }
        else {
            for(int i=u+1;i<=v-1;++i){
                ans += sum[i] + add[i] * (r[i] - l[i] +1);
            }
            ans += part_query(x, r[u]);
            ans += part_query(l[v], y);
        }
        return ans;
    }

} chunk;

void init()
{
    // cin >> n >> m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        // cin >> a[i];
        scanf("%lld",&a[i]);
    }
}
int main(int argc,char * argv[]){
    // cin.sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    init();
    chunk.init(n);

    char str[3];
    int l,r,d;
    for(int i=1;i<=m;i++) {
        // cin >> q;
        scanf("%s",str);
        scanf("%d%d",&l,&r);
        if( str[0] == 'C') {
            cin >> d;
            chunk.update(l, r, d);
        }
        else {
            // cout << chunk.query(l, r) << "\n";
            printf("%lld\n",chunk.query(l, r));
        }
    }
    
    return 0;
}
