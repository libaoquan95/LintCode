#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/coins-in-a-line-ii/-395-硬币排成线 II
     * @param : a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> values) {
        // write your code here
        int size = values.size();
        if (size <= 2) {
            return true;
        }
        vector<int> dp(size + 1, 0);
        int sum = 0;
        dp[size - 1] = values[size - 1];
        dp[size - 2] = values[size - 1] + values[size - 2];
        dp[size - 3] = values[size - 2] + values[size - 3];
        sum += (values[size - 1] + values[size - 2] + values[size - 3]);
        for (int i = size - 4; i >= 0; i--) {
            sum += values[i];
            dp[i] = max(values[i] + min(dp[i + 2], dp[i + 3]), values[i] + values[i + 1] + min(dp[i + 3], dp[i + 4]));
        }
        return dp[0] > sum - dp[0];
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

    int A[] = { 3,2,3,1,2 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    cout << s.firstWillWin(nums) << endl;

    return 0;
}