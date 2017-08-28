#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/minimum-path-sum/-110-最小路径和 
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        int sizeRow = grid.size(), sizeCol = grid[0].size(), i = 0, j = 0;
        if(sizeRow <= 0) {
            return 0;
        }

        vector<vector<int> > dp(sizeRow, vector<int>(sizeCol, 0x7FFFFFFF));

        for(i=sizeRow-1; i>=0; i--) {
            for(j=sizeCol-1; j>=0; j--) {
                if(i == sizeRow-1 && j == sizeCol-1) {
                    dp[i][j] = grid[i][j];
                }
                else if(i == sizeRow-1 && j < sizeCol-1) {
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                else if(i < sizeRow-1 && j == sizeCol-1) {
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else if(i < sizeRow-1 && j < sizeCol-1) {
                    dp[i][j] = grid[i][j] + ((dp[i+1][j] > dp[i][j+1]) ? dp[i][j+1] : dp[i+1][j]);
                }
            }
        }

        display(dp);
        cout<<endl;
        return dp[0][0];
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
    srand(time(NULL));
    int m = 5, n = 8;
    vector<vector<int> > grid(m, vector<int>(n, 0));
    /*for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            grid[i][j] = rand()%9;
        }
    }*/
    grid[0][0] = 0; grid[0][1] = 3; grid[0][2] = 8; grid[0][3] = 8;
    grid[0][4] = 3; grid[0][5] = 7; grid[0][6] = 3; grid[0][7] = 5;

    grid[1][0] = 3; grid[1][1] = 6; grid[1][2] = 7; grid[1][3] = 3;
    grid[1][4] = 4; grid[1][5] = 4; grid[1][6] = 2; grid[1][7] = 7;
    
    grid[2][0] = 7; grid[2][1] = 6; grid[2][2] = 6; grid[2][3] = 4;
    grid[2][4] = 4; grid[2][5] = 2; grid[2][6] = 1; grid[2][7] = 0; 

    grid[3][0] = 4; grid[3][1] = 7; grid[3][2] = 4; grid[3][3] = 8;
    grid[3][4] = 8; grid[3][5] = 4; grid[3][6] = 3; grid[3][7] = 1; 
    
    grid[4][0] = 7; grid[4][1] = 0; grid[4][2] = 6; grid[4][3] = 6;
    grid[4][4] = 3; grid[4][5] = 7; grid[4][6] = 3; grid[4][7] = 5; 

    s.display(grid);
    cout<<endl;
    cout<<s.minPathSum(grid)<<endl;
    
    return 0;
}