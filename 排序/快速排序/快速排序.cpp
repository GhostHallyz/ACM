#include<stdio.h>
#include<algorithm> 
void quick_sort(int s[], int l, int r) 
{  
    if (l < r)  
    {  
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1  
        int i = l, j = r, x = s[l];  //i��jһ��ʼ�ֱ�ָ�����ұ߽磬�������߽����ֵ��¼���� 
        while (i < j)  
        {  
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����  
                j--;  
            if(i < j)  
                s[i++] = s[j];  
              
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����  
                i++;    
            if(i < j)   
                s[j--] = s[i]; 	
        }  
        s[i] = x; 	   	
        quick_sort(s, l, i - 1); // �ݹ���� 
        quick_sort(s, i + 1, r);  
    }  
}  
void qsort(int a[],int l,int r)   //a[]�����������飬l������߽磬r�����ұ߽�  
{  
    int x = a[l],i = l,j = r;     //i��jһ��ʼ�ֱ�ָ�����ұ߽磬�������߽����ֵ��¼����  
    if(l >= r) return ;           //������ֻ��һ����ֵʱ�������������ģ��˿̾Ͳ���Ҫ�ݹ���  
    while(i < j)  
    {  
        while(i < j && a[j] >= x) j--;    //���ұ߽翪ʼ�жϣ��������xֵ��j�����ƣ��������С�ڵĻ�������ѭ��  
        a[i] = a[j];                     //����ѭ���󣬽�����С��x��ֵ���ƶ���ǰ��ȥ  
        while(i < j && a[i] <= x) i++;       
        a[j] = a[i];  
    }  
    a[i] = x;                //��i=jʱ����x��ֵ��ֵ��a[i]��ȥ����ʱ��xС�Ķ�����ߣ���x��Ķ����ұ�  
    qsort(a,l,i-1);           //��a[i]���ֿ����ݹ��ж���ߵ���ֵ���ұߵ���ֵ  
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
