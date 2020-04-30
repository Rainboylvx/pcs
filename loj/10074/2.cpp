#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

int N, P, K, tot;
int head[1001], f[1001][1001], v[1001][1001];
struct node{
    int to, v, next;
}e[20001];

void add(int x, int y, int z) {
    e[++tot].to = y;
    e[tot].v = z;
    e[tot].next = head[x];
    head[x] = tot;
    e[++tot].to = x;
    e[tot].v = z;
    e[tot].next = head[y];
    head[y] = tot;
}

void spfa() {
    memset(f, 127 / 3, sizeof(f));
    queue< pair<int, int> > q;
    q.push(make_pair(1, 0));
    v[1][0] = 1;
    f[1][0] = 0;
    pair<int, int> a;
    while (q.size()) {
        a = q.front();
        q.pop();
        v[a.first][a.second] = 0;
        for (int i = head[a.first]; i; i = e[i].next) {
            if (a.second < K && f[a.first][a.second] < f[e[i].to][a.second + 1]) {//use
                f[e[i].to][a.second + 1] = f[a.first][a.second];
                if (!v[e[i].to][a.second + 1]) {
                    v[e[i].to][a.second + 1] = 1;
                    q.push(make_pair(e[i].to, a.second + 1));
                }
            }
            if (max(e[i].v, f[a.first][a.second]) < f[e[i].to][a.second]) {//not use
                f[e[i].to][a.second] = max(e[i].v, f[a.first][a.second]);
                if (!v[e[i].to][a.second]) {
                    v[e[i].to][a.second] = 1;
                    q.push(make_pair(e[i].to, a.second));
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &P, &K);
    for (int i = 1, x, y, z; i <= P; i++) {
        scanf("%d %d %d", &x, &y, &z);
        add(x, y, z);
    }
    spfa();
    printf("%d", f[N][K] == 707406378 ? -1 : f[N][K]);
}
