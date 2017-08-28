#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * http://www.lintcode.com/zh-cn/problem/plus-one/-407-加一 
     * @param digits: a number represented as an array of digits
     * @return: the result
     */
    vector<int> plusOne(vector<int> digits) {
        // write your code here
        int size = digits.size();
        if (size <= 0) {
            return vector<int>();
        }
        int carry = 0;
        digits[size - 1]++;
        if (digits[size - 1] < 10) {
            return digits;
        }
        carry = 1;
        digits[size - 1] = 0;
        for (int i = size - 2; i >= 0; i--) {
            digits[i] = digits[i] + carry;
            if (digits[i] > 9) {
                carry = 1;
                digits[i] = 0;
            }
            else {
                carry = 0;
                break;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
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

    int A[] = { 8,9,9,9 };
    vector<int> nums(&A[0], &A[sizeof(A) / sizeof(int)]);

    s.display(nums);
    s.display(s.plusOne(nums));
    

    return 0;
}