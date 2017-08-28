#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/set-matrix-zeroes/-162-�������
     * @param matrix: An integer
     * @return: 
     */
    void setZeroes(vector<vector<int> >& matrix) {
        // write your code here
        int sizeRow = matrix.size();
        if (sizeRow <= 0) {
            return;
        }
        int sizeCol = matrix[0].size(), i = 0, j = 0;
        bool firRow = false, firCol = false;
        // 检测第 1 行是否含0
        for (i = 0; i < sizeCol; i++) {
            if (matrix[0][i] == 0) {
                firRow = true;
                break;
            }
        }
        // 检测第 1 列是否含0
        for (i = 0; i < sizeRow; i++) {
            if (matrix[i][0] == 0) {
                firCol = true;
                break;
            }
        }
        // 若点 (i , j) 为0，则可以把 (i , 0)  ,(0 , j) 标记为 0
        for (i = 1; i < sizeRow; i++) {
            for (j = 1; j < sizeCol; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 根据 (i , 0)  ,(0 , j) 的值，单独设置某行或某列为 0
        for (i = 1; i < sizeCol; i++) {
            if (matrix[0][i] == 0) {
                for (j = 1; j < sizeRow; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        for (i = 1; i < sizeRow; i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < sizeCol; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 第 1 行包含 0，置第 1 行全为 0 
        if (firRow == true) {
            for (j = 0; j < sizeCol; j++) {
                matrix[0][j] = 0;
            }
        }
        // 第 1 列包含 0，置第 1 列全为 0 
        if (firCol == true) {
            for (j = 0; j < sizeRow; j++) {
                matrix[j][0] = 0;
            }
        }
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
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
    vector< vector<int> > matrix;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(0);
    matrix.push_back(nums);

    /*nums.clear();
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(3);
    matrix.push_back(nums);*/

    s.display(matrix);
    s.setZeroes(matrix);
    cout << endl;
    s.display(matrix);

    return 0;
}