#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/maximum-product-subarray/-191-乘积最大子序列
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        int maxPro = nums[0], minPro = nums[0], result = nums[0];
        for (int i = 1; i < size; i++) {
            int maxTemp = maxPro, minTemp = minPro;
            maxPro = max(nums[i], max(nums[i] * maxTemp, nums[i] * minTemp));
            minPro = min(nums[i], min(nums[i] * maxTemp, nums[i] * minTemp));
            result = max(result, maxPro);
        }
        return result;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << (*i) << " ";
        }
        cout << endl;
    }

};

int main()
{
    Solution s;

    int A[] = { 8,2,3,-2,4 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << s.maxProduct(nums) << endl;

    return 0;
}