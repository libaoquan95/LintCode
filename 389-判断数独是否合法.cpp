#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/valid-sudoku/-389-判断数独是否合法
     * @param board: the board
     * @return: whether the Sudoku is valid
     */
    bool isValidSudoku(vector<vector<char>> board) {
        // write your code here
        int sizeRow = board.size();
        if (sizeRow != 9) {
            return false;
        }
        int sizeCol = board[0].size();
        if (sizeCol != 9) {
            return false;
        }
        map<char, int> map;
        for (int i = 0; i < sizeRow; i++) {
            map.clear();
            // 当前元素所在行
            for (int j = 0; j < sizeCol; j++) {
                if (board[i][j] <= '9' && board[i][j] >= '0') {
                    if (map[board[i][j]] > 0) {
                        return false;
                    }
                    else {
                        map[board[i][j]]++;
                    }
                }
            }
            map.clear();
            // 当前元素所在列
            for (int j = 0; j < sizeRow; j++) {
                if (board[j][i] <= '9' && board[j][i] >= '0') {
                    if (map[board[j][i]] > 0) {
                        return false;
                    }
                    else {
                        map[board[j][i]]++;
                    }
                }
            }
        }
        // 当前元素所在宫
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int row = i * 3, col = j * 3;
                map.clear();
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[row + k][col + l] <= '9' && board[row + k][col + l] >= '0') {
                            if (map[board[row + k][col + l]] > 0) {
                                return false;
                            }
                            else {
                                map[board[row + k][col + l]]++;
                            }
                        }
                    }
                }
            }
        }
        return true;
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
    vector< vector<char>> matrix;

    cout << s.isValidSudoku(matrix) << endl;

    return 0;
}