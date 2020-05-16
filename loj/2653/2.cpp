#include<iostream>
#include<queue>

using namespace std;

const int N = 1001;
const int MOV[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};

int w[N][N];
int vis[N][N];
queue<int> q;
int feng,gu,n;

int main(){
	cin >> n;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
			cin >> w[i][j];
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j) if (!vis[i][j]) {
			int m = -1;
			bool ok = true;
			q.push(i*n+j); vis[i][j] = true;
			while (!q.empty()){
				int x = q.front()/n, y = q.front()%n; q.pop();
				for (int k=0;k<8;++k){
					int nx = x+MOV[k][0];
					int ny = y+MOV[k][1];
					if (nx>=0 && nx<n && ny>=0 && ny<n){
						if (w[nx][ny]==w[i][j]){
							if (!vis[nx][ny]){
								vis[nx][ny] = true;
								q.push(nx*n+ny);
							}
						} else {
							int cmp = w[nx][ny]>w[i][j];
							if (m==-1) m = cmp;
							else {
								if (m!=cmp) ok = false;
							}	
						}
					}
				}
			}
			if (m==-1) {
				gu++;
				feng++;
			}else{
				if (ok){
				if (m) gu++;
				else feng++;
			}
		}
	}
	cout << feng << " " << gu << endl;
}
