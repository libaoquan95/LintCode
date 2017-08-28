#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/number-of-islands/-433-岛屿的个数
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        int sizeRow = grid.size();
        if (sizeRow <= 0) {
            return 0;
        }
        int sizeCol = grid[0].size();
        if (sizeCol <= 0) {
            return 0;
        }
        int count = 0;
        vector<vector<bool>> isVisited(sizeRow, vector<bool>(sizeCol, false));
        for (int i = 0; i < sizeRow; i++) {
            for (int j = 0; j < sizeCol; j++) {
                if (grid[i][j] == true && !isVisited[i][j]) {
                    numIslands(i, j, grid, isVisited);
                    count++;
                }
            }
        }
        return count;
    }

    void numIslands(int i, int j, vector<vector<bool>> &grid, vector<vector<bool>> &isVisited) {
        if (i < 0 || i >= grid.size()) {
            return;
        }
        if (j < 0 || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == false || isVisited[i][j] == true) {
            return;
        }
        isVisited[i][j] = true;
        numIslands(i - 1, j, grid, isVisited);
        numIslands(i + 1, j, grid, isVisited);
        numIslands(i, j - 1, grid, isVisited);
        numIslands(i, j + 1, grid, isVisited);
    }

    void display(vector< vector<int> > &matrix) {
        vector< vector<int> >::iterator i;
        vector<int>::iterator j;

        for (i = matrix.begin(); i != matrix.end(); i++) {
            for (j = i->begin(); j != i->end(); j++) {
                cout << *j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;

    vector< vector<bool> > matrix;
    vector<bool> nums;

    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    matrix.push_back(nums);

    cout << s.numIslands(matrix) << endl;

    return 0;
}