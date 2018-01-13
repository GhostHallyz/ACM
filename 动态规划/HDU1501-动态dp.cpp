/*Zipper

Problem Description
Given three strings, you are to determine whether the third string 
can be formed by combining the characters in the first two strings. 
The first two strings can be mixed arbitrarily, 
but each must stay in its original order.

For example, consider forming "tcraete" from "cat" and "tree":

String A: cat
String B: tree
String C: tcraete

As you can see, we can form the third string by alternating characters 
from the two strings. As a second example, consider forming "catrtee" from "cat" and "tree":

String A: cat
String B: tree
String C: catrtee

Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
 

Input
The first line of input contains a single positive integer from 1 through 1000. 
It represents the number of data sets to follow. The processing for each data set is identical. 
The data sets appear on the following lines, one data set per line.

For each data set, the line of input consists of three strings, 
separated by a single space. All strings are composed of upper and lower case letters only. 
The length of the third string is always the sum of the lengths of the first two strings.
The first two strings will have lengths between 1 and 200 characters, inclusive.

Output
For each data set, print:
Data set n: yes
if the third string can be formed from the first two, or
Data set n: no
if it cannot. Of course n should be replaced by the data set number. 
See the sample output below for an example.
 
Sample Input
3
cat tree tcraete
cat tree catrtee
cat tree cttaree
 
Sample Output
Data set 1: yes
Data set 2: yes
Data set 3: no

*/

#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
#include <string>  
#include <iostream>  
using namespace std;  
  
const int N = 205;   
char str1[N], str2[N], str[N * 2];  
int dp[N][N];  
  
int main()  
{  
  //   freopen("in.txt", "r", stdin);  
    int t, i, j, Case = 1;  
    scanf("%d", &t);  
    while(t --)  
    {  
        scanf("%s%s%s", str1 + 1, str2 + 1, str + 1); 
		int lens1,lens2;
		lens1= strlen(str1+1);
		lens2= strlen(str2+1);
        memset(dp, 0, sizeof(dp));  
        for(i = 1; i <= lens1; i++)  
        {  
            if(str1[i] == str[i]) 
				dp[i][0] = 1;   
        }  
        for(i = 1; i <= lens2; i++)  
        {  
            if(str2[i] == str[i]) 
				dp[0][i] = 1;   
        }  
        for(i = 1; i <= lens1; i++)  
        {  
            for(j = 1; j <= lens2; j++)  
            {  
                if(dp[i-1][j] && str1[i] == str[i+j]) 
                	dp[i][j] = 1;
				if(dp[i][j-1] && str2[j] == str[i+j])  
            		dp[i][j] = 1;
			}  
        }  
        if(dp[lens1][lens2]) 
			printf("Data set %d: yes\n", Case ++);  
        else 
			printf("Data set %d: no\n", Case ++);  
    }  
    return 0;  
}  
