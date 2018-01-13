/*������ٲ�AC

Problem Description
��������ٲ�AC����
���ǵġ���
�������ʲô�أ���
�������籭ѽ����������
��@#$%^&*%...��
ȷʵ��ˣ����籭���ˣ����ԵĽ���Ҳ���ˣ����ƺܶ�ACMerҲ���׿����ԣ���������ˡ�
��Ϊ���ԣ�һ���뿴������������ı�������Ȼ����Ϊ��ʱ���ĺ����꣬
��һ�����ῴһЩ�����Ľ�Ŀ������������������Զ��Ҫ���ǹ��Ĺ��Ҵ��£���
�ǳ�6+7������Ů�����Լ���СѾ�ġ����Ĵǵ䡷�ȵȣ�
�������Ѿ�֪����������ϲ�����ĵ��ӽ�Ŀ��ת��ʱ�����
��������𣿣�Ŀ�����ܿ��������������Ŀ��
 
Input
�������ݰ����������ʵ����ÿ������ʵ���ĵ�һ��ֻ��һ������n(n<=100)��
��ʾ��ϲ�����Ľ�Ŀ��������Ȼ����n�����ݣ�ÿ�а�����������Ti_s,Ti_e (1<=i<=n)��
�ֱ��ʾ��i����Ŀ�Ŀ�ʼ�ͽ���ʱ�䣬Ϊ�˼����⣬ÿ��ʱ�䶼��һ����������ʾ��
n=0��ʾ�����������������
 
Output
����ÿ������ʵ������������������ĵ��ӽ�Ŀ�ĸ�����ÿ������ʵ�������ռһ�С�
 
Sample Input
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
 
Sample Output
5

*/
#include <iostream>  
#include <string.h>  
#include <algorithm>  
using namespace std;  

struct node
{
	int Tis;
	int Tie;
}pro[110];
int cmp(node a,node b)
{
	return a.Tie<b.Tie;
}
int main()  
{  
	int n,i;
	while(scanf("%d",&n),n)
	{
		int cnt=0, time=0;
		for(i=0; i<n; i++)
			scanf("%d%d",&pro[i].Tis,&pro[i].Tie);
		sort(pro,pro+n,cmp);
//		printf("\n");
//		for(i=0; i<n; i++)
//			printf("%d %d\n",pro[i].Tis,pro[i].Tie);
		cnt=1;
		time=pro[0].Tie;
		for(i=1; i<n; i++)
		{
			if(pro[i].Tis>=time)
			{
				time=pro[i].Tie;
				cnt++;
			}
		}
		printf("%d\n",cnt);	
	} 
    return 0;  
} 
