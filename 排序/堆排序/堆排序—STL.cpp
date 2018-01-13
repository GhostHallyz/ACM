/*
C++�жѵ�Ӧ�ã�make_heap, pop_heap, push_heap, sort_heap

����˵���� 
std::make_heap��[start, end)��Χ���ж�����
	Ĭ��ʹ��less, �����Ԫ�ط��ڵ�һ����

std::pop_heap��front������һ�����Ԫ�أ��ƶ���end��ǰ����
	ͬʱ��ʣ�µ�Ԫ�����¹����(������)һ���µ�heap��

std::push_heap�Ըղ���ģ�β����Ԫ����������

std::sort_heap��һ����������,���ճ�Ϊһ�������ϵ�У�
	���Կ���sort_heapʱ����������һ���ѣ�
	�������ԣ�1�����Ԫ���ڵ�һ�� 2����ӻ���ɾ��Ԫ���Զ���ʱ�䣩��
	��˱�������һ��make_heap.
*/
#include<algorithm>
#include<cstdio>
#include<iostream> 
using namespace std;
bool cmp(int a,int b) //�ȽϺ���
{
    return a>b;
}
int main()
{
    int i,number[20]={29,23,20,22,17,15,26,51,19,12,35,40};
    make_heap(&number[0],&number[12]); //�����:51 35 40 23 29 20 26 22 19 12 17 15
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");
    make_heap(&number[0],&number[12],cmp);//�����12 17 15 19 23 20 26 51 22 29 35 40
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");
    number[12]=8;  //����Ԫ��8  
    push_heap(&number[0],&number[13],cmp); //��������
    //�����8 17 12 19 23 15 26 51 22 35 40 20
    for(i=0;i<13;i++)
 	    printf("%d ",number[i]);
    printf("\n");
    //����Ԫ��8
    pop_heap(&number[0],&number[13],cmp);//�����12 17 15 19 23 20 26 51 22 29 35 40 
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    printf("\n");
    sort_heap(&number[0],&number[12],cmp);
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    return 0;
}
