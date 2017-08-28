#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix/-28-ËÑË÷¶þÎ¬¾ØÕó
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int rowSize = matrix.size();
        if(rowSize < 1)
            return false;
        int colSize = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[rowSize-1][colSize-1])
            return false;

        int rowIndex = 0, colIndex = 0;

        int rowHigh = rowSize-1, rowLow = 0, rowMid = (rowHigh + rowLow) / 2;
        while(rowLow <= rowHigh) {
            if(matrix[rowMid][0] == target || matrix[rowMid][colSize-1] == target) {
                return true;
            }
            else if(matrix[rowMid][0] < target && matrix[rowMid][colSize-1] > target) {
                rowIndex = rowMid;
                break;
            }
            else if(matrix[rowMid][0] > target) {
                rowHigh = rowMid - 1;
                rowMid = (rowHigh + rowLow) / 2;
            }
            else if(matrix[rowMid][colSize-1] < target){
                rowLow = rowMid + 1;
                rowMid = (rowHigh + rowLow) / 2;
            }
        }

        int colHigh = colSize-1, colLow = 0, colMid = (colHigh + colLow) / 2;
        while(colLow <= colHigh) {
            if(matrix[rowIndex][colMid] == target) {
                return true;
            }
            else if(matrix[rowIndex][colMid] < target) {
                colLow = colMid + 1;
                colMid = (colHigh + colLow) / 2;
            }
            else {
                colHigh = colMid - 1;
                colMid = (colHigh + colLow) / 2;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    vector< vector<int> > matrix;
    vector<int> i;
    i.push_back(1);i.push_back(3);i.push_back(5);i.push_back(7);
    matrix.push_back(i);
    i.clear();
    i.push_back(10);i.push_back(11);i.push_back(16);i.push_back(20);
    matrix.push_back(i);
    i.clear();
    i.push_back(23);i.push_back(30);i.push_back(34);i.push_back(50);
    matrix.push_back(i);
    i.clear();
    i.push_back(53);i.push_back(60);i.push_back(64);i.push_back(80);
    matrix.push_back(i);

    cout<<s.searchMatrix(matrix, 0)<<endl; // 0
    cout<<s.searchMatrix(matrix, 3)<<endl; // 1
    cout<<s.searchMatrix(matrix, 4)<<endl; // 0
    cout<<s.searchMatrix(matrix, 7)<<endl; // 1
    cout<<endl;

    cout<<s.searchMatrix(matrix, 10)<<endl; // 1
    cout<<s.searchMatrix(matrix, 16)<<endl; // 1
    cout<<s.searchMatrix(matrix, 18)<<endl; // 0
    cout<<endl;
 
    cout<<s.searchMatrix(matrix, 32)<<endl; // 0
    cout<<s.searchMatrix(matrix, 34)<<endl; // 1
    cout<<endl;
 
    cout<<s.searchMatrix(matrix, 62)<<endl; // 0
    cout<<s.searchMatrix(matrix, 64)<<endl; // 1
    cout<<s.searchMatrix(matrix, 160)<<endl; // 0

    /*cout<<s.searchMatrix(matrix, 33)<<endl;*/

    return 0;
}