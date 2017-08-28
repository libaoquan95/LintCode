#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/valid-palindrome/-415-有效回文串
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string s) {
        // write your code here
        int size = s.size();
        if (size <= 0) {
            return true;
        }
        int cur = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] <= 'Z' && s[i] >= 'A') {
                s[cur] = s[i] - 'A' + 'a';
                cur++;;
            }
            else if (s[i] <= 'z' && s[i] >= 'a' || s[i] <= '9' && s[i] >= '0') {
                s[cur] = s[i];
                cur++;
            }
        }
        for (int i = 0; i < cur / 2; i++) {
            if (s[i] != s[cur - 1 - i]) {
                return false;
            }
        }
        return true;
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
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}