#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/merge-sorted-array/-64-合并排序数组 II 
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int size = m + n, i = 0, a = m-1, b = n-1;
        for(i=size-1; i>=0; i--){
            if(A[a] <= B[b]) {
                A[i] = B[b];
                b--;
            }
            else {
                A[i] = A[a];
                a--;
            }
        }
    }

    void displayVector(int order[], int num) {
        for(int i=0; i!=num; i++) {
            cout<<order[i]<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    int A[10] = {1, 2, 3, 0, 0};
    int B[10] = {4, 5, 0, 0, 0};

    s.displayVector(A, 3);
    s.displayVector(B, 2);
    s.mergeSortedArray(A, 3, B, 2);
    s.displayVector(A, 5);

    return 0;
}