#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/happy-number/-488-快乐数
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        // write your code here
        if (n <= 0) {
            return false;
        }

        unordered_map<int, bool> isExisted;

        while (n != 1 && isExisted[n] != true) {
            isExisted[n] = true;
            int n2 = 0;
            while (n != 0) {
                n2 += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = n2;
        }
        if (n == 1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main()
{
    Solution s;

    cout << s.isHappy(196) << endl;

    return 0;
}