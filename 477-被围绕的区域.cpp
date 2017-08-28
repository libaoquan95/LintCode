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
     * http://www.lintcode.com/zh-cn/problem/surrounded-regions/-477-被围绕的区域
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int sizeRow = board.size();
        if (sizeRow <= 0) {
            return ;
        }
        int sizeCol = board[0].size();
        if (sizeCol <= 0) {
            return ;
        }
        // 从外围开始
        int i = 0, j = 0;
        for (j = 0; j < sizeCol; j++) {
            // 上围
            if (board[0][j] == 'O') {
                DFS(board, 0, j);
            }
            // 下围
            if (board[sizeRow - 1][j] == 'O') {
                DFS(board, sizeRow - 1, j);
            }
        }
        for (i = 0; i < sizeRow; i++) {
            // 左围
            if (board[i][0] == 'O') {
                DFS(board, i, 0);
            }
            // 右围
            if (board[i][sizeCol - 1] == 'O') {
                DFS(board, i, sizeCol - 1);
            }
        }

        for (i = 0; i < sizeRow; i++) {
            for (j = 0; j < sizeCol; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void DFS(vector<vector<char>>& board, int i, int j) {
        if (i < board.size() && j < board[0].size()) {
            board[i][j] = '#';
            if (i > 0 && board[i - 1][j] == 'O') {
                DFS(board, i - 1, j);
            }
            if (j > 0 && board[i][j - 1] == 'O') {
                DFS(board, i, j - 1);
            }
            if (i < board.size() - 1 && board[i + 1][j] == 'O') {
                DFS(board, i + 1, j);
            }
            if (j < board[0].size() - 1 && board[i][j + 1] == 'O') {
                DFS(board, i, j + 1);
            }
        }
    }

    void display(vector< vector<char> > &matrix) {
        vector< vector<char> >::iterator i;
        vector<char>::iterator j;

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

    vector< vector<char> > matrix;
    vector<char> nums;

    nums.push_back('X');
    nums.push_back('X');
    nums.push_back('X');
    nums.push_back('X');
    matrix.push_back(nums);

    nums.clear();
    nums.push_back('X');
    nums.push_back('O');
    nums.push_back('O');
    nums.push_back('X');
    matrix.push_back(nums);

    nums.clear();
    nums.push_back('X');
    nums.push_back('X');
    nums.push_back('O');
    nums.push_back('X');
    matrix.push_back(nums);

    nums.clear();
    nums.push_back('X');
    nums.push_back('O');
    nums.push_back('X');
    nums.push_back('X');
    matrix.push_back(nums);

    s.display(matrix);
    cout << endl;
    s.surroundedRegions(matrix);
    s.display(matrix);

    return 0;
}