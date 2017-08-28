#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/minimum-adjustment-cost/-91-最小调整代价
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int size = A.size(), i = 0, j = 0, k = 0;
        if(size <= 0) {
            return 0;
        }

        vector<vector<int> > dp(size+1, vector<int> (101, 0x7FFFFFFF));
        dp[0] = vector<int>(101, 0);

        for(i=1; i<=size; i++) {  
            for(j=0; j<=100; j++) {  
                for(k=0; k<=100; k++) {
                    if (abs(j - k) <= target) {
                        dp[i][j] = (dp[i-1][k]+abs(A[i-1]-j)) > dp[i][j] ? dp[i][j] : (dp[i-1][k]+abs(A[i-1]-j));
                    }
                }  
            }  
        }
        
        int minCost = 0x7FFFFFFF;  
        for(i=0; i<=100; i++) {  
            minCost = minCost > dp[size][i] ? dp[size][i] : minCost;  
        }  
        return minCost;
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
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(3);
    
    cout<<s.MinAdjustmentCost(nums, 1)<<endl;
    
    return 0;
}