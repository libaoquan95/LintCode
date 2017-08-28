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
     * http://www.lintcode.com/zh-cn/problem/evaluate-reverse-polish-notation/-424-逆波兰表达式求值
     * @param tokens: The Reverse Polish Notation
     * @return: the value
     */
    int evalRPN(vector<string> tokens) {
        // write your code here
        int size = tokens.size();
        if (size <= 0) {
            return 0;
        }
        stack<int> stack;
        for (int i = 0; i < size; i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stack.push(atoi(tokens[i].c_str()));
            }
            else {
                int num1 = stack.top();
                stack.pop();
                int num2 = stack.top();
                stack.pop();
                int num3 = 0;
                if (tokens[i] == "+") {
                    num3 = num2 + num1;
                }
                else if (tokens[i] == "-") {
                    num3 = num2 - num1;
                }
                else if (tokens[i] == "*") {
                    num3 = num2 * num1;
                }
                else if (tokens[i] == "/") {
                    num3 = num2 / num1;
                }
                stack.push(num3);
            }
        }
        return stack.top();
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

    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    cout << s.evalRPN(tokens) << endl;

    return 0;
}