#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/problem/flip-bits/-181-将整数A转换为B
     * @param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int diff = 0, pos = 1;
        for (int i = 0; i < 32; i++) {
            if ((a & pos) != (b & pos)) {
                diff++;
            }
            pos = pos << 1;
        }
        return diff;
    }
};

int main()
{
    Solution s;

    cout << s.bitSwapRequired(31, 4) << endl;

    return 0;
}