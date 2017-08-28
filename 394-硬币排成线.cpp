#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/coins-in-a-line/-394-硬币排成线
    * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        return n % 3 != 0;
    }
};

int main()
{
    Solution s;

    cout << s.firstWillWin(5) << endl;

    return 0;
}