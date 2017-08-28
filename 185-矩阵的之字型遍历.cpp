#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/matrix-zigzag-traversal/-185-矩阵的之字型遍历
    *  @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        int sizeRow = matrix.size();
        if (sizeRow <= 0) {
            return vector<int>();
        }
        int sizeCol = matrix[0].size();
        if (sizeCol <= 0) {
            return vector<int>();
        }

        vector<int> result;
        int count = sizeRow * sizeCol, curRow = 0, curCol = 0;
        result.push_back(matrix[0][0]);
        for (int i = 1; i < count; ) {
            //斜上走到顶
            while (i < count && curRow - 1 >= 0 && curCol + 1 < sizeCol) {
                result.push_back(matrix[--curRow][++curCol]);
                i++;
            }
            //横右走一步，不可横右走时竖下走一步
            if (i < count && curCol + 1 < sizeCol) {
                result.push_back(matrix[curRow][++curCol]);
                i++;
            }
            else if (i < count && curRow + 1 < sizeRow) {
                result.push_back(matrix[++curRow][curCol]);
                i++;
            }
            //斜下走到底
            while (i < count && curRow + 1 < sizeRow && curCol - 1 >= 0) {
                result.push_back(matrix[++curRow][--curCol]);
                i++;
            }
            //竖下走一步，不可竖下走时横右走一步
            if (i < count && curRow + 1 < sizeRow) {
                result.push_back(matrix[++curRow][curCol]);
                i++;
            }
            else if (i < count && curCol + 1 < sizeCol) {
                result.push_back(matrix[curRow][++curCol]);
                i++;
            }
        }
        return result;
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
    nums.push_back(3);
    nums.push_back(4);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(12);
    matrix.push_back(nums);

    s.display(matrix);
    cout << endl;
    s.display(s.printZMatrix(matrix));

    return 0;
}