#include <iostream>  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN], T[MAXN];  
  
void merge_sort(int *A, int x, int y, int *T) {  
    if(y - x > 1) {  
        int m = x + (y - x) / 2;     //划分  
        int p = x, q = m, i = x;  
        merge_sort(A, x, m, T);      //递归求解  
        merge_sort(A, m, y, T);      //递归求解  
        while(p < m || q < y) {  
            if(q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];   //从左半数组复制到临时空间  
            else T[i++] = A[q++];    //从右半数组复制到临时空间  
        }  
        for(i = x; i < y; ++i) A[i] = T[i];   //从辅助空间复制回A数组  
    }  
}  
  
int main() {  
    int n;  
    cin >> n;  
    for(int i = 0; i < n; ++i) cin >> A[i];  
    merge_sort(A, 0, n, T);  
    for(int i = 0; i < n; ++i) cout << A[i] << endl;  
    return 0;  
}  
