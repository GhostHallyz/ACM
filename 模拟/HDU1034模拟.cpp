/*
һЩѧ��Χ����ʦ����һȦ��ÿ����������һЩ�ǡ�
��ʦһ�����ӣ�ѧ���ͽ��Ƿָ����ֱ�ͬѧ����һ�롣
���һ��ѧ���������Ϊ����������ʦ����һ��������ǣ��ճ�ż����
����ʦҪ�����ٴ�������ʹ��ÿ��ѧ���������������ͬ��
������ڴ������ǵ�������

����ģ��õ��ǵ����������������+1��
ע��߽紦���ж���
���Ƕ࿪��һ������ռ䣬Ȼ��ÿ�κ���ĵõ�ǰ������ǡ�
������Ŀռ��ʼ��Ϊ������Ŀռ䡣
����һ����ģ��ͳ����ˡ�
�ж���ż������λ���㣬%2Ҫ15MS��&1 0MS��
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
                // λ�����ж���ż���϶���%2��  
                if( arr[i]&1 )  ++arr[i];  
            }  
            ++step;  
        }  
        cout<<step<<" "<<arr[1]<<endl;  
    }  
    return 0;  
}  

