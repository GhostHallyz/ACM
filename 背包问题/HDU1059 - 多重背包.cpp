#include<stdio.h>  
#include<string.h>  
int dp[120002],a[6];  //注意dp数组要不小于120000  
int max(int a,int b)  
{  
    return a>b?a:b;  
}  
void CompletePack(int v,int w,int m)  
{  
    for(int i=v;i<=m;i++)  
      dp[i]=max(dp[i],dp[i-v]+w);  
}  
void ZeroOnePack(int v,int w,int m)  
{  
    for(int i=m;i>=v;i--)  
     dp[i]=max(dp[i],dp[i-v]+w);  
}  
void MultiPack(int v,int w,int m,int c)  
{  
    if(v*c>=m)  
        CompletePack(v,w,m);  
    else  
    {  
        int k=1;  
        while(k<c)  
        {  
            ZeroOnePack(k*v,k*w,m);  
            c-=k;  
            k*=2;  
        }  
        ZeroOnePack(c*v,c*w,m);  
    }  
}  
int main()  
{  
    int i,sum,count,t=0,s;  
    while(1)  
    {  
        count=sum=0;  
        for(i=1;i<=6;i++)  
        {  
            scanf("%d",&a[i]); //a[i]为数量，i为价值和体积  
            sum+=a[i]*i;  
            if(a[i]==0)  
              count++;  
        }  
        if(count==6) break;  
        memset(dp,0,sizeof(dp));  
        s=sum/2;  
        for(i=1;i<=6;i++)  
        {  
          MultiPack(i,i,s,a[i]);  
    }  
          printf("Collection #%d:\n",++t);  
          if(dp[s]==sum-dp[s])  
            printf("Can be divided.\n");  
          else  
            printf("Can't be divided.\n");  
        printf("\n");  
    }  
    return 0;  
}  
