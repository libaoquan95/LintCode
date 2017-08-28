#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/sort-letters-by-case/-51-上一个排列 
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int size = nums.size(), i = 0, j = 0, k = 0;
        if(size == 0) {
            return vector<int> ();
        }

        for(i=size-1; i>=1; i--) {
            if(nums[i-1] > nums[i]) {
                int flag = i + 1;
                while(flag < size) {
                    if(nums[i-1] > nums[flag] && nums[i] < nums[flag]) {
                        int temp = nums[i];
                        nums[i] = nums[flag];
                        nums[flag] = temp;
                    }
                    flag++;
                }

                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                
                for(j=i; j<size; j++){  
                    for(k=j+1; k<size; k++) {  
                        if(nums[k] >nums[j]) {  
                            int temp = nums[j];
                            nums[j] = nums[k];
                            nums[k] = temp;
                        }  
                    }  
                }
                break;
            }
        }
        if(i == 0){  
            for(i=0; i<size/2; i++) {   
                int temp = nums[i];
                nums[i] = nums[size-1-i];
                nums[size-1-i] = temp;
            }
        }
        return nums;
    }
};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);

    vector<int> order;
    order = s.previousPermuation(nums);
    
    vector<int>::iterator i;
    for(i=order.begin(); i!=order.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    return 0;
}