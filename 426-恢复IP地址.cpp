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
     * http://www.lintcode.com/problem/restore-ip-addresses/-426-恢复IP地址
     *  @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string s) {
        // write your code here
        if (s.size() < 4 || s.size() > 12) {
            return vector<string>();
        }
        vector<string> result;
        vector<string> temp;
        restoreIpAddresses(s, result, temp, 0);
        return result;
    }

    void restoreIpAddresses(string s, vector<string> &result, vector<string> &temp, int start) {
        if (temp.size() == 4 && start == s.size()) {
            result.push_back(temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3]);
            return;
        }
        else if (temp.size() == 4 && start != s.size()) {
            return;
        }
        for (int i = start; i < s.size() && i < start + 3; i++) {
            if (isValid(s.substr(start, i - start + 1))) {
                temp.push_back(s.substr(start, i - start + 1));
                restoreIpAddresses(s, result, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    bool isValid(string s) {
        if (s[0] == '0') {
            return s == "0";
        }
        int digit = atoi(s.c_str());
        return digit >= 0 && digit <= 255;
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

    s.display(s.restoreIpAddresses("25525511135"));

    return 0;
}