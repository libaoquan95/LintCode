#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
    * http://www.lintcode.com/zh-cn/problem/permutation-index-ii/-198-排列序号II
    * @param A an integer array
    * @return a long integer
    */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }

        long long result = 1, fac = 1, base = 1, dup = 1;
        map<int, int> hashRepeat;
        for (int i = size - 1; i >= 0; i--) {
            hashRepeat[A[i]]++;
            if (hashRepeat[A[i]] > 1) {
                dup *= hashRepeat[A[i]];
            }
            int count = 0;
            for (int j = i + 1; j < size; j++) {
                if (A[j] < A[i]) {
                    count++;
                }
            }
            result += count * fac / dup;
            fac *= (size - i);
        }
        return result;
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

    int A[] = { 1, 4, 2, 2 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << s.permutationIndexII(nums) << endl;

    return 0;
}
