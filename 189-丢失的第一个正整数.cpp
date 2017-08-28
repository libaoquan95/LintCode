#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/first-missing-positive/-189-丢失的第一个正整数
     *  @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }
        for (int i = 0; i < size; ) {
            if (A[i] == i + 1) {
                i++;
            }
            if (A[i] >= 1 && A[i] <= size && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
            else {
                i++;
            }
        }
        for (int i = 0; i < size; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << (*i) << " ";
        }
        cout << endl;
    }

};

int main()
{
    Solution s;

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(1);

    s.display(nums);
    cout << s.firstMissingPositive(nums) << endl;

    return 0;
}