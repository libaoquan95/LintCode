#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/3sum/-57-三数之和
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if(size < 3) {
            return vector<vector<int> >();
        }
        vector<vector<int> > result;

        int i = 0, j = 0, k = 0;
        sort(nums.begin(), nums.end());
        for(k=0; k<size; k++) {
            if(nums[k] > 0) {
                break;
            }
            if(k>0 && nums[k]==nums[k-1]) {
                continue;
            }

            int target = 0 - nums[k];
            i = k + 1;
            j = size - 1;

            while(i < j) {
                if(nums[i]+nums[j] == target) {
                    vector<int> temp;
                    temp.push_back(nums[k]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    result.push_back(temp);

                    while(i<j && nums[i]==nums[i+1]) {
                        i++;
                    }
                    while(i<j && nums[j]==nums[j-1]) {
                        j--;
                    }
                    i++; 
                    j--;
                } 
                else if(nums[i]+nums[j] < target) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return result;
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
    
    vector<vector<int> > result = s.threeSum(nums);

    s.display(result);
    
    return 0;
}