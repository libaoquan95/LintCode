#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/minimum-subarray/-44-最小子数组
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int size=nums.size(), i=0, dec=0, minValue=0x7FFFFFFF;

        dec = nums[0];
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
        }
        return minValue;
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
    nums.push_back(-5);
    nums.push_back(10);
    nums.push_back(-4);

    s.displayVector(nums);
    cout<<s.minSubArray(nums)<<endl;

    return 0;
}