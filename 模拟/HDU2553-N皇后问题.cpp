/*N皇后问题
Problem Description
在N*N的方格棋盘放置了N个皇后，使得它们不相互攻击（即任意2个皇后不允许处在同一排，同一列，也不允许处在与棋盘边框成45角的斜线上。
你的任务是，对于给定的N，求出有多少种合法的放置方法。
Input
共有若干行，每行一个正整数N≤10，表示棋盘和皇后的数量；如果N=0，表示结束。
Output
共有若干行，每行一个正整数，表示对应输入行的皇后的不同放置数量。
Sample Input
1
8
5
0
Sample Output
1
92
10
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int vis[50],row[50],col[50],P[15];//三个方向 ↖↑↗在此三个方向都不能有皇后 
int n, sum;

void  DFS(int row);

int main()
{
    for(n = 1; n <= 10; n++)//先打表不然会超时的
    {
        memset(vis,0,sizeof(vis));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        sum = 0;
        DFS(1);
        P[n] = sum;
    }
    while(scanf("%d",&n), n)
    {
        printf("%d\n",P[n]);
    }
    return 0;
}

void  DFS(int k)
{
    int i;
    if(k == n + 1)
    {
        sum ++;
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(vis[k-i+n] == 0 && row[i] == 0 && col[k+i] == 0)
        {
            vis[k-i+n] = row[i] = col[k+i] = 1;//变值
            DFS(k + 1);//深搜
            vis[k-i+n] = row[i] = col[k+i] = 0;//回溯
        }
    }
}


