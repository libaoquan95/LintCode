#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/problem/count-and-say/-420-报数
    *  @param n: the nth
    * @return: the nth sequence
    */
    string countAndSay(int n) {
        // write your code here
        if (n <= 0) {
            return string("");
        }
        string result("1");
        for (int i = 1; i < n; i++) {
            string temp;
            int count = 1, j;
            for (j = 0; j < result.size() - 1; j++) {
                if (result[j] == result[j + 1]) {
                    count++;
                }
                else{
                    temp += ('0' + count);
                    temp += result[j];
                    count = 1;
                }
            }
            if (j > 0 && result[j] == result[j - 1]) {
                temp += ('0' + count);
                temp += result[j];
            }
            else if (j == 0) {
                temp += '1';
                temp += result[j];
            }
            else {
                temp += '1';
                temp += result[j];
            }
            result = temp;
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
    for (int i = 1; i < 10; i++) {
        cout << i << "   ";
        s.display(s.countAndSay(i));
    }
    return 0;
}