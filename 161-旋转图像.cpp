#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/rotate-image/-161-Ðý×ªÍ¼Ïñ
     * @param matrix: a lists of integers
     * @return: 
     */
    void rotate(vector<vector<int>>& matrix) {
        // write your code here
        int size = matrix.size(), i = 0, j = 0;
        if (size <= 0) {
            return;
        }

        for (i = 0; i < size / 2; i++) {
            swap(matrix[i], matrix[size - 1 - i]);
        }
        for (i = 0; i < size; i++) {
            for (j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
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
    }
};

int main()
{
    Solution s;
    vector< vector<int> > matrix;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    matrix.push_back(nums);

    nums.clear();
    nums.push_back(3);
    nums.push_back(4);
    matrix.push_back(nums);

    s.display(matrix);
    s.rotate(matrix);
    cout << endl;
    s.display(matrix);

    return 0;
}