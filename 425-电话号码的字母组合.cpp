#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/letter-combinations-of-a-phone-number/-425-电话号码的字母组合
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string digits) {
        // write your code here
        if (digits.size() <= 0) {
            return vector<string>();
        }
        vector<string> result;
        string str;
        letterCombinations(digits, str, 0, result);
        return result;
    }

    void letterCombinations(string &digits, string &str, int index, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(str);
            return;
        }
        string base[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        for (int i = 0; i < base[digits[index] - '0'].size(); i++) {
            str += base[digits[index] - '0'][i];
            letterCombinations(digits, str, index + 1, result);
            str.pop_back();
        }
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(vector<string> &nums) {
        vector<string>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            display(*i);
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    s.display(s.letterCombinations("23"));

    return 0;
}