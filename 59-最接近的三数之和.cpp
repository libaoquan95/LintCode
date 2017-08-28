#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/3sum-closest/-59-最接近的三数之和
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int size = nums.size();
        if(size < 3) {
            return 0;
        }

        sort(nums.begin(),nums.end());
        int ans = 0x7FFFFFFF, i = 0, j = 0, k = 0;

        for(i=0; i<size; i++) {
            for(j=i+1, k=size-1; j<k;){
                int sum = nums[i] + nums[j] + nums[k];

                ans = abs(target-sum) < abs(target-ans) ? sum : ans;

                if(sum > target) {
                    k--;
                }
                else if(sum < target) {
                    ++j;
                }
                else {
                    return sum;
                }
            }
        }
        return ans;
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for(i=matrix.begin(); i!=matrix.end(); i++)
        {
            for(j=i->begin(); j!=i->end(); j++)
            {
                cout<<*j<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    
    cout<<s.threeSumClosest(nums, 0)<<endl;
    
    return 0;
}