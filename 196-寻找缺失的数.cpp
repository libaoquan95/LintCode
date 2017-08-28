#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/find-the-missing-number/-196-寻找缺失的数
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size <= 0) {
            return 0;
        }
        long sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++) {
            sum1 += nums[i];
            sum2 += i;
        }
        sum2 += size;
        return sum2 - sum1;
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

    int A[] = { 1,2,3 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << s.findMissing(nums) << endl;

    return 0;
}