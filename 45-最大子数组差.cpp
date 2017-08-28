#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/minimum-subarray/-45-最大子数组差
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int size = nums.size(), i = 0;
        int sum = 0, maxValue = 0;
        int dec = 0, minValue = 0;
        
        int *maxLeft = new int[size];   
        int *minLeft = new int[size];
        int *maxRight = new int[size];
        int *minRight = new int[size];

        sum = maxValue = maxLeft[0] = nums[0];
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
            maxLeft[i] = maxValue;
        }
        sum = maxValue = maxRight[size-1] = nums[size-1];
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
            maxRight[i] = maxValue;
        }

        dec = minValue = minLeft[0] = nums[0];
        for(i=1; i<size; i++) {
            if(dec > 0) {
                dec = nums[i];
            }
            else {
                dec += nums[i];
            }
            if(dec < minValue) {
                minValue = dec;
            }
            minLeft[i] = minValue;
        }
        dec = minValue = minRight[size-1] = nums[size-1];
        for(i=size-2; i>=0; i--) {
            if(dec > 0) {
                dec = nums[i];
            }
            else {
                dec += nums[i];
            }
            if(dec < minValue) {
                minValue = dec;
            }
            minRight[i] = minValue;
        }
        
        int result1 = 0x80000000;
        int result2 = 0x80000000;
        for(i=0; i<size-1; i++) {
            result1 = (result1 > maxLeft[i]-minRight[i+1])?result1:( maxLeft[i]-minRight[i+1]);
            result2 = (result2 > maxRight[i+1]-minLeft[i])?result2:( maxRight[i+1]-minLeft[i]);
        }

        
        delete[] maxLeft;
        delete[] minLeft;
        delete[] maxRight;
        delete[] minRight;

        return (result1 > result2)?result1:result2;
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
    nums.push_back(2);
    nums.push_back(-3);
    nums.push_back(1);

    s.displayVector(nums);
    cout<<s.maxDiffSubArrays(nums)<<endl;

    return 0;
}