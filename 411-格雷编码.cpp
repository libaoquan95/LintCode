#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/gray-code/-411-格雷编码 
     * @param n: a number
     * @return: Gray code
     */
    vector<int> grayCode(int n) {
        // write your code here
        if (n <= 0) {
            return vector<int>(1, 0);
        }

        vector<string> strs = grayCodeOfString(n);
        vector<int> result;
        for (int i = 0; i < strs.size(); i++) {
            result.push_back(bitStringToInt(strs[i]));
        }

        display(strs);
        return result;
    }

    vector<string> grayCodeOfString(int n) {
        vector<string> strs(pow(2, n), "");
        if (n == 1) {
            strs[0] = "0";
            strs[1] = "1";
            return strs;
        }
        vector<string> last = grayCodeOfString(n - 1);

        for (int i = 0; i < last.size(); i++) {
            strs[i] = "0" + last[i];
            strs[strs.size() - 1 - i] = "1" + last[i];
        }
        return strs;
    }

    int bitStringToInt(string str) {
        int result = 0, pow = 1;
        for (int i = str.size() - 1; i >= 0; i--) {
            result += ((str[i] - '0') * pow);
            pow *= 2;
        }
        return result;
    }

    void display(string s) {
        for (int i = 0; i<s.size(); i++) {
            cout << s[i];
        }
        cout << endl;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
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

    s.display(s.grayCode(2));
    
    return 0;
}