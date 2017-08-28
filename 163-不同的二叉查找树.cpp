#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/unique-binary-search-trees/-163-不同的二叉查找树
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        if (n <= 0) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i + 1; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}