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
     * http://www.lintcode.com/problem/generate-parentheses-427-生成括号
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        if (n <= 0) {
            return vector<string>();
        }
        vector<string> result;
        string temp;
        generateParenthesis(n, temp, result, 0, 0);
        return result;
    }

    void generateParenthesis(int n, string temp, vector<string> &result, int lCount, int rCount) {
        if (lCount == n) {
            for (int i = rCount; i < n; i++) {
                temp += ')';
            }
            result.push_back(temp);
            return;
        }
        generateParenthesis(n, temp + '(', result, lCount + 1, rCount);
        if (lCount > rCount) {
            generateParenthesis(n, temp + ')', result, lCount, rCount + 1);
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

    s.display(s.generateParenthesis(3));

    return 0;
}