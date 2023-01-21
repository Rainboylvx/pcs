#include <cstdio>

typedef long long ll;
int n;
ll a[200100];


void quicksort(int l,int r){
    if( l < r) {
    int s=l,t=r;
    ll key =a[l]; // 取第一个值为key

    while(s < t){
        while( s <t && key <a[t]) --t;// key 应该在a[t]前面时 --t
        if(s < t) a[s++] = a[t];        //交换
        while(s<t &&  key > a[s]) ++s;  // key 应该在a[s]后面时 ++s
        if(s<t ) a[t--] = a[s];         //停下来的时候,看一看,是不是到了中点,如果不是,交换值
    }
    a[s] = key;  //上面while停止的时候,一定是s ==t
    quicksort(l,s-1);
    quicksort(s+1,r);
}
}

int main(){
	scanf("%d",&n);
	int i,j;
	//输入数据
	for(i=1;i<=n;i++){
	    scanf("%lld",&a[i]);
	}
	quicksort(1,n);

	int cnt =1;
	for(i=2;i<=n;i++){
	    if( a[i] == a[i-1])
	        cnt++;
	    else {
	        printf("%lld %d\n",a[i-1],cnt);
	        cnt =1;
	    }
	}
	printf("%lld %d\n",a[n],cnt);


    return 0;
}
