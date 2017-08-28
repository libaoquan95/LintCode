#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/kth-smallest-number-in-sorted-matrix/-401-排序矩阵中的从小到大第k个数 
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        // write your code here
        int sizeRow = matrix.size();
        if (sizeRow <= 0) {
            return 0;
        }
        int sizeCol = matrix[0].size();
        if (sizeCol <= 0) {
            return 0;
        }
        
        int min = 0;

        for (int i = 0; i < k; i++) {
            min = matrix[0][0];
            matrix[0][0] = INT_MAX;
            adjustMatrix(matrix);
            display(matrix);
        }
        return min;
    }

    void adjustMatrix(vector<vector<int> > &matrix) {
        int row = 0, col = 0;
        while (row < matrix.size() - 1 && col < matrix[0].size() - 1) {
            if (matrix[row][col + 1] <= matrix[row + 1][col]) {
                swap(matrix[row][col + 1], matrix[row][col]);
                col++;
            }
            else if (matrix[row][col + 1] >= matrix[row + 1][col]) {
                swap(matrix[row + 1][col], matrix[row][col]);
                row++;
            }
        }
        while (row == matrix.size() - 1 && col < matrix[0].size() - 1) {
            if (matrix[row][col] >= matrix[row][col + 1]) {
                swap(matrix[row][col + 1], matrix[row][col]);
                col++;
            }
        }
        while (col == matrix[0].size() - 1 && row < matrix.size() - 1) {
            if (matrix[row][col] >= matrix[row + 1][col]) {
                swap(matrix[row + 1][col], matrix[row][col]);
                row++;
            }
        }
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
        cout << endl;
    }
};

int main()
{
    Solution s;

    vector< vector<int> > matrix;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(7);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(8);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(9);
    matrix.push_back(nums);

    s.display(matrix);
    cout << s.kthSmallest(matrix, 4) << endl;

    return 0;
}