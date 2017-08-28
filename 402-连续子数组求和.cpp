#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/continuous-subarray-sum/-402-连续子数组求和 
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if (size <= 0) {
            return vector<int>();
        }

        vector<int> result(2, -1);
        int sum = 0, min = 0, max = INT_MIN, minIndex = -1;
        for (int i = 0; i < size; i++) {
            sum += A[i];
            if (sum - min > max) {
                max = sum - min;
                result[0] = minIndex;
                result[1] = i;
            }
            if (sum < min) {
                min = sum;
                minIndex = i;
            }
        }
        result[0] = result[0] + 1;
        return result;
    }

    void display(vector<int> &nums) {
        vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++) {
            cout << *i << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;

    int A[] = { -3, 1, 3, -3, 4 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.display(s.continuousSubarraySum(nums));
    

    return 0;
}