#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/unique-paths-ii/-115-不同的路径 II 
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if(obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0) {
            return 0;
        }

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
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
    
    int m = 3, n = 3;
    vector<vector<int> > obstacleGrid(m, vector<int>(n, 0));
    obstacleGrid[1][1] = 1; 
    s.display(obstacleGrid);

    cout<<s.uniquePathsWithObstacles(obstacleGrid)<<endl;
    
    return 0;
}