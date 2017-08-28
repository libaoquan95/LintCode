#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/backpack/-92-±≥∞¸Œ Ã‚
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */int backPack(int m, vector<int> A) {
        // write your code here
        int size = A.size(), i = 0, j = 0;

        if(size <= 0) {
            return 0;
        }
        
        int *dp = new int[m+1];
        for(i=0; i<m+1; i++) {
            dp[i] = 0;
        }

        for(i=0; i<size; i++) {
            for(j=m; j>=1; j--) {
                if(j >= A[i]) {
                    dp[j] = (dp[j]>dp[j-A[i]] + A[i])?dp[j]:dp[j-A[i]] + A[i];
                }
            }
        }
        return dp[m];
    }

    int backPack_MN(int m, vector<int> A) {
        // write your code here
        int size = A.size(), i = 0, j = 0;

        if(size <= 0) {
            return 0;
        }

        sort(A.begin(), A.end());
        vector< vector<int> > dp(size, vector<int>(m+1, 0) );

        for(i=0; i<size; i++) {
            for(j=1; j<=m; j++) {
                if(i==0 && j>=A[i]) {
                    dp[i][j] = A[i];
                }
                else if(i>0 && j>=A[i]){
                    dp[i][j] = (dp[i-1][j-A[i]] + A[i] > dp[i-1][j]) ? dp[i-1][j-A[i]] + A[i] : dp[i-1][j];
                }
                else if(i>0 && j<A[i]){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[size-1][m];
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
    nums.push_back(5);
    nums.push_back(7);
    
    cout<<s.backPack(11, nums)<<endl;
    
    return 0;
}