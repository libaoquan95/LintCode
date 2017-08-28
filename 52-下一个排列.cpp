#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-letters-by-case/-52-下一个排列 
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int size = nums.size(), i = 0, j = 0;
        if(size == 0) {
            return vector<int> ();
        }

        for(i=size-1; i>=0; i--)  {
            for(j=size-1; j>i; j--) {
                if(nums[i]<nums[j])  {
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());
                    return nums;  
                }
            }
        }
        sort(nums.begin(),nums.end());
        return nums;  
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);

    vector<int> order;
    order = s.nextPermutation(nums);
    
    vector<int>::iterator i;
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}