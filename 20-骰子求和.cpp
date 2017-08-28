#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/dices-sum/-20-骰子求和
    * @param n an integer
    * @return a list of pair<sum, probability>
    */
    vector<pair<int, double> > dicesSum(int n) {
        // Write your code here
        if (n <= 0) {
            return vector<pair<int, double> >();
        }

        long long total = powOf6(n);
        vector<vector<long long>> dp(n + 1, vector<long long>(6 * n + 1, 0));
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[1][3] = 1;
        dp[1][4] = 1;
        dp[1][5] = 1;
        dp[1][6] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                long x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
                if (j - 1 > 0) {
                    x1 = dp[i - 1][j - 1];
                }
                if (j - 2 > 0) {
                    x2 = dp[i - 1][j - 2];
                }
                if (j - 3 > 0) {
                    x3 = dp[i - 1][j - 3];
                }
                if (j - 4 > 0) {
                    x4 = dp[i - 1][j - 4];
                }
                if (j - 5 > 0) {
                    x5 = dp[i - 1][j - 5];
                }
                if (j - 6 > 0) {
                    x6 = dp[i - 1][j - 6];
                }
                dp[i][j] = x1 + x2 + x3 + x4 + x5 + x6;
            }

        }
        vector<pair<int, double> > result;
        for (int i = n; i <= 6 * n; i++) {
            pair<int, double> p(i, double(dp[n][i]) / total);
            result.push_back(p);
        }
        return result;
    }

    long long powOf6(int n) {
        long long sum = 1;
        for (int i = 0; i<n; i++) {
            sum *= 6;
        }
        return sum;
    }
};

int main()
{
    Solution s;


    vector<pair<int, double> >  matrix;
    vector<pair<int, double> > ::iterator it;

    matrix = s.dicesSum(15);

    for (it = matrix.begin(); it != matrix.end(); it++)
    {
        cout << (*it).first;
        cout << "=>";
        cout << (*it).second;
        cout << endl;
    }

    return 0;
}