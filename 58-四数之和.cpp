#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>  
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/4sum/-58-四数之和
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int size = nums.size();
        if(size < 4) {
            return vector<vector<int> >();
        }
        vector<vector<int> > result;

        int i = 0, j = 0, k = 0, l = 0;
        sort(nums.begin(), nums.end());

        for(k=0; k<size; k++) {
            if(k>0 && nums[k]==nums[k-1]) {
                continue;
            }

            for(l=k+1; l<size; l++) {
                if(l>k+1 && nums[l]==nums[l-1]) {
                    continue;
                }

                for(i=l+1, j=size-1; i<j;) {
                    if(i>l+1 && nums[i]==nums[i-1]) {
                        i++;
                        continue;
                    }
                    if(j<size-1 && nums[j]==nums[j+1]) {
                        j--;
                        continue;
                    }

                    int sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if(target == sum) {
                        vector<int> temp;
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        result.push_back(temp);
                        i++;
                        j--;
                    }
                    else if(target < sum) {
                        j--;
                    }
                    else {
                        i++;
                    }
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
    
    //[1,0,-1,-1,-1,-1,0,1,1,1,2]
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    
    vector<vector<int> > result = s.fourSum(nums, 2);

    s.display(result);

    return 0;
}