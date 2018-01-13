#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
#define parent(i) (i)/2  
#define left(i) 2*(i)  
#define right(i) 2*(i)+1  
  
int size;  
  
void heapify(int a[], int i)  
{  
    int l = left(i), r = right(i), largest;  
    if(l<=size && a[l] > a[i])  
        largest = l;  
    else largest = i;  
    if(r<=size && a[r] > a[largest])  
        largest = r;  
    if(largest != i)  
    {  
        int t = a[i];  
        a[i] = a[largest];  
        a[largest] = t;  
        heapify(a, largest);  
    }  
}  
  
void build_heap(int a[])  
{  
    int len = size;  
    for(int i=len/2; i>=1; i--)  
        heapify(a, i);  
}  
  
void heap_sort(int a[])  
{  
    build_heap(a);  
    for(int i=size; i>=2; i--)  
    {  
        int t = a[1]; a[1] = a[i]; a[i] = t;  
        size--;  
        heapify(a, 1);  
    }  
}  
  
int main()  
{  
    int a[20];  
    printf("请输入数据个数：\n");  
    scanf("%d", &size);  
    int len = size;  
    printf("请输入%d个你要排序的数：\n", size);  
    for(int i=1; i<=size; i++)  
        scanf("%d", &a[i]);  
    heap_sort(a);  
    for(int i=1; i<len; i++)  
        printf("%d ", a[i]);  
    printf("%d\n", a[len]);  
    return 0;  
}  
