#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/longest-increasing-continuous-subsequence/-397-最长上升连续子序列
    * @param : An array of Integer
    * @return: an integer
    */
    int longestIncreasingContinuousSubsequence(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }
        vector<int> dp(size, 0);
        dp[0] = 1;
        int maxLeft = dp[0];
        for (int i = 1; i < size; i++) {
            if (A[i] > A[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = 1;
            }
            maxLeft = max(maxLeft, dp[i]);
        }

        dp[size - 1] = 1;
        int maxRight = dp[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            if (A[i] > A[i + 1]) {
                dp[i] = dp[i + 1] + 1;
            }
            else {
                dp[i] = 1;
            }
            maxRight = max(maxRight, dp[i]);
        }
        return max(maxLeft, maxRight);
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

    int A[] = { 5, 4, 2, 1, 3 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    cout << s.longestIncreasingContinuousSubsequence(nums) << endl;

    return 0;
}