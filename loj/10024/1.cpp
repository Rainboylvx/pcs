/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 13日 星期五 08:38:20 CST
* problem:  loj-10024
*----------------*/
#include <bits/stdc++.h>
typedef long long ll;
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

int mp[10][10];
int m1_sum[10][10]; // 记录行的前缀和
int m2_sum[10][10]; // 记录列的前缀和
vector<string> v;  // 存所有 和 为 n的素数
vector<string> v1; // 存开头为m 的 素数
vector<string> v2; // 存开头为m 的 素数,且不含0
vector<string> head[10][10]; //head[i][j] 开头i,结尾j的 和为n的, 不含偶数

bool b[100000]; //筛法选素数

void shai(){ int i,j; For(i,2,100000){ if( !b[i] ) For(j,2,100000/i){ b[i*j] = 1; } } }

inline bool isprime(int x){ return !b[x]; }


int chai_tmp[10];
int chai(int n){
    int cnt = 5,sum=0;
    while(n >0){
        int g = n % 10;
        chai_tmp[cnt--]= g;
        sum += g;
        n /= 10;
    }
    return sum;
}

bool chai_no_0(int n){
    int cnt = 5;
    while(n >0){
        int g = n % 10;
        if(!g) return 0;
        n /= 10;
    }
    return 1;
}

//没有偶数
bool chai_no_eve(int n){
    int cnt = 5;
    while(n >0){
        int g = n % 10;
        if(!g || g % 2 == 0) return 0;
        n /= 10;
    }
    return 1;
}

string ToString(int x){
    int i,base = 10000;
    string s;
    For(i,1,5){
         s += x /base +'0';
         x %= base;
         base /= 10;
    }
    return s;
}

void init(){
    shai();
    scanf("%d%d",&n,&m);
    int i;
    For(i,10000,90000+9999){
        if( !b[i] && chai(i) == n){
            string s = ToString(i);
            if( s[0] == m +'0') {
                v1.push_back(s);
                if( chai_no_0(i) )
                    v2.push_back(s);
            }
            if( chai_no_eve(i)){
                int t1 = s[0]-'0';
                int t2 = s[4]-'0';
                head[t1][t2].push_back(s);
            }
        }
    }
}

void p_mp(){ int i,j; For(i,1,5){ For(j,1,5){ printf("%d",mp[i][j]); } printf("\n"); } printf("\n"); }

bool all_check(){
    int i,j;
    For(i,1,5){
        int s1=0,s2=0;
        for(j=1;j<=5;++j){
            s1 += mp[i][j];
            s2 = s2 *10 + mp[i][j];
        }
        if( s1 != n || b[s2]) return 0;
    }
    For(j,1,5){
        int s1=0,s2=0;
        For(i,1,5){
            s1 += mp[i][j];
            s2 = s2 *10 + mp[i][j];
        }
        if( s1 != n || b[s2]) return 0;
    }
    int s1 = mp[1][1] + mp[2][2] + mp[3][3] + mp[4][4] + mp[5][5] ;
    int s2 = mp[1][1] *10000+ mp[2][2] *1000+ mp[3][3] *100+ mp[4][4] *10+ mp[5][5] ;
    if( s1 != n || b[s2]) return 0;

    s1 = mp[5][1] + mp[4][2] + mp[3][3] + mp[2][4] + mp[1][5] ;
    s2 = mp[5][1] *10000+ mp[4][2] *1000+ mp[3][3] *100+ mp[2][4] *10+ mp[1][5] ;
    if( s1 != n || b[s2]) return 0;
    return 1;
}

/* 放 \ 行 */
void put_xx(int i){
    mp[1][1] = v1[i][0] -'0'; mp[2][2] = v1[i][1] -'0'; mp[3][3] = v1[i][2] -'0'; mp[4][4] = v1[i][3] -'0'; mp[5][5] = v1[i][4] -'0';
}

void put_line_1(int i){
    mp[1][2] = v2[i][1] - '0';
    mp[1][3] = v2[i][2] - '0';
    mp[1][4] = v2[i][3] - '0';
    mp[1][5] = v2[i][4] - '0';
}


void put_lie_1(int i){
    mp[2][1] = v2[i][1] - '0'; mp[3][1] = v2[i][2] - '0'; mp[4][1] = v2[i][3] - '0'; mp[5][1] = v2[i][4] - '0';
}

//void put_line_2(int i){
    //mp[2][3] = head[mp[2][1]][i][2] - '0';
    //mp[2][4] = head[mp[2][1]][i][3] - '0';
//}
//void put_line_3(int i){
    //mp[3][2] = head[mp[3][1]][i][1] - '0';
    //mp[3][4] = head[mp[3][1]][i][3] - '0';
//}
//void put_line_4(int i){
    //mp[4][2] = head[mp[4][1]][i][1] - '0';
    //mp[4][3] = head[mp[4][1]][i][2] - '0';
//}

