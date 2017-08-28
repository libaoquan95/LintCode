#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/longest-increasing-subsequence/-76-最长上升子序列
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int size = nums.size(), i = 0;
        vector<int> stack;

        if(size <= 0) {
            return 0;
        }

        stack.push_back(nums[0]);
        for(i=1; i<size; i++) {
            if(stack[stack.size()-1] < nums[i]) {
                stack.push_back(nums[i]);
            }
            else {
                int low = 0, high = stack.size()-1, mid = low + (high - low) / 2;
                while(low <= high) {
                    mid = low + (high - low) / 2;
                    if(nums[i] > stack[mid]) {
                        low = mid + 1;
                    }
                    else {
                        high = mid - 1;
                    }
                }
                stack[low] = nums[i];
            }
        }
        return stack.size();
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(10);
    nums.push_back(1);
    nums.push_back(11);
    nums.push_back(2);
    nums.push_back(12);
    nums.push_back(3);
    nums.push_back(11);

    cout<<s.longestIncreasingSubsequence(nums)<<endl;

    return 0;
}