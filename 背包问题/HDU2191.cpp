//δ�Ż� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int price[110],weight[110],num[110],dp[1010];

int main()
{
    int c,m,n,i,j,k;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&price[i],&weight[i],&num[i]);        
        }        
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=num[i];j++)
            {
                for(k=n;k>=price[i];k--)
                {
                    dp[k] = max(dp[k],dp[k-price[i]]+weight[i]);
                }
            }
        }
        printf("%d\n",dp[n]);        
    }
    return 0;
}
//ֻ��01�������������Ż� 
#include <iostream> 
#include <string.h> 
using namespace std;  
int main()  
{  
    int nCase,Limit,nKind,i,j,k,  v[111],w[111],c[111],dp[111];  
    //v[]���ֵ��w[]��ߴ磬c[]�����  
    //�ڱ����У���ֵ���׵��������ߴ����׵ļ۸�  
    int count,Value[1111],size[1111];  
    //count�洢�ֽ�������Ʒ����  
    //Value�洢�ֽ����ÿ����Ʒ�ļ�ֵ  
    //size�洢�ֽ����ÿ����Ʒ�ĳߴ�  
    cin>>nCase;  
    while(nCase--)  
    {  
        count=0;  
        cin>>Limit>>nKind;  
        for(i=0; i<nKind; i++)  
        {  
            cin>>w[i]>>v[i]>>c[i];  
            //�Ը������c[i]����Ʒ���ж����Ʒֽ�  
            for(j=1; j<=c[i]; j<<=1)  
            {  
                //<<����1λ���൱�ڳ�2  
                Value[count]=j*v[i];  
                size[count++]=j*w[i];  
                c[i]-=j;  
            }  
            if(c[i]>0)  
            {  
                Value[count]=c[i]*v[i];  
                size[count++]=c[i]*w[i];  
            }  
        }  
        //���������ÿһ����Ʒ�ķֽ⣬  
        //����Value[]��ľ��Ƿֽ�����Ʒ��ֵ  
        //size[]��ľ��Ƿֽ�����Ʒ�ߴ�  
        //count���൱��ԭ����n  
        //�����ֱ����01�����㷨����  
        memset(dp,0,sizeof(dp));  
        for(i=0; i<count; i++)  
            for(j=Limit; j>=size[i]; j--)  
                if(dp[j]<dp[j-size[i]]+Value[i])  
                    dp[j]=dp[j-size[i]]+Value[i];  
  
        cout<<dp[Limit]<<endl;  
    }  
    return 0;  
}  
