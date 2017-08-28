#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/o1-check-power-of-2/-142-O(1)时间检测2的幂次
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if(n <= 0) {
            return false;
        }
        return n & (n-1) ? false : true;
    }
};

int main()
{
    Solution s;

    cout<<s.checkPowerOf2(4)<<endl;;

    return 0;
}