#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/remove-element/-172-É¾³ýÔªËØ
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int size = A.size(), elemSize = 0, i = 0;
        if (size <= 0) {
            return 0;
        }

        while (i < size - elemSize) {
            if (A[i] == elem && A[size - 1 - elemSize] != elem) {
                swap(A[i], A[size - 1 - elemSize]);
                elemSize++;
                i++;
            }
            else if (A[i] == elem && A[size - 1 - elemSize] == elem) {
                elemSize++;
            }
            else if (A[i] != elem && A[size - 1 - elemSize] == elem) {
                elemSize++;
                i++;
            }
            else {
                i++;
            }
        }
        for (i = 0; i < elemSize; i++) {
            A.pop_back();
        }
        return size - elemSize;
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

    int A[] = { 0,0,4,0,4,4,2,0,4,5 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << s.removeElement(nums, 4) << endl;
    s.display(nums);

    return 0;
}