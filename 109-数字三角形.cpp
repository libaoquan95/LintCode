#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/triangle/-109-Êý×ÖÈý½ÇÐÎ
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int size = triangle.size(), i = 0, j = 0;
        if(size <=0) {
            return 0;
        }
        
        vector<vector<int> > dp = triangle;
        for(i=size-2; i>=0; i--) {
            for(j=0; j<dp[i].size(); j++) {
                dp[i][j] += (dp[i+1][j] > dp[i+1][j+1]) ? dp[i+1][j+1] : dp[i+1][j];
            }
        }

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

    vector<vector<int> > triangle;
    triangle.push_back(vector<int>(1, 0));
    triangle.push_back(vector<int>(2, 0));
    triangle.push_back(vector<int>(3, 0));
    triangle.push_back(vector<int>(4, 0));
    triangle[0][0] = 2;
    triangle[1][0] = 3; triangle[1][1] = 4;
    triangle[2][0] = 6; triangle[2][1] = 5; triangle[2][2] = 7;
    triangle[3][0] = 3; triangle[3][1] = 1; triangle[3][2] = 8; triangle[3][2] = 3;

    s.display(triangle);

    cout<<s.minimumTotal(triangle)<<endl;

    s.display(triangle);
    
    return 0;
}