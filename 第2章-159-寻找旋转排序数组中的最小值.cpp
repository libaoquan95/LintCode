#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第2章-159-寻找旋转排序数组中的最小值
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size == 0)
            return 0;

        int min = nums[0];
        for(int i=1; i<size; i++)
        {
            if(min > nums[i])
                min = nums[i];
        }
        return min;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(4);nums.push_back(5);nums.push_back(6);nums.push_back(7);
    //nums.push_back(8);nums.push_back(1);nums.push_back(2);nums.push_back(3);

    s.display(nums);
    cout<<s.findMin(nums)<<endl;

    return 0;
}