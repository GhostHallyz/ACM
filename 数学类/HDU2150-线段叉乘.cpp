/*叉乘判断 
两个向量的向量积，是一个垂直于两个向量的向量，如果ABxAC，得到的结果是垂直于ABC这个平面的一个向量，
这是用右手系判断的，如果是ABxAC，就是右手拇指朝上，手掌从AB边旋转小于180度的角度转到AC，这个结果就是拇指的方向。
如果AB和CD相交，可以画个图看看，ABxAC和ADxAB的拇指方向是相同的，ACxAD和BDxBC的拇指方向也是相同的。
ABxAC=（b.x-a.x）*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)；
(ABxAC)*(ADxAB)>=0,就是说明这两个向量积的方向相同，也就是姆指方向相同，也就是两个线段相交的判断条件。
其他的过程就是依次枚举。
*/

#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<cstring>  
using namespace std;  

struct point{  
    int x,y;  
}p[35][105];  

double circulation(point a,point b,point c)
{  
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);  
}  
bool cross(point a,point b,point c,point d)
{  
    if(max(a.x,b.x)>=min(c.x,d.x)&&  
       max(c.x,d.x)>=min(a.x,b.x)&&  
       max(a.y,b.y)>=min(c.y,d.y)&&  
       max(c.y,d.y)>=min(a.y,b.y)&&  
       circulation(a,b,c)*circulation(a,d,b)>=0&&  
       circulation(a,c,d)*circulation(b,d,c)>=0) 
	   return true;
	else  
    	return false;  
}  
int main()
{  
    int n,k[35];  
    while(cin>>n)
	{  
        memset(k,0,sizeof(k));  
        memset(p,0,sizeof(p));  
        for(int i=0;i<n;i++)
		{  
            cin>>k[i];  
            for(int j=0;j<k[i];j++) 
				scanf("%d%d",&p[i][j].x,&p[i][j].y);  
        }  
        if(n==1)
		{  
            printf("No\n");  
            continue;  
        }  
        int flag=0;  
        for(int i=0;i<n-1;i++)
		{  
            for(int j=1;j<k[i];j++)
			{  
                for(int t=i+1;t<n;t++)
				{  
                    for(int h=1;h<k[t];h++)
					{  
                        if(cross(p[i][j-1],p[i][j],p[t][h-1],p[t][h]))
						{  
                            flag=1;  
                            break;  
                        }  
                    }  
                }  
            }  
        }  
        if(flag) 
			printf("Yes\n");  
        else 
			printf("No\n");  
    }  
    return 0;  
}  
