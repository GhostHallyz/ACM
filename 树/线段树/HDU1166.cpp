/*�б�����

Problem Description
C��������ͷA�����ʱ�����ڽ��о�����ϰ������C�����ͷ��Derek��������Tidy�ֿ�ʼæ���ˡ�
A���ں�������ֱ�߲�����N������Ӫ��,Derek��Tidy���������Ҫ������Щ����Ӫ�صĻ�����
���ڲ�ȡ��ĳ���Ƚ��ļ���ֶΣ�����ÿ������Ӫ�ص�����C�������յ�һ�����,
ÿ������Ӫ�ص��������п��ܷ����䶯���������ӻ������������,����Щ���Ӳ���C���ļ��ӡ�
�����鱨��Ҫ�о����˾�����ϰʲôս��,����TidyҪ��ʱ��Derek�㱨ĳһ�������Ĺ���Ӫ��һ���ж�����,
����Derek��:��Tidy,���ϻ㱨��3��Ӫ�ص���10��Ӫ�ع��ж�����!��Tidy��Ҫ���Ͽ�ʼ������һ�ε����������㱨��
���б�Ӫ�ص����������䶯����Derekÿ��ѯ�ʵĶζ���һ��������Tidy���ò�ÿ�ζ�һ��һ��Ӫ�ص�ȥ����
�ܿ�;�ƣ�����ˣ�Derek��Tidy�ļ����ٶ�Խ��Խ����:"��������У������ô�����ҳ�������!��
Tidy�룺�����Լ������㿴���������һ�����˵Ĺ���!�Һ޲����㳴��������!������֮�£�
Tidyֻ�ô�绰������ר��Windbreaker���,Windbreaker˵���������У�����ƽʱ�����acm��Ϳ�����㷨�飬
���ڳ�������˰�!��Tidy˵��"��֪���ˡ�����"��Windbreaker�Ѿ��ҵ��绰�ˡ�Tidy�ܿ��գ�
��ô������Ļ�����ģ������Ķ��ߣ�����д������������������𣿲��������ĳ���Ч�ʲ����ߵĻ���
Tidy���ǻ��ܵ�Derek�������.

Input
��һ��һ������T����ʾ��T�����ݡ�
ÿ�����ݵ�һ��һ��������N��N<=50000��,��ʾ������N������Ӫ�أ�
��������N��������,��i��������ai�����i������Ӫ���￪ʼʱ��ai���ˣ�1<=ai<=50����
������ÿ����һ�����������4����ʽ��
(1) Add i j,i��jΪ������,��ʾ��i��Ӫ������j���ˣ�j������30��
(2)Sub i j ,i��jΪ������,��ʾ��i��Ӫ�ؼ���j���ˣ�j������30��;
(3)Query i j ,i��jΪ������,i<=j����ʾѯ�ʵ�i����j��Ӫ�ص�������;
(4)End ��ʾ����������������ÿ������������;
ÿ�����������40000������

Output
�Ե�i������,���������Case i:���ͻس�,
����ÿ��Queryѯ�ʣ����һ���������س�,��ʾѯ�ʵĶ��е�������,�����������int���ڡ�

Sample Input
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 

Sample Output
Case 1:
6
33
59

*/
#include<iostream>   
#include<algorithm>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>   
#include<cmath>   
using namespace std;
  
int sum,n;   
struct node  
{  
    int l,r,n;  
} a[1000000];  
  
void init()//�½�һ���߶���  
{  
    int i,k;  
    for(k = 1; k<n; k<<=1);  
    for(i = k; i<2*k; i++)  
    {  
        a[i].l = a[i].r = i-k+1;  
        a[i].n = 0;  
    }  
    for(i = k-1; i>0; i--)  
    {  
        a[i].l = a[2*i].l;  
        a[i].r = a[2*i+1].r;  
        a[i].n = 0;  
    }  
}  
  
void insert(int i,int x,int m)//�߶����Ĳ���  
{  
    if(x>=a[i].l && x<=a[i].r)  
        a[i].n+=m;  
    if(a[i].l == a[i].r)  
        return ;  
    int mid = (a[i].l+a[i].r)/2;  
    if(x>mid)  
        insert(2*i+1,x,m);  
    else  
        insert(2*i,x,m);  
}  
  
void find(int x,int y,int i)//�߶����Ĳ�ѯ  
{  
    if(a[i].l == x && a[i].r == y)  
    {  
        sum+=a[i].n;  
        return ;  
    }  
    if(a[i].l == a[i].r)  
        return ;  
    int mid = (a[i].l+a[i].r)/2;  
    if(x>mid)  
        find(x,y,2*i+1);  
    else if(y<=mid)  
        find(x,y,2*i);  
    else  
    {  
        find(x,mid,2*i);  
        find(mid+1,y,2*i+1);  
    }  
}  
  
int main()  
{  
    int t,cas = 1,x,y,i,j,k;  
    char str[10];  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        init();  
        for(i = 1; i<=n; i++)  
        {  
            scanf("%d",&k);  
            insert(1,i,k);  
        }  
        printf("Case %d:\n",cas++);  
        while(scanf("%s",str) && str[0]!='E')  
        {  
            scanf("%d%d",&x,&y);  
            if(!strcmp(str,"Add"))  
                insert(1,x,y);  
            else if(!strcmp(str,"Sub"))  
                insert(1,x,-y);  
            else if(!strcmp(str,"Query"))  
            {  
                sum = 0;  
                find(x,y,1);  
                printf("%d\n",sum);  
            }  
        }  
    }  
    return 0;  
}  


