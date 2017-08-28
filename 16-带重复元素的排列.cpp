#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/permutations-ii/-16-带重复元素的排列
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > result;
        int size = nums.size();
        if(size == 0) {
            result.push_back(nums);  
            return result; 
        }

        permute(nums, 0, size, result);

        return result;
    }

    void permute(vector<int> &nums, int begin, int end, vector<vector<int> > &result) {
        if(begin == end) {
            if(!isExist(nums, result)) {
                result.push_back(nums);
            }
        }
        else {
            for(int i=begin; i<end; i++) {
                int temp = nums[i];
                nums[i] = nums[begin];
                nums[begin] = temp;

                permute(nums, begin+1, end, result);

                temp = nums[i];
                nums[i] = nums[begin];
                nums[begin] = temp;
            }
        }
    }

    bool isExist(vector<int> &nums, vector<vector<int> > &result) {
        int size = result.size();
        if(size == 0)
            return false;
        for(int i=0; i<size; i++) {
            if(isSameNums(nums, result[i])) {
                return true;
            }
        }
        return false;
    }

    bool isSameNums(vector<int> &nums1, vector<int> &nums2) {
        int size = nums1.size();
        for(int i=0; i<size; i++) {
            if(nums1[i] != nums2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    vector<int> order;
    order.push_back(1);
    order.push_back(2);
    order.push_back(2);


    vector< vector<int> > matrix;
    vector< vector<int> > ::iterator it2;
    vector<int>::iterator it;
    
    matrix = s.permute(order);

    for(it2=matrix.begin(); it2!=matrix.end();it2++)
    {
        for(it=it2->begin(); it!=it2->end();it++)
            cout<<*it<<"\t";
        cout<<endl<<endl;
    }


    return 0;
}