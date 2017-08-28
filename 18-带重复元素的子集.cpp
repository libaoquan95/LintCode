#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/subsets-ii/-18-带重复元素的子集
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<vector<int> > result;
        vector<int> nums(S);
        int size = nums.size();
        
        if(size == 0) {
            result.push_back(vector<int> ()); 
            return result; 
        }

        sort(nums.begin(),nums.end());

        vector<int> temp;
        subset(result, nums, temp, 0, size);

        return result;
    }

    void subset(vector<vector<int> > &result, vector<int> nums, vector<int> temp, int begin, int end) {
        result.push_back(temp);

        for(int i=begin; i<end; i++) {
            if (i!=begin && nums[i] == nums[i-1]) 
                continue;
            temp.push_back(nums[i]);
            subset(result, nums, temp, i+1, end);
            temp.pop_back();
        }
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
    
    matrix = s.subsetsWithDup(order);

    for(it2=matrix.begin(); it2!=matrix.end();it2++)
    {
        for(it=it2->begin(); it!=it2->end();it++)
            cout<<*it<<"\t";
        cout<<endl<<endl;
    }


    return 0;
}