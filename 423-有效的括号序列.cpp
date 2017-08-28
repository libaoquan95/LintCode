#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/valid-parentheses/-423-有效的括号序列
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string s) {
        // write your code here
        int size = s.size();
        if (size <= 0) {
            return true;
        }
        stack<char> stack;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                char top = stack.top();
                if ((s[i] == ')' && top == '(') || (s[i] == ']' && top == '[') || (s[i] == '}' && top == '{')) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (!stack.empty()) {
            return false;
        }
        return true;
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

    cout << s.isValidParentheses("()[]{}") << endl;
    cout << s.isValidParentheses("([)]") << endl;

    return 0;
}