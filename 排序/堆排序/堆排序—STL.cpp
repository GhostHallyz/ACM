/*
C++中堆的应用：make_heap, pop_heap, push_heap, sort_heap

函数说明： 
std::make_heap将[start, end)范围进行堆排序，
	默认使用less, 即最大元素放在第一个。

std::pop_heap将front（即第一个最大元素）移动到end的前部，
	同时将剩下的元素重新构造成(堆排序)一个新的heap。

std::push_heap对刚插入的（尾部）元素做堆排序。

std::sort_heap将一个堆做排序,最终成为一个有序的系列，
	可以看到sort_heap时，必须先是一个堆（
	两个特性：1、最大元素在第一个 2、添加或者删除元素以对数时间），
	因此必须先做一次make_heap.
*/
#include<algorithm>
#include<cstdio>
#include<iostream> 
using namespace std;
bool cmp(int a,int b) //比较函数
{
    return a>b;
}
int main()
{
    int i,number[20]={29,23,20,22,17,15,26,51,19,12,35,40};
    make_heap(&number[0],&number[12]); //结果是:51 35 40 23 29 20 26 22 19 12 17 15
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");
    make_heap(&number[0],&number[12],cmp);//结果：12 17 15 19 23 20 26 51 22 29 35 40
    for(i=0;i<12;i++)
        printf("%d ",number[i]);
    printf("\n");
    number[12]=8;  //加入元素8  
    push_heap(&number[0],&number[13],cmp); //加入后调整
    //结果：8 17 12 19 23 15 26 51 22 35 40 20
    for(i=0;i<13;i++)
 	    printf("%d ",number[i]);
    printf("\n");
    //弹出元素8
    pop_heap(&number[0],&number[13],cmp);//结果：12 17 15 19 23 20 26 51 22 29 35 40 
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    printf("\n");
    sort_heap(&number[0],&number[12],cmp);
    for(i=0;i<13;i++)
        printf("%d ",number[i]);
    return 0;
}
