/*
一些学生围着老师坐成一圈，每个人手里有一些糖。
老师一吹哨子，学生就将糖分给右手边同学，分一半。
如果一个学生手里的糖为奇数，则老师给他一个额外的糖，凑成偶数。
问老师要吹多少次哨子能使得每个学生手里的糖数量相同。
输出吹哨次数与糖的数量。

就是模拟得到糖的情况，若是奇数则+1。
注意边界处的判定。
我是多开了一块数组空间，然后，每次后面的得到前面的人糖。
最左面的空间初始化为最右面的空间。
这样一步步模拟就出来了。
判断奇偶还是用位运算，%2要15MS，&1 0MS。
*/ 

#include <iostream>  
using namespace std;  
int arr[100001];  
bool judge(int n)  
{  
    int i;  
    for(i=2;i<=n;++i)  
        if( arr[1]!=arr[i] )  
            return false;  
    return true;  
}  
int main()  
{  
    int i,test,step;  
    while( cin>>test && test )  
    {  
        for(i=1;i<=test;++i)  
            cin>>arr[i];  
        step=0;  
        while( !judge(test) )  
        {  
            arr[0]=arr[test];  
            for(i=test;i>0;--i)  
            {  
                arr[i]=(arr[i-1]/2+arr[i]/2);  
                // 位运算判断奇偶，肯定比%2快  
                if( arr[i]&1 )  ++arr[i];  
            }  
            ++step;  
        }  
        cout<<step<<" "<<arr[1]<<endl;  
    }  
    return 0;  
}  

