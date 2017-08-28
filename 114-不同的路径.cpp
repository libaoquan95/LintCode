#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/unique-paths/-114-不同的路径 
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if(m <= 0 || n <= 0) {
            return 0;
        }
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else if(i == 0 && j > 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if(i > 0 && j == 0) {
                    dp[i][j] = dp[i-1][j];
                }
                else if(i > 0 && j > 0) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        display(dp);
        cout<<endl;
        return dp[m-1][n-1];
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
    
    cout<<s.uniquePaths(3, 3)<<endl;
    //cout<<s.uniquePaths(4, 5)<<endl;
    
    return 0;
}