#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/roman-to-integer/-419-罗马数字转整数
     * @param n: The integer
     * @return: Roman representation
     */
    int romanToInt(string s) {
        // write your code here
        int res = 0;
        unordered_map<char, int> m{ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L', 50 },{ 'C', 100 },{ 'D', 500 },{ 'M', 1000 } };
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || m[s[i]] <= m[s[i - 1]]) {
                res += m[s[i]];
            }
            else {
                res += m[s[i]] - 2 * m[s[i - 1]];
            }
        }
        return res;
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
    
    cout << s.romanToInt("XII") << endl;
    return 0;
}