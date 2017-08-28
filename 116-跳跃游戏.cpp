#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/jump-game/-116-Ã¯‘æ”Œœ∑ 
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        int size = A.size();
        if (size == 1) {
            return true;
        }
        int currMaxStep = A[0];
        int step = 0;
        for (int i=1; i<size; i++) {
            if(i > currMaxStep) {
                return false;
            }
            currMaxStep = (i+A[i] > currMaxStep) ? i+A[i] : currMaxStep;
            if(currMaxStep >= size-1) {
                return true;
            }
        }
        return currMaxStep >= size-1;
    }
    bool canJump_dp(vector<int> A) {
        // write you code here
        int size = A.size();
        if (size == 1) {
            return true;
        }

        vector<int> dp(size, 0);
        dp[0] = A[0];
        for(int i=1; i<size; i++) {
            if (dp[i-1] >= i) {
                dp[i] = (A[i]+i > dp[i-1]) ? A[i]+i : dp[i-1];
            }
            else {
                dp[i] = 0;
            }
        }
        return dp[size-1] >= size-1;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for(i=nums.begin(); i!=nums.end(); i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
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
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);

    s.display(nums);
    cout<<s.canJump(nums)<<endl;
    
    return 0;
}