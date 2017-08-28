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
    * http://www.lintcode.com/zh-cn/problem/decode-ways/-512-解码方法
    * @param s: a string,  encoded message
    * @return: an integer, the number of ways decoding
    */
    int numDecodings(string s) {
        // write your code here
        int size = s.size();
        if (size <= 0) {
            return 0;
        }
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= size; i++) {
            if (s[i - 1] == '0') {
                dp[i] = 0;
            }
            else {
                dp[i] += dp[i - 1];
            }
            if (i > 1) {
                int num = atoi(s.substr(i - 2, 2).c_str());
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[size];
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

    cout << s.numDecodings("19261001") << endl;

    return 0;
}