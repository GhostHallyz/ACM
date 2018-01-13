/*N�ʺ�����
Problem Description
��N*N�ķ������̷�����N���ʺ�ʹ�����ǲ��໥������������2���ʺ�������ͬһ�ţ�ͬһ�У�Ҳ�������������̱߿��45�ǵ�б���ϡ�
��������ǣ����ڸ�����N������ж����ֺϷ��ķ��÷�����
Input
���������У�ÿ��һ��������N��10����ʾ���̺ͻʺ�����������N=0����ʾ������
Output
���������У�ÿ��һ������������ʾ��Ӧ�����еĻʺ�Ĳ�ͬ����������
Sample Input
1
8
5
0
Sample Output
1
92
10
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int vis[50],row[50],col[50],P[15];//�������� �I���J�ڴ��������򶼲����лʺ� 
int n, sum;

void  DFS(int row);

int main()
{
    for(n = 1; n <= 10; n++)//�ȴ��Ȼ�ᳬʱ��
    {
        memset(vis,0,sizeof(vis));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        sum = 0;
        DFS(1);
        P[n] = sum;
    }
    while(scanf("%d",&n), n)
    {
        printf("%d\n",P[n]);
    }
    return 0;
}

void  DFS(int k)
{
    int i;
    if(k == n + 1)
    {
        sum ++;
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(vis[k-i+n] == 0 && row[i] == 0 && col[k+i] == 0)
        {
            vis[k-i+n] = row[i] = col[k+i] = 1;//��ֵ
            DFS(k + 1);//����
            vis[k-i+n] = row[i] = col[k+i] = 0;//����
        }
    }
}


