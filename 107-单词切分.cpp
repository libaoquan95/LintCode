#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/word-break/-107-单词切分
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string s, unordered_set<string> dict) {
        // write your code here
        int sizeS = s.size(), sizeD = dict.size();
        if (sizeS == 0 && sizeD == 0) {
            return true;
        }
        if (sizeS == 0 || sizeD == 0) {
            return false;
        }
        vector<bool> dp(sizeS + 1, false);
        dp[0] = true;
        for (int i = 0; i < sizeS; i++) {
            for (string str : dict ) {
                if (dp[i] == true && i + str.size() <= sizeS && s.substr(i, str.size()) == str) {
                    dp[i + str.size()] = true;
                }
            }
        }
        return dp[sizeS];
    }
};

int main()
{
    Solution s;
    string str("lintcode");
    unordered_set<string> dict;
    dict.insert("lint");
    dict.insert("code");

    cout << s.wordBreak(str, dict) << endl;

    return 0;
}