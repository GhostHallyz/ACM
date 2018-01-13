#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring> 
#include<iomanip> 
using namespace std;
int vis[100005];

char change(char a)
{
	switch(a)  
    {  
	    case 'A':  
	    case 'B':  
	    case 'C': return '2';  
	    case 'D':  
	    case 'E':  
	    case 'F': return '3';  
	    case 'G':  
	    case 'H':  
	    case 'I': return '4';  
	    case 'J':  
	    case 'K':  
	    case 'L': return '5';  
	    case 'M':  
	    case 'N':  
	    case 'O': return '6';  
	    case 'P':  
	    case 'R':  
	    case 'S': return '7';  
	    case 'T':  
	    case 'U':  
	    case 'V': return '8';  
	    case 'W':  
	    case 'X':  
	    case 'Y': return '9';  
	    default: return a;  
    }  
}

int getnum(char str[])
{
	int temp=0;
	for(int i=0; i < 7; i++) 
		temp=temp*10+str[i]-'0'; 
	return temp;
}
int main()
{
	int n,len,i,j,k,m;
	char str[20];
    while(cin >>n)
    {
    	memset(vis,0,sizeof(vis));
		m=0;
  		for(i=0; i<n; i++)
  		{	
  			cin >> str;
  			len = strlen(str);
			for( j=0; j<len; j++)
			{
				if(str[j]=='-')
					continue;
				else
				{ 
					vis[m]=vis[m]*10+change(str[j])-'0';
				} 
			}	
			//cout << vis[m] <<endl; 
			m++;		
		}
		sort(vis,vis+n);
		for(i=0;i<n;i++)
		{
			k =1;
			while(vis[i]==vis[i+1])
			{
				k++;
				i++;
				m=0;
			}
			if(k>1)
				cout<<setfill('0')<<setw(3)<<vis[i]/10000 <<"-"<<setfill('0')<<setw(4)<<vis[i]%10000 << " " << k << endl;
		}
		if(m!=0)
			cout << "No duplicates.\n" << endl;
    } 
    return 0;
}
