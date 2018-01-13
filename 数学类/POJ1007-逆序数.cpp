#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring> 
using namespace std;
int p,e,k,d,sum;  
int r1,r2,r3,r;  
  
void slove()//求出r1,r2,r3,r;  
{  
    int i;  
    for (i=1, r1=28*33; ; i++)  
        if (r1*i%23==1) break;  
    r1 *= i;  
    for (i=1, r2=23*33; ; i++)  
        if (r2*i%28==1) break;  
    r2 *= i;  
    for (i=1, r3=23*28; ; i++)  
        if (r3*i%33==1) break;  
    r3 *= i;  
    r = 23*28*33;  
}  
  
int main ()  
{  
    int ii=1;  
    slove();  
    //cout<<r1<<" "<<r2<<" "<<r3<<" "<<r<<endl;  
    while (scanf ("%d%d%d%d",&p,&e,&k,&d)==4)  
    {  
        if (p==-1&&e==-1&&k==-1&&d==-1)  
            break;  
        sum = (r1*p+r2*e+r3*k-d)%r;//中国剩余定理求解  
        sum = (sum+r-1)%r+1;//可能会出现负数  
        printf ("Case %d: the next triple peak occurs in %d days.\n",ii++, sum);  
    }  
    return 0;  
}  
