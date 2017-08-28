#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/-42-最大子数组 II 
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        int size = nums.size(), i = 0, sum = 0, maxValue = 0;
        int *left = new int[size];

        sum = maxValue = left[0] = nums[0];
        for(i=1; i<size; i++) {
            if(sum < 0) {
                sum = nums[i];
            }
            else {
                sum += nums[i];
            } 
            if(sum > maxValue) {
                maxValue = sum;
            }
            left[i] = maxValue;
        }

        int *right = new int[size];
        sum = maxValue = right[size-1] = nums[size-1];
        for(i=size-2; i>=0; i--) {
            if(sum < 0) {
                sum = nums[i];
            }
            else {
                sum += nums[i];
            } 
            if(sum > maxValue) {
                maxValue = sum;
            }
            right[i] = maxValue;
        }

        int result = 0x80000000;
        for(i=0; i<size-1; i++) {
            result = (result > left[i]+right[i+1])?result:(left[i]+right[i+1]);
        }

        delete[] left;
        delete[] right;
        return result;
    }

    void displayVector(vector<int> &order) {
        vector<int>::iterator i;
        for(i=order.begin(); i!=order.end(); i++) {
            cout<<(*i)<<",";
        }
        cout<<endl;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(2);

    s.displayVector(nums);
    cout<<s.maxTwoSubArrays(nums)<<endl;

    return 0;
}