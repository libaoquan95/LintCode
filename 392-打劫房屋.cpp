#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/problem/house-robber/-392-打劫房屋
    * @param : An array of non-negative integers
    * @return: The maximum amount of money you can rob tonight
    */
    long long houseRobber(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }
        if (size == 1) {
            return A[0];
        }
        long long dp_i_1 = 0, dp_i_2 = 0, dp_i = 0;
        dp_i_2 = A[0];
        dp_i_1 = max(A[0], A[1]);

        for (int i = 2; i < size; i++) {
            dp_i = max(dp_i_1, dp_i_2 + A[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }

    long long houseRobber_N(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }
        if (size == 1) {
            return A[0];
        }
        vector<long long> dp(size, 0);
        dp[0] = A[0];
        dp[1] = max(A[0], A[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
        }
        return dp[size - 1];
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

    cout << s.houseRobber(nums) << endl;

    return 0;
}