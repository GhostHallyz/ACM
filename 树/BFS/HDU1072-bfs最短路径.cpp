#include<cstdio>  
#include<iostream>  
#include<queue>  
#define N 10  
using namespace std;  
int map[N][N],n,m; 
int dir[4][2]={ {0,1},{0,-1},{-1,0},{1,0} }; /*向右 向左 向下 向上*/ 
struct Node  
{  
   int x,y;//记录坐标   
   int step,time;//步数和时间   
}start;  
void BFS()  
{  
   queue<Node> q;//队列实现  
   Node q1,q2;//交换值，相当于temp   
   q.push(start);//将start放入队列  
     
   //队列为空时说明 ： 
   //1.已经扫描到结果 ；2.完全扫描结束（没找到结果）  
   while(!q.empty())  
   {  
      int i;  
      q1=q.front();//将队头的数据拿出来  
      q.pop();//将队头弹出  
      //开始搜索上下左右四个方向   
      for(i=0;i<4;i++)  
      {  
         q2.x=q1.x+dir[i][0];  
         q2.y=q1.y+dir[i][1];  
         q2.step=q1.step+1;  
         q2.time=q1.time-1;  
         //判断走这一步是否已经超出矩阵范围   
          //确定此步不是走过的(或墙)或者炸弹时间已到   
         if(q2.x>=0&&q2.y>=0&&q2.x<n&&q2.y<m&&map[q2.x][q2.y]!=0&&q2.time>0)  
         {  
            //说明找到答案，结束搜索   
            if(map[q2.x][q2.y]==3)  
            {  
               printf("%d\n",q2.step);  
               return;                      
            }  
            else if(map[q2.x][q2.y]==4)  
            {//碰到时间调整器，可以恢复时间   
                 q2.time=6;  
                 map[q2.x][q2.y]=0; //标记已经走过     
            }    
            q.push(q2);//将这一步放进队列                                 
         }  
      }   
   }    
   //队列扫完都没搜到答案，说明答案不存在  
   printf("-1\n");  
   return;  
}  
int main()  
{  
    int i,j,T;  
    scanf("%d",&T);  
    while(T--)  
    {  
       scanf("%d %d",&n,&m);  
       for(i=0;i<n;i++)  
         for(j=0;j<m;j++)  
         {  
            scanf("%d",&map[i][j]);  
            if(map[i][j]==2)  
            {  
               start.x=i;  
               start.y=j;  
               start.step=0;  
               start.time=6;//时间初始化为6   
            }  
         }  
         BFS();   
    }  
    return 0;  
}  

