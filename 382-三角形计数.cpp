#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/triangle-count/-382-三角形计数 
     * @param : A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> S) {
        // write your code here
        int size = S.size();
        if (size <= 0) {
            return 0;
        }

        int result = 0;
        sort(S.begin(), S.end());
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                int third = S[j] - S[i];
                int low = i + 1, high = j;
                while (low < high) {
                    int mid = low + (high - low) / 2;
                    if (S[mid] > third) {
                        high = mid;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                result += (j - low);
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
};

int main()
{
    Solution s;
    int A[] = { 3,4,6,7 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    cout << s.triangleCount(nums) << endl;

    return 0;
}