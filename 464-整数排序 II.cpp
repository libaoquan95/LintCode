#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-integers-ii/-464-整数排序 II
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 1) {
            return;
        }
        quitSort(A, 0, size - 1);
    }

    void quitSort(vector<int> &A, int left, int right) {
        if (left < right) {
            int i = left, j = right, x = A[i];
            while (i < j) {
                while (i < j && A[j] >= x) {
                    j--;
                }
                if (i < j) {
                    A[i] = A[j];
                    i++;
                }
                while (i < j && A[i] < x) {
                    i++;
                }
                if (i < j) {
                    A[j] = A[i];
                    j--;
                }
            }
            A[i] = x;
            quitSort(A, left, i - 1);
            quitSort(A, i + 1, right);
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    int A[] = { 19,-10,-2,40,3,36,57,25,66,51,5,40,-8,43,9,-5,0,4,55,28,63,67,-2,35,57,0,0,30,17,55,22,34,-4,42,57,52,4,65,6,-2,8,12,31,43,26,34,31,19,-3,36,34,11,58,23,13,7,17,10,33,-5,10,53,14,56,18,8,-6,-2,37,7 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.sortIntegers2(nums);
    s.display(nums);

    return 0;
}