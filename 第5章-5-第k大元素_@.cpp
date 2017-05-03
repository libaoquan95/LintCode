#include <iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/ladder/6/-第5章-5-第k大元素
     * @param k : description of k
     * @param nums : description of array and index 0 ~ n-1
     * @return: description of return
     */
    multiset<int> kthLargestElement(int k, vector<int> nums) {
        // write your code here
        multiset<int> set;

        for(int i=0; i<nums.size(); i++)
        {
            if(set.size() < k)
            {
                set.insert(nums[i]);
            }
            else
            {
                if(nums[i] >= *set.begin()) 
                {
                    set.erase(*set.begin());
                    set.insert(nums[i]);
                }
            }
        }
        //return *set.begin();
        return set;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(6);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);

    // 0  1  1 1 1 1 1 3 4 5 6 6
    //12 11 10 9 8 7 6 5 4 3 2 1

    /*
    for(int i=1; i<=nums.size(); i++)
        cout<<s.kthLargestElement(i, nums)<<endl;

    */
    
    /**/for(int i=1; i<=nums.size(); i++)
    {
        multiset<int> set;
        multiset<int>::iterator it;

        set = s.kthLargestElement(i, nums);
        for(it=set.begin(); it!=set.end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}