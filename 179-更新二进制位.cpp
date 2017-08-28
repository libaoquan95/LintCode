#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/update-bits/-179-更新二进制位
     * @param n, m: Two integer
     * @param i, j: Two bit positions
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        for (int pos = i; pos <= j; ++pos) {
            n &= ~(1 << pos);
        }
        m <<= i;
        return n | m;
    }
};

int main()
{
    Solution s;

    cout << s.updateBits(0x10000000000, 0x10101, 2, 6) << endl;

    return 0;
}