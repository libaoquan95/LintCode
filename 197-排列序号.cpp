#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int size = A.size();
        if (size <= 0) {
            return 0;
        }

        long long result = 1, fac = 1, base = 1;
        for (int i = size - 1; i >= 0; i--) {
            int count = 0;
            for (int j = i + 1; j < size; j++) {
                if (A[j] < A[i]) {
                    count++;
                }
            }
            result += count * fac;
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

    int A[] = { 2,6,4,5,8,1,7,3 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    cout << s.permutationIndex(nums) << endl;

    return 0;
}
