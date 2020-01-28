#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
struct POINT
{
    int x,y,tot; //坐标，步数
    bool get_jewel[7],enchantment; //找到的宝石，结界
} point,door;

int main()
{
    int k,F[4][2]={-1,0,1,0,0,-1,0,1};
    scanf("%d",&k);
    for(int kk=1;kk<=k;kk++)
    {
        /*定义*/
        queue<POINT> que; //队列
        int r,c,needkind,door_coord[15][2]={},sdoor_coord=0; //边界，需要的宝石种类,传送门坐标，传送门个数
        char maze[205][205]={};//迷宫
        bool walked[205][205][35]={},finish=false; //已经走过的路，第三维是宝石数(2进制)；是否完成
        /*输入*/
        scanf("%d%d%d",&r,&c,&needkind);
        for(int i=0;i<r;i++)
        {
            scanf("%s",maze[i]);
            for(int j=0;j<c;j++)
            {
                if(maze[i][j]=='S') //起点
                {
                    memset(point.get_jewel,false,sizeof(point.get_jewel));
                    point.x=i;point.y=j;point.tot=0;point.enchantment=true;
                }
                if(maze[i][j]=='$') //传送门
                {
                    door_coord[sdoor_coord][0]=i; //存入位置
                    door_coord[sdoor_coord++][1]=j;
                }
            }
        }
        /*广度优先搜索*/
        que.push(point); //存入起点
        while(!que.empty()) //队列不为空
        {
            for(int i=0;i<4;i++) //4个方向
            {
                point=que.front(); //直接等
                point.tot++;point.x+=F[i][0];point.y+=F[i][1]; //改坐标，改步数
                if(point.x<0 || point.x>=r || point.y<0 || point.y>=c || maze[point.x][point.y]=='#') continue;
                //超界或为墙
                if('0'<=maze[point.x][point.y] && maze[point.x][point.y]<='4') //如果为宝石
                    point.get_jewel[maze[point.x][point.y]-'0']=true; //改变point中该宝石的值为 “找到 ”
                int sget_jewel=0,ss=0; //找到的宝石个数
                for(int i=0;i<5;i++)
                    if(point.get_jewel[i]) //遍历宝石获得数
                        sget_jewel+=pow(2,i),ss++; //eg:获得0,3 --> 2进制：01001=9
                if(walked[point.x][point.y][sget_jewel]) continue;
                //如果之前到达过该位置且未找到更多的宝石
                walked[point.x][point.y][sget_jewel]=true; //改变该位置的到达记录
                if(ss>=needkind) point.enchantment=false; //如果找到了足够的宝石，结界消失
                if(maze[point.x][point.y]=='$') //如果是传送门
                {
                    door=point; //保存位置
                    for(int i=0;i<sdoor_coord;i++) //遍历所有传送门
                        if(door_coord[i][0]!=point.x || door_coord[i][1]!=point.y) //不是当前的位置
                        {
                            door.x=door_coord[i][0];door.y=door_coord[i][1]; //存入传送门
                            que.push(door);
                        }
                }
                if(maze[point.x][point.y]=='E' && !point.enchantment)
                    //如果是找到终点并且没有结界
                {
                    printf("%d\n",point.tot);
                    finish=true; //找到
                }
                if(finish) break; //找到退出
                que.push(point); //存入当前位置
            }
            if(finish) break; //找到退出
            que.pop(); //出队
        }
        if(!finish) printf("oop!\n"); //没有找到
    }
    return 0;
}
