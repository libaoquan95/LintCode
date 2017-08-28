#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/reverse-integer/-413-反转整数 
     * @param n: the integer to be reversed
     * @return: the reversed integer
     */
    int reverseInteger(int n) {
        // write your code here
        bool isNeg = (n < 0);
        n = abs(n);
        long long res = 0;
        do {
            res *= 10;
            res += n % 10;
            n = n / 10;
        } 
        while (n > 0);
        if (res > INT_MAX) {
            res = 0;
        }
        if (isNeg == true) {
            return -1 * res;
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

    cout << " 1534236469   =>    ";
    cout << s.reverseInteger(1534236469) << endl;
    
    return 0;
}