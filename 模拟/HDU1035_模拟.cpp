#include<iostream>
#include<cstring>
using namespace std;

const int maxn=15;
int count[maxn][maxn];
int n, m, k;
char dir[maxn][maxn];

void dfs(int x, int y)
{
	int step=0;
	memset(count,-1,sizeof(count));
	while(1)
	{
		if(x>n || y>m || !x || !y)
		{
			printf("%d step(s) to exit\n",step);
			return;
		}
		if(count[x][y]>=0)//注意等于零的情况 
		{
			printf("%d step(s) before a loop of %d step(s)\n",count[x][y],step-count[x][y]);
			return;
		}
		count[x][y] = step;
        if(dir[x][y]=='N') x--;
        else if(dir[x][y]=='S') x++;
        else if(dir[x][y]=='W') y--;
        else if(dir[x][y]=='E') y++;
        step++;
	}
}

int main()
{
    while(scanf("%d%d", &n, &m),m||n)
    {
        scanf("%d", &k);
        for(int i=1; i<=n; i++)
            scanf("%s", dir[i]+1);
        dfs(1, k);
    }
    return 0;
}
