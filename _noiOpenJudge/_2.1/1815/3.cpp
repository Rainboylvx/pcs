#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n, paint[18][18], canvas[18][18], tmp[18][18];
int minn = 500;

void change(int i, int j){
    tmp[i][j] = !tmp[i][j];
    tmp[i-1][j] = !tmp[i-1][j];
    tmp[i+1][j] = !tmp[i+1][j];
    tmp[i][j+1] = !tmp[i][j+1];
    tmp[i][j - 1] = !tmp[i][j - 1];
};

int check(){
    int num = 0;
    memcpy(tmp, canvas, sizeof tmp);
    for (int i = 1; i <= n; i++)
        if (paint[1][i] == 1){ change(1, i); num++; }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (tmp[i - 1][j]){ paint[i][j] = 1; change(i, j); num++; }
    }
    for (int i = 1; i <= n; i++){
        if (tmp[n][i]) return 1;
    }
    minn = min(minn, num);
    return 0;
};

int main()
{
    cin >> n;
    char x;
    memset(paint, 0, sizeof paint);
    memset(canvas, 0, sizeof canvas);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == 'w') canvas[i][j] = 1;
        }
    while (!paint[1][n + 1]){
        check();
        for (int i = 2; i <= n;i++)
            for (int j = 1; j <= n; j++)
                paint[i][j] = 0;
        paint[1][1]++;
        for (int i = 1; i <= n; i++){
            if (paint[1][i] == 2){ paint[1][i + 1]++; paint[1][i] = 0; }
        }
    }
    if (minn == 500) cout << "inf";
    else cout << minn;

    return 0;
}
