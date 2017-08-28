#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/subarray-sum/-138-子数组之和
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        int size = nums.size(), sum = 0;
        if(size <= 0) {
            return vector<int>();
        }

        vector<int> result;
        map<int, int> subSum;
        subSum[0] = -1;

        for(int i=0; i<size; i++) {
            sum += nums[i];
            if(subSum.count(sum)) {
                result.push_back(subSum[sum]+1);
                result.push_back(i);
                return result;
            }
            subSum[sum] = i;
        }

        return result;
    }

    vector<int> subarraySum_N2(vector<int> nums){
        // write your code here
        int size = nums.size(), sum = 0;
        if(size <= 0) {
            return vector<int>();
        }

        vector<int> result;

        for(int i=0; i<size; i++) {
            sum = nums[i];
            if(sum == 0){
                result.push_back(i);
                result.push_back(i);
                return result;
            }
            for(int j=i+1; j<size; j++) {
                sum += nums[j];
                if(sum == 0) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(0);
    //nums.push_back(1);
    //nums.push_back(2);
    //nums.push_back(-3);
    //nums.push_back(4);

    s.display(nums);

    s.display(s.subarraySum(nums));

    return 0;
}