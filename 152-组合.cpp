#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/combinations/152-���
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        if (n <= 0 || k <= 0) {
            return vector<vector<int> >();
        }

        vector<vector<int> > result;
        vector<int> temp;
        isInsert(result, temp, 1, n, k);
        return result;
    }

    void isInsert(vector<vector<int> > &result, vector<int> &temp, int current, int n, int k) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        if (current <= n) {
            temp.push_back(current);
            isInsert(result, temp, current + 1, n, k);
            temp.pop_back();
            isInsert(result, temp, current + 1, n, k);
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
    vector<vector<int> > result = s.combine(4, 2);
    s.display(result);

    return 0;
}