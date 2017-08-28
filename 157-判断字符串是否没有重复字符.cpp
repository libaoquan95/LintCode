#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/unique-characters/-157-ÅÐ¶Ï×Ö·û´®ÊÇ·ñÃ»ÓÐÖØ¸´×Ö·û
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        int size = str.size();
        if (size <= 0) {
            return true;
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (str[i] == str[j]) {
                    return false;
                }
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
    string str("abc");
    cout << s.isUnique(str) << endl;

    return 0;
}