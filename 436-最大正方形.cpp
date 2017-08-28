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
     * http://www.lintcode.com/zh-cn/problem/maximal-square/-436-最大正方形
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // Write your code here
        int sizeRow = matrix.size();
        if (sizeRow <= 0) {
            return 0;
        }
        int sizeCol = matrix[0].size();
        if (sizeCol <= 0) {
            return 0;
        }
        int maxCount = matrix[0][0];
        for (int i = 1; i < sizeRow; i++) {
            for (int j = 1; j < sizeCol; j++) {
                if (matrix[i][j] > 0 && matrix[i - 1][j] > 0 && matrix[i][j - 1] > 0 && matrix[i - 1][j - 1] > 0) {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;
                    maxCount = max(maxCount, matrix[i][j]);
                }
            }
        }
        return maxCount * maxCount;
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
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    matrix.push_back(nums);

    cout << s.maxSquare(matrix) << endl;

    return 0;
}