#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/n-queens-ii/-34-Nª ∫ÛŒ Ã‚ II
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        if(n == 1) {
            return 1;
        }
        else if(n < 4) {
            return 0;
        }

        int result = 0;
        int i=0, row=0, col=0, j=0, k=0;
        int *pCheckerboard = new int[n];
        for(i=0; i<n; i++) {
            pCheckerboard[i] = -1;
        }

        while(row < n) {
            while(col < n) {
                if(canPlace(row, col, n, pCheckerboard)) {
                    pCheckerboard[row] = col;
                    col = 0;
                    break;
                }
                else {
                    col++;
                }
            }

            if(pCheckerboard[row] == -1) {
                if(row == 0) {
                    break;
                }
                else {
                    row--;
                    col = pCheckerboard[row] + 1;
                    pCheckerboard[row] = -1;
                    continue;
                }
            }

            if(row == n-1) {
                result++;
                
                col = pCheckerboard[row] + 1;
                pCheckerboard[row] = -1;
                continue;
            }
            row++;
        }
        delete[] pCheckerboard;
        return result;
    }

    int canPlace(int row, int col, int n, int *pCheckerboard) {
        int i;
        for(i=0; i<n && i!=row; i++) {
            if(pCheckerboard[i] == col) {
                return 0;
            }
            if(abs(row-i) == abs(col-pCheckerboard[i])) {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    Solution s;
    int result = s.totalNQueens(4);

    cout<<result<<endl;
    return 0;
}