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
     * http://www.lintcode.com/zh-cn/problem/sort-integers/-463-整数排序
     * @param A: an integer array
     * @return: 
     */
    void sortIntegers(vector<int> &A) {
        // write your code here
        int size = A.size();
        if (size <= 1) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j > 0; j--) {
                if (A[j] < A[j - 1]) {
                    swap(A[j], A[j - 1]);
                }
                else {
                    break;
                }
            }
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

    int A[] = { 3, 2, 1, 4, 5 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.sortIntegers(nums);
    s.display(nums);

    return 0;
}