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
  
const int N = 1 << 16;  
const int INF = 1e8;  
  
string str1, str2, str;  
bool pos;  
int vis[205][205];  
  
void dfs(int s1, int s2, int s)  
{  
    if(s1 == str1.length() && s2 == str2.length())  
    {  
        pos = true;  
        return;  
    }  
    if(str1[s1] != str[s] && str2[s2] != str[s]) return;  
    if(vis[s1][s2]) return;  
    if(pos) return;  
    vis[s1][s2] = 1;  
    if(str1[s1] == str[s]) dfs(s1 + 1, s2, s + 1);  
    if(str2[s2] == str[s]) dfs(s1, s2 + 1, s + 1);  
}  
  
int main()  
{  
  //   freopen("in.txt", "r", stdin);  
    int t, n, Case = 1;  
    scanf("%d", &t);  
    while(t --)  
    {  
        cin >> str1 >> str2 >> str;  
        pos = false;  
        memset(vis, 0, sizeof(vis));  
        dfs(0, 0, 0);  
        if(pos) printf("Data set %d: yes\n", Case ++);  
        else printf("Data set %d: no\n", Case ++);  
    }  
    return 0;  
}  




