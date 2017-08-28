#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-substring-without-repeating-characters/-384-最长无重复字符的子串
     * @param : a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int size = s.size();
        if (size <= 1) {
            return size;
        }

        int result = 0, begin = 1;
        map<char, int> map;
        for (int i = 1; i <= size; i++) {
            if (map[s[i - 1]] >= begin) {
                begin = map[s[i - 1]] + 1;
                map[s[i - 1]] = i;
            }
            else {
                map[s[i - 1]] = i;
                result = max(result, i - begin +1);
            }
        }
        return result;
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

    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("aab") << endl;

    return 0;
}