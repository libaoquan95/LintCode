#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第5章-41-最大子数组
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int maxSub=0x80000000,accSub=0,size=nums.size();

        if(size<=0)
            return 0;

        for(int i=0; i<size; i++)
        {
            if(accSub < 0)
                accSub = nums[i];
            else
                accSub+=nums[i];

            if(accSub > maxSub)
                maxSub = accSub;
        }
        return maxSub;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(2);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(3);

    cout<<s.maxSubArray(nums)<<endl;

    return 0;
}