#include<cstdio>
#include<string.h>
#include <iostream>
#include <queue>
using namespace std;

int m, n;
char map[102][102];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } }; 
int flag[102][102];
int fight[102][102];  
int totTime;
int seconds;
struct Node{
    int x;
    int y;
    int time;
    bool operator<(const Node &a) const {
        return a.time<time;
    }
};
bool bfs()
{
    priority_queue<Node>que; 
    struct Node start;
    start.x=start.y=start.time=0;
    que.push(start);
    map[0][0]='X';

    while (!que.empty())
    {
        struct Node cur=que.top();
        que.pop();
        if(cur.x==n-1 && cur.y==m-1)
		{
            totTime=cur.time;
            return true;
        }
        for (int i=0; i<4; i++)
		{
            int xtmp=cur.x+dir[i][0];
            int ytmp=cur.y+dir[i][1];
            if(map[xtmp][ytmp]=='X') continue;
            if(xtmp<n && xtmp>=0 && ytmp<m && ytmp>=0 )
			{
                struct Node nextstep;
                nextstep.x=xtmp;
                nextstep.y=ytmp;
                if(map[nextstep.x][nextstep.y]!='.') 
				{
                    nextstep.time=cur.time+1+map[nextstep.x][nextstep.y]-'0';
                    fight[nextstep.x][nextstep.y]=map[nextstep.x][nextstep.y]-'0';  
                } 
				else
                    nextstep.time=cur.time+1;
                    
                flag[nextstep.x][nextstep.y]=i+1;
                que.push(nextstep);
                map[xtmp][ytmp]='X';
            }
        }
    }
    return false;//没有到达，则返回false
}

void printRoad(int x, int y)
{
    if(flag[x][y]==0) return ;
    int pre_x, pre_y;
    pre_x=x-dir[flag[x][y]-1][0];
    pre_y=y-dir[flag[x][y]-1][1];
    printRoad(pre_x, pre_y);
    printf("%ds:(%d,%d)->(%d,%d)\n",seconds++,pre_x,pre_y,x,y); 
    while(fight[x][y]--)
        printf("%ds:FIGHT AT (%d,%d)\n",seconds++,x,y); 
    
}
int main()
{ 
    int i, j;
    while(~scanf("%d%d", &n, &m))
    {
        memset(fight,0,sizeof(fight));
        memset(flag,0,sizeof(flag));
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                cin>>map[i][j];
        if(bfs())
		{
            seconds=1;
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",totTime);
            printRoad(n-1,m-1);
        } 
		else 
		{
            printf("God please help our poor hero.\n");
        }
        printf("FINISH\n"); 
    }
    return 0;
}
