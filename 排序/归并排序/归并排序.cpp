#include <iostream>  
using namespace std;  
  
const int MAXN = 1000;  
int A[MAXN], T[MAXN];  
  
void merge_sort(int *A, int x, int y, int *T) {  
    if(y - x > 1) {  
        int m = x + (y - x) / 2;     //����  
        int p = x, q = m, i = x;  
        merge_sort(A, x, m, T);      //�ݹ����  
        merge_sort(A, m, y, T);      //�ݹ����  
        while(p < m || q < y) {  
            if(q >= y || (p < m && A[p] <= A[q])) T[i++] = A[p++];   //��������鸴�Ƶ���ʱ�ռ�  
            else T[i++] = A[q++];    //���Ұ����鸴�Ƶ���ʱ�ռ�  
        }  
        for(i = x; i < y; ++i) A[i] = T[i];   //�Ӹ����ռ临�ƻ�A����  
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
