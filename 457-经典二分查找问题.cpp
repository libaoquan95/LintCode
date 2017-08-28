#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/classical-binary-search/-457-经典二分查找问题
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        int size = A.size();
        if (size <= 0) {
            return -1;
        }
        if (target<A[0] || target>A[size - 1]) {
            return -1;
        }
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == A[mid]) {
                return mid;
            }
            else if (target < A[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
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

    int A[] = { 1, 2, 2, 4, 5, 5 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    cout << s.findPosition(nums, 2) << endl;
    cout << s.findPosition(nums, 3) << endl;
    cout << s.findPosition(nums, 5) << endl;
    cout << s.findPosition(nums, 6) << endl;

    return 0;
}