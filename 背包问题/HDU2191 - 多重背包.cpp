#include<stdio.h>  
#include<string.h>  
int dp[102];  
int p[102],h[102],c[102];  
int n,m;  
void comback(int v,int w)//���ѣ���������ȫ������  
{  
    for(int i=v; i<=n; i++)  
        if(dp[i]<dp[i-v]+w)  
            dp[i]=dp[i-v]+w;  
}  
void oneback(int v,int w)//���ѣ�������01������  
{  
    for(int i=n; i>=v; i--)  
        if(dp[i]<dp[i-v]+w)  
            dp[i]=dp[i-v]+w;  
}  
int main()  
{  
    int ncase,i,j,k;  
    scanf("%d",&ncase);  
    while(ncase--)  
    {  
        memset(dp,0,sizeof(dp));  
        scanf("%d%d",&n,&m);//���ѣ����ࣻ  
        for(i=1; i<=m; i++)  
        {  
            scanf("%d%d%d",&p[i],&h[i],&c[i]);//��ֵ������������;  
            if(p[i]*c[i]>=n) comback(p[i],h[i]);  
            else  
            {  
                for(j=1; j<c[i]; j<<1)  
                {  
                    oneback(j*p[i],j*h[i]);  
                    c[i]=c[i]-j;  
                }  
                oneback(p[i]*c[i],h[i]*c[i]);  
            }  
        }  
        printf("%d\n",dp[n]);  
    }  
    return 0;  
} 
