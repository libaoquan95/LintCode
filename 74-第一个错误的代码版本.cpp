#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
 */
class SVNRepo {
public:
    static bool isBadVersion(int k) {
        if(k >= 4) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/first-bad-version/-74-第一个错误的代码版本
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        if(n <= 0) {
            return 0;
        }

        int low = 1, high = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(SVNRepo::isBadVersion(mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution s;

    cout<<s.findFirstBadVersion(3)<<endl;
    cout<<s.findFirstBadVersion(4)<<endl;
    cout<<s.findFirstBadVersion(5)<<endl;

    return 0;
}