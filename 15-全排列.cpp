#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/permutations/-15-È«ÅÅÁĞ
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
        if(begin == end)
            result.push_back(nums);
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
};

int main()
{
    Solution s;

    vector<int> order;
    order.push_back(1);
    order.push_back(2);
    order.push_back(3);
    order.push_back(4);
    order.push_back(5);


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