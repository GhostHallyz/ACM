#include<stdio.h>  
int main()  
{  
    int number[10]={4,2,1,7,5,9,8,6,10,3};  
    int i,j,temp;  
    printf("before order:\n");  
    for(i=0;i<10;i++)  
        printf("%d ",number[i]);  
    for(i=0;i<10;i++)  
        for(j=i+1;j<10;j++)  
	    {  
	        if(number[i]>number[j])//大于升序，小于降序  
	        {  
	            temp=number[i];  
	            number[i]=number[j];  
	            number[j]=temp;  
	        }  
	    }  
    printf("\nafter order:\n");  
    for(i=0;i<10;i++)  
        printf("%d ",number[i]);  
    return 0;  
}  
