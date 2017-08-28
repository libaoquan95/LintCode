#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/integer-to-roman/-418-整数转罗马数字
     * @param n: The integer
     * @return: Roman representation
     */
    string intToRoman(int n) {
        // write your code here
        if (n < 1 || n> 3999) {
            return "";
        }
        char* c[4][10] = {
            { "","I","II","III","IV","V","VI","VII","VIII","IX" },
            { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
            { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
            { "","M","MM","MMM" }
        };
        string roman;

        roman.append(c[3][n / 1000 % 10]);
        roman.append(c[2][n / 100 % 10]);
        roman.append(c[1][n / 10 % 10]);
        roman.append(c[0][n % 10]);

        return roman;
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
    
    s.display(s.intToRoman(2));
    return 0;
}