void put_lie_5(int i){
    mp[2][5] =head[mp[1][5]][mp[5][5]][i][1] - '0';
    mp[3][5] =head[mp[1][5]][mp[5][5]][i][2] - '0';
    mp[4][5] =head[mp[1][5]][mp[5][5]][i][3] - '0';
}
void put_line_5(int i){
    mp[5][2] =head[mp[5][1]][mp[5][5]][i][1] - '0';
    mp[5][3] =head[mp[5][1]][mp[5][5]][i][2] - '0';
    mp[5][4] =head[mp[5][1]][mp[5][5]][i][3] - '0';
}
int tt[10][10] = {

    {0,1,1,3,5,1},
    {0,1,1,3,5,1},
    {0,1,4,-1,-1,3},
    {0,3,-1,3,-1,3},
    {0,5,-1,-1,0,1},
    {0,1,3,3,1,3},
};

bool cmp_tt(){
    int i,j;
    For(i,1,5){
        For(j,1,5){
            if( tt[i][j] == -1) continue;
            if( mp[i][j] != tt[i][j]) return 0;
        }
    }
    return 1;
}
inline bool isCorrect(int x1,int x2,int x3,int x4,int x5){
    int sum = x1*10000+ x2*1000+ x3*100+ x4*10+ x5;
    return !b[sum];
}
// line_2 关键点的和
#define line_2_sum (mp[2][1] + mp[2][2] + mp[2][5])
#define lie_3_sum (mp[1][3] + mp[3][3] + mp[5][3])
#define lie_4_sum (mp[1][4] + mp[2][4] + mp[4][4]+mp[5][4])

vector<string> ans;

string tran_mp_s(){
    string s;
    int i,j;
    For(i,1,5){
        For(j,1,5){
            s += mp[i][j]+'0';
        }
    }
    return s;
}

void str_mp_out(string s){
    int i;
    For(i,0,24){
        printf("%c",s[i]);
        if( (i+1) %5 == 0) printf("\n");
    }
    printf("\n");
}

// 最后的放置
bool final_put(){
    int i1,i2,i3,i4,i5;
    For(i1,0,9){ // mp[2][3] 放置尝试 //第二行
        int sum  = line_2_sum + i1;
        int rest = n -sum;
        if( rest >9 || rest <0 ) continue;
        if( ! isCorrect(mp[2][1],mp[2][2],i1,rest,mp[2][5])) continue;
        mp[2][3] = i1,mp[2][4] = rest;
        // ---- 第3列
        rest = n-lie_3_sum-i1;
        if( rest >9 || rest <0 ) continue;
        if( !isCorrect( mp[1][3], mp[2][3], mp[3][3], rest, mp[5][3])) continue;
        mp[4][3] = rest;
        // ---- 第4列
        rest = n - lie_4_sum;
        if( rest >9 || rest <0 ) continue;
        if( !isCorrect( mp[1][4], mp[2][4], rest, mp[4][4], mp[5][4])) continue;
        mp[3][4] = rest;

        // -- 第3行
        rest = n - (mp[3][1] + mp[3][3]+mp[3][4]+mp[3][5]);
        if( rest >9 || rest <0 ) continue;
        if( !isCorrect(mp[3][1] , rest,mp[3][3],mp[3][4],mp[3][5])) continue;
        mp[3][2] = rest;

        // -- 第4行
        rest = n - (mp[4][1] + mp[4][3]+mp[4][4]+mp[4][5]);
        if( rest >9 || rest <0 ) continue;
        if( !isCorrect(mp[4][1] , rest,mp[4][3],mp[4][4],mp[4][5])) continue;
        mp[4][2] = rest;

        //检查第2列
        if( mp[2][2] + mp[1][2] + mp[3][2] + mp[4][2]+mp[5][2] !=n ) continue;
        if( !isCorrect(  mp[1][2] ,mp[2][2] , mp[3][2] , mp[4][2],mp[5][2] )) continue;

        //检查 / 斜线
        int s1 = mp[5][1] + mp[4][2] + mp[3][3] + mp[2][4] + mp[1][5] ;
        if( s1 != n ) continue;
        int s2 = mp[5][1] *10000+ mp[4][2] *1000+ mp[3][3] *100+ mp[2][4] *10+ mp[1][5] ;
        if(  b[s2]) continue;;
        ans.push_back(tran_mp_s());
        //p_mp();
        //if( all_check()){
            //printf("yes\n");
        //}
        //else
            //printf("no\n");

    }
    return 1;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    int cnt=0;
    ll i1,i2,i3,i4,i5,i6,i7,i8,i9;
    
    For(i1,0,v1.size()-1){  //第一层斜线
        put_xx(i1);
        For(i2,0,v2.size()-1){ //第一行
            put_line_1(i2);
            For(i3,0,v2.size()-1){ //第一列
                put_lie_1(i3);
                ll i4_end = head[mp[5][1]][mp[5][5]].size();
		if(!i4_end) continue;
		i4_end--;
                For(i4,0,i4_end){ //最后一行
                    put_line_5(i4);
                    ll i5_end = head[mp[1][5]][mp[5][5]].size();
		    if(!i5_end) continue;
		    i5_end--;

                    For(i5,0,i5_end){ //最后一列
                        put_lie_5(i5);
                        //if( cmp_tt() ){
                            //printf("yes");
                            //final_put();
                            //return 0;
                        //}
                        final_put();
                        //p_mp();
                        //cnt++;
                    }
                }
            }
        }
    }
    //printf("%d\n",cnt);
    sort(ans.begin(),ans.end());
    ll siz = ans.size() - 1;
    For(i1,0,siz){
        str_mp_out(ans[i1]);
    }
    


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
