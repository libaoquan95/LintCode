#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-µÚ5ÕÂ-46-Ö÷ÔªËØ
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int size = nums.size();
        int result, count;

        if(size > 0)
        {
            result = nums[0];
            count = 1;

            for(int i=1; i<size; i++)
            {
                if(count == 0)
                {
                    result = nums[i];
                    count = 1;
                }
                if(result == nums[i])
                    count++;
                else
                    count--;
            }
            return result;
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);

    cout<<s.majorityNumber(nums)<<endl;

    return 0;
}