#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/combination-sum-ii/153-Êý×Ö×éºÏ II
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        int size = num.size();
        if (size <= 0) {
            return vector<vector<int> >();
        }

        sort(num.begin(), num.end());
        vector<vector<int> > result;
        vector<int> temp;
        isInsert(result, temp, num, 0, 0, target);

        return result;
    }

    void isInsert(vector<vector<int> > &result, vector<int> &temp, vector<int> &num, int current, int sum, int target) {
        if (sum == target && !isExisted(result, temp)) {
            result.push_back(temp);
            return;
        }
        if (current < num.size() && sum < target) {
            sum += num[current];
            temp.push_back(num[current]);
            isInsert(result, temp, num, current + 1, sum, target);
            sum -= temp[temp.size() - 1];
            temp.pop_back();
            isInsert(result, temp, num, current + 1, sum, target);
        }
    }

    bool isExisted(vector<vector<int> > &result, vector<int> &temp) {
        for (int i = 0; i < result.size(); i++) {
            if (temp.size() == result[i].size()) {
                int ret = true;
                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] == result[i][j]) {
                        ret = ret & true;
                    }
                    else {
                        ret = ret & false;
                    }
                }
                if (ret == true) {
                    return true;
                }
            }
        }
        return false;
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
    int A[] = {10,1,6,7,2,1,5};
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    vector<vector<int> > result = s.combinationSum2(nums, 8);
    s.display(result);

    return 0;
}