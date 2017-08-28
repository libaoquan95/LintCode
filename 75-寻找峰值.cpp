#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/find-peak-element/-75-—∞’“∑Â÷µ
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int size = A.size(), low = 0, high = size-1, mid = 0;
        while(low <= high) {
            mid = (high - low) / 2 + low;
            if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            }
            else if(A[mid] < A[mid - 1]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(6);

    cout<<s.findPeak(nums)<<endl;

    return 0;
}