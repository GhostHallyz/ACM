/*hdu2660 Accepted Necklace(±³°ü±äÐÎ)

Problem Description
I have N precious stones, and plan to use K of them to make a necklace for my mother, but she won't accept a necklace which is too heavy. Given the value and the weight of each precious stone, please help me find out the most valuable necklace my mother will accept.

Input
The first line of input is the number of cases. 
For each case, the first line contains two integers N (N <= 20), the total number of stones, and K (K <= N), the exact number of stones to make a necklace. 
Then N lines follow, each containing two integers: a (a<=1000), representing the value of each precious stone, and b (b<=1000), its weight. 
The last line of each case contains an integer W, the maximum weight my mother will accept, W <= 1000. 

Output
For each case, output the highest possible value of the necklace.

Sample Input
1 
2 1 
1 1 
1 1 
3 

Sample Output
1 

*/

#include<iostream>   
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>   
#include<cmath>   
using namespace std;
int w[25], v[25],dp[1010][25];
int main()  
{  
    int t,n,m,W,j,i,k;
    scanf("%d",&t);
    while(t--)
    {
    	memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d%d",&v[i],&w[i]);
		scanf("%d",&W);
		for(i=0;i<n;i++)
			for(j=W;j>=w[i];j--)
				for(k=1;k<=m;k++)
					dp[j][k]=max(dp[j][k],dp[j-w[i]][k-1]+v[i]);
		printf("%d\n",dp[W][m]);
    } 
    return 0;  
}  


