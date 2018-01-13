/*Eddy's picture

Problem Description
Eddy begins to like painting pictures recently ,
he is sure of himself to become a painter.
Every day Eddy draws pictures in his small room, 
and he usually puts out his newest pictures to let his friends appreciate. 
but the result it can be imagined(想象), 
the friends are not interested in his picture.Eddy feels very puzzled,
in order to change all friends 's view to his technical（技术的） of painting pictures ,
so Eddy creates a problem for the his friends of you.
Problem descriptions as follows: 
	Given you some coordinates（坐标） pionts on a drawing paper, 
	every point links with the ink with the straight line, 
	causes all points finally to link in the same place. 
	How many distants does your duty discover the shortest length which the ink draws?

Input
The first line contains 0 < n <= 100, the number of point. 
For each point, a line follows; each following line contains two real numbers 
indicating the (x,y) coordinates of the point. 
Input contains multiple test cases. Process to the end of file.
 
Output
Your program prints a single real number to two decimal places: 
the minimum total length of ink lines that can connect all the points. 

Sample Input
3
1.0 1.0
2.0 2.0
2.0 4.0
 
Sample Output
3.41

*/
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MAXN 100+10
#define INF 9999999999
using namespace std;

int n, tag[MAXN];
double mp[MAXN][MAXN], low[MAXN];

double prime(void){
    memset(tag, 0, sizeof(tag));  //×××标记数组清 0
    int s=1;
    double cnt=0;
    for(int i=1; i<=n; i++){   //×××从点 1 开始
        low[i]=mp[s][i];
    }
    for(int i=2; i<=n; i++){
        double min=INF;
        for(int j=2; j<=n; j++){  //×××找到未添加点中到以添加点中距离最近的点即当前要添加的点
            if(!tag[j]&&min>low[j]){
                min=low[j];
                s=j;
            }
        }
        cnt+=min;      //***本题中不存在不能连同的情况，所以不需要加 if(min>=INF) return -1
        tag[s]=1;
        for(int j=2; j<=n; j++){
            if(!tag[j]&&low[j]>mp[s][j]){  //×××更新low数组
                low[j]=mp[s][j];
            }
        }
    }
    return cnt;
}

int main(void){
    while(~scanf("%d", &n)){
        pair<double, double> p[MAXN];
        for(int i=1; i<=n; i++){
            scanf("%lf%lf", &p[i].first, &p[i].second);
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                mp[i][j]=sqrt((p[j].first-p[i].first)*(p[j].first-p[i].first)+(p[j].second-p[i].second)*(p[j].second-p[i].second));
            }
        }
        double ans=prime();
        printf("%.2lf\n", ans);
    }
    return 0;
}
