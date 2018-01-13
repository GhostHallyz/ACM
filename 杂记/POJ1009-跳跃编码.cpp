#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
using namespace std;
int n,sum,len,sticks[65];
bool flag,vis[65];

bool cmp(int a,int b)
{
	return a>b;
}
void dfs(int dep, int now_len, int u) // depΪ��ǰ�ѱ��ù���С������uΪ��ǰҪ�����С����
{  
    if(flag) return;
    if(now_len == 0)//  ��ǰ����Ϊ0��Ѱ����һ����ǰ�С����
	{                    
        int k = 0;
        while(vis[k]) k++;  //  Ѱ�ҵ�һ����ǰ�С����
		
        vis[k] = true;
        dfs(dep + 1, sticks[k], k + 1);
        vis[k] = false;
        return;
    }
    if(now_len == len) //  ��ǰ����Ϊlen������ƴ�ճ���һ��ԭ����
	{                 
        if(dep == n) //  ��ɵı�־�����е�n��С������ƴ���ˡ�
			flag = true;  	
        else 
			dfs(dep, 0, 0);
        return;
    }
    for(int i = u; i < n; i++)
        if(!vis[i] && now_len + sticks[i] <= len)
		{
            if(!vis[i-1] && sticks[i] == sticks[i-1]) continue;      //  ���ظ�����������Ҫ�ļ�֦��
            vis[i] = true;
            dfs(dep + 1, now_len + sticks[i], i + 1);
            vis[i] = false;
        }
}
int main()
{      
    while (~scanf("%d",&n),n)
    {
		sum=0;
		flag=false;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&sticks[i]);
			sum += sticks[i];
		}
		sort(sticks,sticks+n,cmp);	
		for(len=sticks[0]; len<sum; len++)
			if(sum%len==0)
			{
				memset(vis,0,sizeof(vis));
				dfs( 0, 0, 0);
				if(flag) break;
			}
		printf("%d\n",len);
    }
    return 0;
}
