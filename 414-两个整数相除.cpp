#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/divide-two-integers/-414-两个整数相除
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here
        bool isNeg = false;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            isNeg = true;
        }
        long long result = 0;
        long long d1 = abs((long long)dividend);
        long long d2 = abs((long long)divisor);
        while (d1 >= d2) {
            long long temp = d2;
            long long cnt = 1;
            while (d1 >= temp) {
                d1 -= temp;
                result += cnt;
                cnt = cnt << 1;
                temp = temp << 1;
            }
        }
        if (isNeg) {
            result *= -1;
        }
        if (result < INT_MIN || result > INT_MAX) {
            return INT_MAX;
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.divide(11, 2) << endl;
    return 0;
}