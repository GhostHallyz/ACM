#include<stdio.h>
#include<algorithm> 
void quick_sort(int s[], int l, int r) 
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1  
        int i = l, j = r, x = s[l];  //i，j一开始分别指向左右边界，并将做边界的数值记录下来 
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数  
                j--;  
            if(i < j)  
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数  
                i++;    
            if(i < j)   
                s[j--] = s[i]; 	
        }  
        s[i] = x; 	   	
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);  
    }  
}  
void qsort(int a[],int l,int r)   //a[]代表无序数组，l代表左边界，r代表右边界  
{  
    int x = a[l],i = l,j = r;     //i，j一开始分别指向左右边界，并将做边界的数值记录下来  
    if(l >= r) return ;           //当区间只有一个数值时，本身就是有序的，此刻就不需要递归了  
    while(i < j)  
    {  
        while(i < j && a[j] >= x) j--;    //从右边界开始判断，如果大于x值，j往左移，如果遇见小于的话，跳出循环  
        a[i] = a[j];                     //跳出循环后，将后面小于x的值，移动到前面去  
        while(i < j && a[i] <= x) i++;       
        a[j] = a[i];  
    }  
    a[i] = x;                //当i=j时，将x的值赋值到a[i]上去，这时比x小的都在左边，比x大的都在右边  
    qsort(a,l,i-1);           //从a[i]，分开，递归判断左边的数值和右边的数值  
    qsort(a,i+1,r);  
}  
int main()
{
	int a[5],i=1;
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	getchar();
	scanf("%d",&a[0]);
	quick_sort(a,0,i-1);
	for(i=0;i<5;i++)
		printf("%d ",a[i]);
	return 0; 
}
