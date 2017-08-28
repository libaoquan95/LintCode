#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/perfect-squares/-513-完美平方
    * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        // write your code here
        if (n <= 0) {
            return 0;
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            int sqr = sqrt(i);
            if (sqr * sqr == i) {
                dp[i] = 1;
            }
            else {
                for (int j = 1; j <= i / 2; j++) {
                    dp[i] = min(dp[j] + dp[i - j], dp[i]);
                }
            }
        }
        return dp[n];
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    cout << s.numSquares(12) << endl;

    return 0;
}