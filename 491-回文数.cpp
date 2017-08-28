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
     * http://www.lintcode.com/zh-cn/problem/palindrome-number/-491-回文数
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        // write your code here
        if (num <= 0) {
            return false;
        }
        char str[33];
        sprintf(str, "%d", num);
        string s(str);

        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    cout << s.isPalindrome(196) << endl;
    cout << s.isPalindrome(19691) << endl;
    cout << s.isPalindrome(196691) << endl;

    return 0;
}