#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第6章-56-两数之和
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        if(nums.empty())  
        {  
            return vector<int>();  
        }//if  
          
        int len = nums.size();  
        vector<int> ret;  
        for(int i=0; i<len; ++i)  
        {  
            for(int j=i+1; j<len; ++j)  
            {  
                if(nums[i] + nums[j] == target)  
                {  
                    ret.push_back(i+1);  
                    ret.push_back(j+1);  
                    return ret;  
                }//if  
            }//for  
        }//for  
          
        return vector<int>();
    }

    vector<int> twoSum_2(vector<int> &nums, int target) {
        // write your code here
        int size = nums.size();
        int i=0, low=0, high=size-1;
        vector<int> result;

        if(size <= 0)
            return result;

        while(low < high)
        {
            if(nums[low]+nums[high] == target)
            {
                result.push_back(low);
                result.push_back(high);
                break;
            }
            else if(nums[low]+nums[high] > target)
            {
                high--;
            }
            else if(nums[low]+nums[high] < target)
            {
                low++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    
    vector<int> result = s.twoSum(nums, 15);
    vector<int>::iterator i;
    
    for(i=result.begin(); i!=result.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    
    return 0;
}