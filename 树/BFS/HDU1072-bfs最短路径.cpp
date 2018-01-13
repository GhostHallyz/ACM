#include<cstdio>  
#include<iostream>  
#include<queue>  
#define N 10  
using namespace std;  
int map[N][N],n,m; 
int dir[4][2]={ {0,1},{0,-1},{-1,0},{1,0} }; /*���� ���� ���� ����*/ 
struct Node  
{  
   int x,y;//��¼����   
   int step,time;//������ʱ��   
}start;  
void BFS()  
{  
   queue<Node> q;//����ʵ��  
   Node q1,q2;//����ֵ���൱��temp   
   q.push(start);//��start�������  
     
   //����Ϊ��ʱ˵�� �� 
   //1.�Ѿ�ɨ�赽��� ��2.��ȫɨ�������û�ҵ������  
   while(!q.empty())  
   {  
      int i;  
      q1=q.front();//����ͷ�������ó���  
      q.pop();//����ͷ����  
      //��ʼ�������������ĸ�����   
      for(i=0;i<4;i++)  
      {  
         q2.x=q1.x+dir[i][0];  
         q2.y=q1.y+dir[i][1];  
         q2.step=q1.step+1;  
         q2.time=q1.time-1;  
         //�ж�����һ���Ƿ��Ѿ���������Χ   
          //ȷ���˲������߹���(��ǽ)����ը��ʱ���ѵ�   
         if(q2.x>=0&&q2.y>=0&&q2.x<n&&q2.y<m&&map[q2.x][q2.y]!=0&&q2.time>0)  
         {  
            //˵���ҵ��𰸣���������   
            if(map[q2.x][q2.y]==3)  
            {  
               printf("%d\n",q2.step);  
               return;                      
            }  
            else if(map[q2.x][q2.y]==4)  
            {//����ʱ������������Իָ�ʱ��   
                 q2.time=6;  
                 map[q2.x][q2.y]=0; //����Ѿ��߹�     
            }    
            q.push(q2);//����һ���Ž�����                                 
         }  
      }   
   }    
   //����ɨ�궼û�ѵ��𰸣�˵���𰸲�����  
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
               start.time=6;//ʱ���ʼ��Ϊ6   
            }  
         }  
         BFS();   
    }  
    return 0;  
}  

